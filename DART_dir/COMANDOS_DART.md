# Comandos de Compilação e Execução do Dart

Referência rápida dos comandos do SDK do Dart.

## Verificar instalação

```bash
dart --version
dart --help
```

## Criar projeto

```bash
dart create nome_do_projeto          # projeto console padrão
dart create -t console meu_app       # aplicação de console
dart create -t package minha_lib     # pacote/biblioteca
dart create -t server-shelf meu_srv  # servidor web (shelf)
```

Templates disponíveis: `dart create --help`

## Dependências

```bash
dart pub get         # baixa as dependências do pubspec.yaml
dart pub upgrade     # atualiza para as versões mais recentes permitidas
dart pub outdated    # lista dependências desatualizadas
dart pub add http    # adiciona um pacote
dart pub remove http # remove um pacote
```

## Executar sem compilar (JIT)

```bash
dart run                       # roda bin/<nome_do_pacote>.dart
dart run bin/main.dart         # roda um arquivo específico
dart main.dart                 # forma curta para um arquivo solto
dart run bin/main.dart arg1 arg2   # passando argumentos
```

Com asserts e observabilidade:

```bash
dart run --enable-asserts bin/main.dart
dart run --observe bin/main.dart     # abre o DevTools
```

## Compilar (AOT / nativo)

### Executável nativo (self-contained)

```bash
dart compile exe bin/main.dart                 # gera bin/main.exe
dart compile exe bin/main.dart -o build/app    # define o nome de saída
./build/app                                    # executa
```

O binário gerado não precisa do SDK instalado na máquina de destino,
mas só roda no mesmo SO/arquitetura em que foi compilado.

### Snapshot AOT (precisa do `dartaotruntime`)

```bash
dart compile aot-snapshot bin/main.dart -o app.aot
dartaotruntime app.aot
```

### Snapshot JIT / kernel (portátil entre plataformas)

```bash
dart compile jit-snapshot bin/main.dart -o app.jit
dart run app.jit

dart compile kernel bin/main.dart -o app.dill
dart run app.dill
```

## Compilar para JavaScript (web)

```bash
dart compile js web/main.dart -o build/main.js
dart compile js -O2 web/main.dart -o build/main.js   # otimizado
dart compile js -m web/main.dart -o build/main.js    # minificado
```

Níveis de otimização: `-O0` a `-O4` (padrão `-O1`).

## Compilar para WebAssembly

```bash
dart compile wasm web/main.dart -o build/main.wasm
```

## Testes

```bash
dart test                          # roda todos os testes de test/
dart test test/meu_teste.dart      # roda um arquivo
dart test -n "nome do teste"       # filtra por nome
dart test --coverage=coverage      # gera dados de cobertura
```

## Análise e formatação

```bash
dart analyze              # análise estática (lints e erros)
dart analyze --fatal-infos
dart fix --dry-run        # mostra correções automáticas possíveis
dart fix --apply          # aplica as correções
dart format .             # formata todo o projeto
dart format --output=none --set-exit-if-changed .   # checagem em CI
```

## Documentação

```bash
dart doc            # gera docs em doc/api
dart doc --output docs
```

## Utilitários

```bash
dart pub global activate <pacote>   # instala ferramenta global
dart pub publish --dry-run          # valida antes de publicar
dart devtools                       # abre o DevTools
dart info                           # informações do ambiente
```

## Fluxo típico

```bash
dart create meu_app
cd meu_app
dart pub get
dart run
dart analyze && dart test
dart compile exe bin/meu_app.dart -o build/meu_app
```
