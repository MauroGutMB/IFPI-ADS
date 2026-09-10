# Estrutura de Diretórios do Flutter

Como o projeto é organizado e como manter `lib/` modular conforme o app cresce.

## Diretórios do projeto

Depois de `flutter create meu_app`:

```
meu_app/
├── lib/                   # TODO o seu código Dart mora aqui
│   └── main.dart          # ponto de entrada (função main + runApp)
├── test/                  # testes unitários e de widget
├── integration_test/      # testes de integração (criado por você)
├── assets/                # imagens, fontes, JSON — precisa declarar no pubspec
├── android/               # projeto Gradle nativo (AndroidManifest, build.gradle)
├── ios/                   # projeto Xcode (Info.plist, Runner)
├── web/                   # index.html, manifest, favicon
├── linux/ macos/ windows/ # runners desktop nativos
├── build/                 # saída de build — gerado, vai no .gitignore
├── .dart_tool/            # cache do pub/analyzer — gerado, .gitignore
├── pubspec.yaml           # dependências, assets, fontes, versão
├── pubspec.lock           # versões travadas — commitar em apps
└── analysis_options.yaml  # regras de lint
```

### Pontos que costumam pegar

- **Só `lib/` é importável.** Código fora de `lib/` (exceto `test/` e `bin/`) não é
  acessível via `package:`.
- **`lib/src/`** é convenção de "privado do pacote". Em app faz pouca diferença;
  em *package* publicado, o que está em `lib/src/` não deveria ser importado
  diretamente por quem consome.
- **`android/`, `ios/` etc. são código real**, não descartável — permissões,
  ícones, assinatura e configuração de flavor vivem lá.
- **`build/` e `.dart_tool/` nunca vão pro git.** `pubspec.lock` vai (em app) e
  não vai (em package/biblioteca publicada).
- **Assets precisam ser declarados** no `pubspec.yaml`; criar a pasta não basta:

```yaml
flutter:
  assets:
    - assets/images/
  fonts:
    - family: Inter
      fonts:
        - asset: assets/fonts/Inter-Regular.ttf
```

## Modularizando `lib/`

Existem duas organizações principais. A diferença está no que você usa como
pasta de primeiro nível.

### 1. Layer-first (por camada)

```
lib/
├── main.dart
├── models/
├── views/
├── controllers/
└── services/
```

Funciona bem até ~5 telas. Depois vira problema: mexer em "login" obriga a abrir
4 pastas distantes, e nada impede um model de perfil ser usado no checkout.

### 2. Feature-first (por funcionalidade) — recomendado

Cada feature é uma fatia vertical fechada, com suas próprias camadas dentro:

```
lib/
├── main.dart
├── app.dart                    # MaterialApp, tema, rotas raiz
│
├── core/                       # o que é compartilhado por TODAS as features
│   ├── theme/
│   │   └── app_theme.dart
│   ├── routing/
│   │   └── app_router.dart
│   ├── network/
│   │   └── api_client.dart
│   ├── errors/
│   │   └── failures.dart
│   └── extensions/
│
├── shared/                     # widgets genéricos reutilizáveis
│   └── widgets/
│       ├── primary_button.dart
│       └── loading_indicator.dart
│
└── features/
    ├── auth/
    │   ├── data/
    │   │   ├── auth_repository.dart
    │   │   └── models/user_model.dart
    │   ├── domain/
    │   │   └── entities/user.dart
    │   └── presentation/
    │       ├── pages/login_page.dart
    │       ├── widgets/login_form.dart
    │       └── controllers/login_controller.dart
    │
    └── produtos/
        ├── data/
        ├── domain/
        └── presentation/
```

A regra que faz isso valer a pena: **feature não importa feature**. Se
`produtos` precisa de algo de `auth`, ou aquilo sobe para `core`/`shared`, ou a
dependência passa por uma abstração. Sem essa regra, feature-first vira
layer-first com pastas mais bonitas.

Fluxo de dependência dentro de uma feature:

```
presentation  →  domain  →  data
```

Widget não fala com HTTP direto; fala com o repositório.

### O papel de cada camada

| Camada         | Responsabilidade                                   | Exemplo                          |
|----------------|----------------------------------------------------|----------------------------------|
| `presentation` | UI e estado de tela                                | `LoginPage`, `LoginController`   |
| `domain`       | Entidades e regras de negócio, sem Flutter         | `User`, `ValidarSenha`           |
| `data`         | Acesso a API, banco, cache; converte JSON ↔ modelo | `AuthRepository`, `UserModel`    |

Em projeto pequeno é legítimo colapsar `domain` e `data` em uma pasta só —
o importante é a direção das dependências, não a contagem de pastas.

## Barrel files

Para não escrever 10 imports por arquivo, cada feature expõe um `.dart` público:

```dart
// lib/features/auth/auth.dart
export 'presentation/pages/login_page.dart';
export 'domain/entities/user.dart';
```

Uso:

```dart
import 'package:meu_app/features/auth/auth.dart';
```

Exporte no barrel apenas o que é API pública da feature. Se tudo é exportado, o
barrel deixa de comunicar qualquer coisa.

## Imports: sempre `package:`

```dart
// bom
import 'package:meu_app/core/network/api_client.dart';

// evitar
import '../../../core/network/api_client.dart';
```

Caminho relativo quebra ao mover arquivo e atrapalha o analyzer. Dentro de uma
mesma pasta, relativo curto (`import 'user_model.dart';`) é aceitável.

## Forçando os limites com lint

Dá para transformar "feature não importa feature" em erro de análise. No
`analysis_options.yaml`:

```yaml
include: package:flutter_lints/flutter.yaml

linter:
  rules:
    - always_use_package_imports
    - directives_ordering
    - prefer_const_constructors
```

Para bloquear imports cruzados de verdade, os pacotes `import_lint` ou
`dart_code_metrics` permitem declarar quais camadas podem importar quais.

## Quando ir além: pacotes locais

Quando o app fica grande (ou vira multi-app), features viram pacotes de verdade:

```
meu_app/
├── app/                  # o app Flutter
└── packages/
    ├── core_network/
    └── feature_auth/
```

```yaml
# app/pubspec.yaml
dependencies:
  feature_auth:
    path: ../packages/feature_auth
```

**Ganho:** o compilador passa a proibir o import cruzado, em vez de depender de
disciplina.
**Custo:** mais `pubspec.yaml` para manter — só compensa quando a equipe cresce
ou você reaproveita módulos entre apps.

## Onde ficam os testes

`test/` espelha a estrutura de `lib/`:

```
test/
├── core/
│   └── network/api_client_test.dart
└── features/
    └── auth/
        ├── domain/user_test.dart
        └── presentation/login_page_test.dart
```

O espelhamento não é exigência da ferramenta, mas é o que torna óbvio o que
está sem teste.

## Resumo prático

1. Comece com `core/`, `shared/` e `features/` desde o primeiro dia — é barato
   adotar no início e caro migrar depois.
2. Uma feature = uma fatia vertical; feature não importa feature.
3. Dependências apontam para dentro: `presentation → domain → data`.
4. Imports com `package:`; barrel file por feature.
5. Só promova a pacote local quando a disciplina manual começar a falhar.
