# Comandos do Flutter

Referência rápida do SDK do Flutter: projeto, execução, emuladores, build e publicação.

## Ambiente e diagnóstico

```bash
flutter --version
flutter doctor              # checa o que falta no ambiente
flutter doctor -v           # detalhado (paths do SDK, Android, Xcode, licenças)
flutter config --list       # mostra as flags do SDK
flutter upgrade             # atualiza o SDK no canal atual
flutter downgrade
flutter channel             # lista canais (stable, beta, master)
flutter channel stable      # troca de canal
flutter clean               # apaga build/ e .dart_tool/
```

Licenças do Android SDK (comum falhar no `doctor`):

```bash
flutter doctor --android-licenses
```

Habilitar plataformas de destino:

```bash
flutter config --enable-web
flutter config --enable-linux-desktop
flutter config --enable-android
```

## Criar projeto

```bash
flutter create meu_app
flutter create --org com.exemplo meu_app          # define o applicationId / bundle id
flutter create --platforms=android,ios,web meu_app
flutter create -t plugin meu_plugin               # plugin
flutter create -t package meu_package             # pacote Dart puro
flutter create --empty meu_app                    # sem o contador de exemplo
flutter create .                                  # regenera plataformas em projeto existente
```

## Dependências

```bash
flutter pub get          # instala as dependências do pubspec.yaml
flutter pub upgrade
flutter pub outdated
flutter pub add http
flutter pub add --dev build_runner
flutter pub remove http
flutter pub cache repair # reinstala o cache de pacotes
```

Geração de código (freezed, json_serializable, etc.):

```bash
dart run build_runner build --delete-conflicting-outputs
dart run build_runner watch --delete-conflicting-outputs
```

## Dispositivos e emuladores

### Listar

```bash
flutter devices          # dispositivos conectados/rodando
flutter emulators        # emuladores Android/iOS disponíveis
```

### Iniciar

```bash
flutter emulators --launch <emulator_id>
flutter emulators --create --name pixel_7        # cria um emulador Android
```

### Android (via SDK, sem passar pelo Flutter)

```bash
avdmanager list avd                      # lista AVDs
emulator -list-avds
emulator -avd Pixel_7_API_34             # inicia um AVD
emulator -avd Pixel_7_API_34 -no-snapshot-load
adb devices                              # dispositivos reconhecidos pelo adb
adb kill-server && adb start-server      # quando o device "some"
adb reverse tcp:8080 tcp:8080            # expõe uma porta do host no device
```

### iOS (somente macOS)

```bash
open -a Simulator
xcrun simctl list devices
xcrun simctl boot "iPhone 15"
```

## Rodar o app

```bash
flutter run                          # no único device disponível
flutter run -d <device_id>           # escolhe o device
flutter run -d chrome                # web
flutter run -d linux                 # desktop Linux
flutter run --release                # build otimizado
flutter run --profile                # para medir performance
flutter run --dart-define=API_URL=https://exemplo.com
flutter run --flavor prod -t lib/main_prod.dart
flutter run -v                       # log verboso
```

Teclas úteis durante o `flutter run`:

| Tecla | Ação |
|-------|------|
| `r`   | hot reload |
| `R`   | hot restart |
| `h`   | ajuda / lista de comandos |
| `p`   | mostra as guias de layout |
| `o`   | alterna Android/iOS na renderização |
| `q`   | encerra |

## Build

### Android

```bash
flutter build apk                       # APK release
flutter build apk --debug
flutter build apk --split-per-abi       # um APK por arquitetura (menor)
flutter build appbundle                 # AAB para a Play Store
flutter build apk --flavor prod -t lib/main_prod.dart
flutter build apk --obfuscate --split-debug-info=build/symbols
```

Saída: `build/app/outputs/flutter-apk/` e `build/app/outputs/bundle/`.

Instalar o build em um device conectado:

```bash
flutter install
adb install -r build/app/outputs/flutter-apk/app-release.apk
```

### iOS / macOS (somente macOS)

```bash
flutter build ios
flutter build ios --no-codesign
flutter build ipa                       # arquivo para a App Store
flutter build macos
```

### Web

```bash
flutter build web
flutter build web --release --base-href /meu_app/
flutter build web --wasm               # renderização via WebAssembly
```

Saída: `build/web/`.

### Desktop

```bash
flutter build linux
flutter build windows
flutter build macos
```

## Testes

```bash
flutter test                         # todos os testes de test/
flutter test test/widget_test.dart
flutter test --name "nome do teste"
flutter test --coverage              # gera coverage/lcov.info
flutter test --watch
flutter drive --target=test_driver/app.dart   # testes de integração (legado)
flutter test integration_test                 # integration_test moderno
```

## Análise, formatação e correções

```bash
flutter analyze
dart format .
dart format --output=none --set-exit-if-changed .   # checagem em CI
dart fix --dry-run
dart fix --apply
```

## Debug e performance

```bash
flutter run --profile
flutter screenshot                     # captura do device conectado
flutter logs                           # logs do device
flutter attach                         # conecta a um app já rodando
dart devtools                          # DevTools (inspector, timeline, memória)
flutter symbolize -i stack.txt -d build/symbols   # desofusca stack trace
```

## Fluxo típico

```bash
flutter create meu_app
cd meu_app
flutter pub get
flutter emulators --launch Pixel_7_API_34
flutter run
flutter analyze && flutter test
flutter build appbundle --release
```

## Problemas comuns

```bash
flutter clean && flutter pub get       # resolve a maioria dos builds quebrados
flutter doctor -v                      # diagnóstico do ambiente
flutter pub cache repair               # cache de pacotes corrompido
rm -rf ~/.gradle/caches                # cache do Gradle travado (Android)
cd android && ./gradlew clean          # limpeza do lado nativo Android
```
