# Changelog

このプロジェクトに対するすべての重要な変更は、このファイルに文書化されます。

## [2.1.0] - 2024-05-14

### Changed

- シミュレーターに対応しました。

> [!NOTE]
> 実機用・シミュレーター用のframeworkをxcframeworkにバンドルしています。
> 組み込む場合はxcframeworkディレクトリをプロジェクトに追加してください。
> 詳細は[README.ja.md](./README.ja.md)を参照してください。

- Library Evolutionに対応しました。

> [!NOTE]
> Swift製のアプリに組み込む際に、本SDKとSwiftコンパイラバージョンを揃える必要がなくなりました。

## [2.0.0] - 2024-03-22

### Changed

- Privacy Manifestに対応しました。

> [!WARNING]
> このSDKはPrivacy Manifest(PrivacyInfo.xcprivacy)を含んでいますが、SDKを組み込んだアプリにSDKのPrivacy Manifestが含まれていないことを確認しています。
> そのため、組み込むアプリのPrivacy Manifestに記載が必要になります。
> 詳細は[README.ja.md](./README.ja.md)を参照してください。

- OptimalRemote In-App Remote SDK for iOSの開発言語をObjective-CからSwiftに移行しました。

> [!WARNING]
> 以下の破壊的変更が含まれます。
> - いくつかのシグネチャの名称の変更
>   - `ORIASessionDelegate.oriaSessionDidSetMicrohponeEnabled`
>     - `ORIASessionDelegate.oriaSessionDidSetMicrophoneEnabled`に変更
>   - `ORIAUIAssistiveButtonViewSetting.assistiveButtoView`
>     - `ORIAUIAssistiveButtonViewSetting.assistiveButtonView`に変更
>   - `ORIAUIViewDelegateDefault.isVoiceChatSpeakerActive`
>     - `ORIAUIViewDelegateDefault.isVoiceChatSpeakerActivate`に変更
> - ビルド手順の変更
>   - SDKを使用するアプリの`Minimum Deployments`が`iOS 12.1`以下の場合、`Build Settings`の`Runpath Search Paths`に`/usr/lib/swift`を追加する必要があります。
>   - `Other Linker Flags`に`-L$(DEVELOPER_DIR)/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/$(PLATFORM_NAME)`を追加する必要があります。
>   - `Library Search Paths`に`$(SDKROOT)/usr/lib/swift`を追加する必要があります。
