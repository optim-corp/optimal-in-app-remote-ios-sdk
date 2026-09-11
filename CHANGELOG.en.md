# Changelog

All notable changes to this project will be documented in this file.

## [2.4.2] - 2026-09-11

### Changed

- Added support for iOS 27.
- Added support for the Split View feature.
- Added support for the Multiple Windows feature.
- Released `ORIAWindow.resize`.

> [!NOTE]
> Please refer to [README.md](./README.md) for details on `ORIAWindow.resize`.

### Fixed

- Fixed an issue where the red pen drawing would disappear when tilting the device forward during screen sharing.
- Fixed an issue where the remote control button remained enabled in the Windows operator tool even when `ORIASession.remoteInputEnabled` was set to `false`.

## [2.4.1] - 2026-05-29

- Fixed an issue where the icon state would become inconsistent when reconnecting while using the screen sharing pause feature.
- Removed the registration flow documentation because its content no longer matched the current registration flow.

## [2.4.0] - 2026-02-24

### Changed

- Added screen sharing pause feature.

> [!NOTE]
> Please refer to [CUSTOMIZE.en.md](./docs/CUSTOMIZE.en.md) for details on the screen sharing pause feature.

- Added support for iOS 26.

## [2.3.0] - 2025-11-07

### Changed

- Added masking feature.

> [!NOTE]
> Please refer to [CUSTOMIZE.en.md](./docs/CUSTOMIZE.en.md) for details on the masking feature.

## [2.2.0] - 2025-06-23

### Changed

- Added UI design customization feature for SDK-displayed UI.

> [!NOTE]
> Please refer to [CUSTOMIZE.en.md](./docs/CUSTOMIZE.en.md) for details on the design customization feature.

## [2.1.2] - 2024-12-18

### Changed

- Added SDK without voice call feature ([OptimalRemoteNoVoIP.xcframework.zip](./OptimalRemoteNoVoIP.xcframework.zip)).

> [!NOTE]
> OptimalRemoteNoVoIP.xcframework.zip excludes modules related to the voice call feature, but there are no differences in other features.

- Added `ORIASession.setLocale` as an API to switch the language displayed by the SDK in the UI.

> [!NOTE]
> Please refer to [CUSTOMIZE.en.md](./docs/CUSTOMIZE.en.md) for details on switching the display language of the SDK.

### Fixed

- Fixed a build error that occurred when incorporating the SDK into apps that conform `UIGestureRecognizerDelegate` to `UIView` (and its derived classes).

## [2.1.1] - 2024-10-04

### Changed

- Added support for iOS 18.

### Fixed

- Fixed an issue where the system model of device information had an invalid value.

## [2.1.0] - 2024-05-14

### Changed

- Added support for the Simulator.

> [!NOTE]
> Frameworks for physical devices and simulators are bundled in the xcframework.
> When incorporating, please add the xcframework directory to your project.
> Please refer to [README.en.md](./README.en.md) for details.

- Added support for Library Evolution.

> [!NOTE]
> When incorporating into Swift apps, it is no longer necessary to match the Swift compiler version with this SDK.

## [2.0.0] - 2024-03-22

### Changed

- Privacy Manifest is now supported.

> [!WARNING]
> This SDK includes the privacy manifest (PrivacyInfo.xcprivacy), but we have confirmed that apps incorporating the SDK do not include the SDK's privacy manifest.
> Therefore, please include it in the privacy manifest of your application.
> Please refer [README.en.md](./README.en.md) for details.

- Migrated the development language of OptimalRemote In-App Remote SDK for iOS from Objective-C to Swift.

> [!WARNING]
> This version includes some breaking changes:
>
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
