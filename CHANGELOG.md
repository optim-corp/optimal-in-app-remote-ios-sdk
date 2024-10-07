# Changelog

このプロジェクトに対するすべての重要な変更は、このファイルに文書化されます。

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
