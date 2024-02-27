# Changelog

All notable changes to this project will be documented in this file.

## [2.0.0] - 2024-02-27

### Changed

- Privacy Manifest is now supported.

> [!WARNING]
> This SDK includes the privacy manifest (PrivacyInfo.xcprivacy), but we have confirmed that apps incorporating the SDK do not include the SDK's privacy manifest.
> Therefore, please include it in the privacy manifest of your application.
> Please refer [README.md](./README.md) for details.

- Migrated the development language of OptimalRemote In-App Remote SDK for iOS from Objective-C to Swift.

> [!WARNING]
> This version includes some breaking changes:
> - Changed the names of some signature
>   - `ORIASessionDelegate.oriaSessionDidSetMicrohponeEnabled`
>     - Changed to `ORIASessionDelegate.oriaSessionDidSetMicrophoneEnabled`
>   - `ORIAUIAssistiveButtonViewSetting.assistiveButtoView`
>     - Changed to `ORIAUIAssistiveButtonViewSetting.assistiveButtonView`
>   - `ORIAUIViewDelegateDefault.isVoiceChatSpeakerActive`
>     - Changed to `ORIAUIViewDelegateDefault.isVoiceChatSpeakerActivate`
> - Changed the needed build settings
>   - If your application's `Minimum Deployments` is `iOS 12.1` or above, Add `/usr/lib/swift` to `Build Settings`'s `Runpath Search Paths`
>   - Add `-L$(DEVELOPER_DIR)/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/$(PLATFORM_NAME)` to `Other Linker Flags`
>   - Add `$(SDKROOT)/usr/lib/swift` to `Library Search Paths`
