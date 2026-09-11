# Changelog

このプロジェクトに対するすべての重要な変更は、このファイルに文書化されます。

## [2.4.2] - 2026-09-11

### Changed

- iOS27 に対応しました。
- Split View 機能に対応しました。
- Multiple Windows 機能に対応しました。
- `ORIAWindow.resize`を公開しました。

> [!NOTE]
> `ORIAWindow.resize`の詳細は[README.md](./README.md)をご参照ください。

### Fixed

- 画面共有中に端末を手前に傾けると赤ペン描画が消える不具合を修正しました。
- `ORIASession.remoteInputEnabled`を`false`にしても、Windows オペレータツールで遠隔操作のボタンが有効化されたままになる不具合を修正しました。

## [2.4.1] - 2026-05-29

- 画面共有一時停止機能の使用中に再接続を実行すると、アイコンの状態に不整合が生じる不具合を修正しました。
- 現行の登録フローと記載内容が一致しなくなっていたため、登録フローに関するドキュメントを削除しました。

## [2.4.0] - 2026-02-24

### Changed

- 画面共有一時停止機能を追加しました。

> [!NOTE]
> 画面共有一時停止機能の詳細は[CUSTOMIZE.md](./docs/CUSTOMIZE.md)をご参照ください。

- iOS26 に対応しました。

## [2.3.0] - 2025-11-07

### Changed

- マスキング機能を追加しました。

> [!NOTE]
> マスキング機能の詳細は[CUSTOMIZE.md](./docs/CUSTOMIZE.md)をご参照ください。

## [2.2.0] - 2025-06-23

### Changed

- SDK が表示する UI のデザインカスタマイズ機能を追加しました。

> [!NOTE]
> デザインカスタマイズ機能の詳細は[CUSTOMIZE.md](./docs/CUSTOMIZE.md)をご参照ください。

## [2.1.2] - 2024-12-18

### Changed

- 音声通話機能を除いた SDK（[OptimalRemoteNoVoIP.xcframework.zip](./OptimalRemoteNoVoIP.xcframework.zip)）を追加しました。

> [!NOTE]
> OptimalRemoteNoVoIP.xcframework.zip は音声通話機能に関するモジュールを除いていますが、その他の機能に差分はありません。

- SDK が UI 上に表示している言語を切り替える API として`ORIASession.setLocale`を追加しました。

> [!NOTE]
> SDK の表示言語切り替えの詳細は[CUSTOMIZE.md](./docs/CUSTOMIZE.md)をご参照ください。

### Fixed

- `UIView`（およびその派生クラス）に`UIGestureRecognizerDelegate`を準拠させているアプリに組み込む際ビルドエラーとなる不具合を修正しました。

## [2.1.1] - 2024-10-04

### Changed

- iOS18 に対応しました。

### Fixed

- 機器情報のシステムモデルが不正な値となっていた不具合に対応しました。

## [2.1.0] - 2024-05-14

### Changed

- シミュレーターに対応しました。

> [!NOTE]
> 実機用・シミュレーター用の framework を xcframework にバンドルしています。
> 組み込む場合は xcframework ディレクトリをプロジェクトに追加してください。
> 詳細は[README.md](./README.md)を参照してください。

- Library Evolution に対応しました。

> [!NOTE]
> Swift 製のアプリに組み込む際に、本 SDK と Swift コンパイラバージョンを揃える必要がなくなりました。

## [2.0.0] - 2024-03-22

### Changed

- Privacy Manifest に対応しました。

> [!WARNING]
> この SDK は Privacy Manifest(PrivacyInfo.xcprivacy)を含んでいますが、SDK を組み込んだアプリに SDK の Privacy Manifest が含まれていないことを確認しています。
> そのため、組み込むアプリの Privacy Manifest に記載が必要になります。
> 詳細は[README.md](./README.md)を参照してください。

- OptimalRemote In-App Remote SDK for iOS の開発言語を Objective-C から Swift に移行しました。

> [!WARNING]
> 以下の破壊的変更が含まれます。
>
> - いくつかのシグネチャの名称の変更
>   - `ORIASessionDelegate.oriaSessionDidSetMicrohponeEnabled`
>     - `ORIASessionDelegate.oriaSessionDidSetMicrophoneEnabled`に変更
>   - `ORIAUIAssistiveButtonViewSetting.assistiveButtoView`
>     - `ORIAUIAssistiveButtonViewSetting.assistiveButtonView`に変更
>   - `ORIAUIViewDelegateDefault.isVoiceChatSpeakerActive`
>     - `ORIAUIViewDelegateDefault.isVoiceChatSpeakerActivate`に変更
> - ビルド手順の変更
>   - SDK を使用するアプリの`Minimum Deployments`が`iOS 12.1`以下の場合、`Build Settings`の`Runpath Search Paths`に`/usr/lib/swift`を追加する必要があります。
>   - `Other Linker Flags`に`-L$(DEVELOPER_DIR)/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/$(PLATFORM_NAME)`を追加する必要があります。
>   - `Library Search Paths`に`$(SDKROOT)/usr/lib/swift`を追加する必要があります。
