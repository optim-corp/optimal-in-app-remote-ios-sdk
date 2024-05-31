# Optimal In-App Remote SDK for iOS

"Optimal In-App Remote SDK for iOS" is a developer kit that provides remote assistance features for your iOS app.
By incorporating this SDK into your iOS application, you can provide remote assistance for your app using [Optimal Remote](https://www.optim.com/products-detail/top/40).

## Operating environment

- Operating Environment for app
  1.  iOS 12 - iOS 17
  2.  iPhone or iPad running on operating system above are supported.
  3.  English / Japanese environment
      - UIs will be displayed in English for languages not listed above.
  4.  Access to the Internet is required.
- Required development environment
  1.  Xcode 15.0 or later

## SDK features

### Screen sharing

SDK allows real-time sharing of your app's screen.

### Remote control feature

SDK allows your app to be operated by remote operators (help desks, customer support team, etc.).

### Highlighting

SDK allows remote operators to highlight and draw on the screen using a red marker, providing more efficient instructions to users.

### Finger indicator

SDK also allows remote operators to point to the specific area of the screen using a finger icon.

### Voice call

SDK also provides VoIP voice calls between app user and remote operator for easier support.

## Incorporating SDK to your project

Before starting with the procedure below, register as a developer and make sure you have all the requirements listed below:

[Please refer here for the detail request steps.](docs/REGISTRATION.md)

1.  Profile and key pair required for SDK
2.  Optimal Remote Operator Tool (for Windows)
3.  User account (user ID and password) for using Optimal Remote Operator Tool

### 0. Run checkout on the following git repository.

When downloaded as a ZIP file, files contained in "OptimalRemote.framework" lose structure and becomes invalid. Make sure to use Git repository instead and run checkout.

Next, unzip "OptimalRemote.framework.zip" in the directory that you checked out.

### 1. Add "OptimalRemote.framework" directory to your project.

"OptimalRemote.framework" directory contains a set of header files and static library files. Follow the instructions below to add "OptimalRemote.framework" contained in the Git repository to your project.

- [Embedding Frameworks In An App : Embedding a Framework in iOS, macOS, watchOS, and tvOS Apps](https://developer.apple.com/library/archive/technotes/tn2435/_index.html#//apple_ref/doc/uid/DTS40017543-CH1-EMBED_IN_APP_SECTION)
- [Project Navigator Help: Adding an Existing File or Folder](https://developer.apple.com/library/ios/recipes/xcode_help-structure_navigator/articles/Adding_an_Existing_File_or_Folder.html)

### 2. Add "OptimalRemoteResources" directory to your project.

"OptimalRemoteResources" directory contains a set of text and image files required to use this SDK. Follow the instructions below to add "OptimalRemoteResources" contained in the Git repository to your project.

- [Managing Files and Folders in Your Xcode Project: Add Existing Files and Folders to a Project](https://developer.apple.com/documentation/xcode/managing-files-and-folders-in-your-xcode-project)

### 3. Adding Framework links required by SDK

To successfully build apps with SDK features, following Framework links need to be added to your project.

1.  AudioToolbox.framework
2.  AVFoundation.framework
3.  CoreMedia.framework
4.  CoreVideo.framework
5.  OpenGLES.framework
6.  SystemConfiguration.framework
7.  Security.framework
8.  libsqlite3.tbd

### 4. Adding linker flags required for SDK

Because SDK utilizes category classes, you need to add both `-ObjC` and `-lc++ -lstdc++ -L$(DEVELOPER_DIR)/Toolchains/XcodeDefault.xctoolchain/usr/lib/swift/$(PLATFORM_NAME)` to linker flags before building your project. Follow instructions below to add linker flags to your project.

- [Technical Q&A QA1490: Building Objective-C static libraries with categories](https://developer.apple.com/library/mac/qa/qa1490/_index.html)

### 5. Adding settings required for using SDK

1.  Please add `$(SDKROOT)/usr/lib/swift` in `Library Search Paths` of `Build Settings`.
2.  If `Minimum Deployments` of application using SDK is iOS 12 or less, please add `/usr/lib/swift` in `Runpath Search Paths` of `Build Settings`.

## Tutorials for using SDK

Following describes sets of codes frequently used in apps utilizing this SDK.

### 1. Supporting device's screen rotation

Following code is not necessary if your app does not support screen rotation.

Screen displayed by SDK is displayed in window that is not "keyWindow". Therefore, device's screen rotation needs to be implemented separately.

In the case of App-Based Life-Cycle apps, insert following codes to `application:willChangeStatusBarOrientation:duration:` method in `UIApplicationDelegate` protocol.

```objc
...
// 1. Importing headers required for SDK.
#import "OptimalRemote/OptimalRemote.h"
...

- (void)application:(UIApplication *)application willChangeStatusBarOrientation:
  (UIInterfaceOrientation)newStatusBarOrientation duration:(NSTimeInterval)duration {
    ...
    // 2. When devices are rotated, rotate the screen displayed by SDK.
    [ORIAWindow setOrientation:newStatusBarOrientation withDuration:duration];
}
...
```

In the case of a Scene-Based Life-Cycle app, the following code can be added to the `UIWindowSceneDelegate` protocol's For apps with `UIWindowSceneDelegate` protocol, you can add the following code to the `windowScene:didUpdateCoordinateSpace:interfaceOrientation:traitCollection:` method.

```objc
...
// 1. Importing headers required for SDK.
#import "OptimalRemote/OptimalRemote.h"
...

- (void)windowScene:(UIWindowScene *)windowScene
    didUpdateCoordinateSpace:(id<UICoordinateSpace>)previousCoordinateSpace
    interfaceOrientation:(UIInterfaceOrientation)previousInterfaceOrientation
    traitCollection:(UITraitCollection *)previousTraitCollection {
    ...
    // 2. When devices are rotated, rotate the screen displayed by SDK.
    [ORIAWindow setOrientation:[windowScene interfaceOrientation] withDuration:0];
}
...
```

For more information about App-Based Life-Cycle and Scene-Based Life-Cycle, please refer to the following.

- [Managing Your App's Life Cycle](https://developer.apple.com/documentation/uikit/app_and_environment/managing_your_app_s_life_cycle?language=objc)

### 2. Create an instance of "ORIASession" class.

For this tutorial, instance of "ORIASession" class is created using `viewDidLoad` method derived from `UIViewController` class. "ORIASession" class is one of SDK's core classes for implementing iOS app remote support.

```objc
...
// 3. Importing headers required for SDK.
#import "OptimalRemote/OptimalRemote.h"
...
// 4.
@interface XxxViewController () <ORIASessionControllerAppDelegate>
...
// 5. Add "ORIASession" control class to the property.
@property (nonatomic, strong) ORIASessionController *controller;
// 6. Add "ORIASession" class to the property.
@property (nonatomic, strong) ORIASession *session;
...
@end
...
- (void)viewDidLoad {
    [super viewDidLoad];
    ...
    // 7. Copy and paste the content of ".profile" to replace "XXXXXXXX" below:
    NSString *PROFILE = @"XXXXXXXX";
    // 8. Copy and paste the content of ".key" to replace "XXXXXXXX" below:
    NSString *KEY = @"XXXXXXXX";

    // 9. Create an instance of "ORIASession" control class.
    self.controller = [ORIASessionController defaultController];
    self.controller.appDelegate = self;

    // 10. Create an instance of "ORIASession" class.
    self.session = [ORIASession sessionForProfile:PROFILE signedBy:KEY];
    // Enable VoIP (default: NO)
    self.session.voiceChatEnabled = YES;
    // Output audio from the speakers when no headphone is connected (default: NO).
    self.session.voiceChatOverridesSpeakerWhenNoHeadphones = YES;
    self.session.delegate = self.controller;
    [self.session loadDefaultPointerImages];
}
```

### 3. Start "ORIASession" when the button is tapped.

In this tutorial, the derived class of "UIViewController" class has "UIButton" class property "helpMeButton". We insert following codes so that "ORIASession" is initiated when this button is tapped.

```objc
...
// 11. Method for initiating "ORIASession"
- (void)controllerDidOpen:(ORIASessionController *)controller {
    // Disable button until "ORIASession" is completed.
    self.helpMeButton.enabled = NO;
}

// 12. Method for completing "ORIASession"
- (void)controllerDidComplete:(ORIASessionController *)controller remoteConnectionHasEstablished:
  (BOOL)remoteConnectionHasEstablished {
    // Enable button after "ORIASession" is completed.
    self.helpMeButton.enabled = YES;
    // Displaying completion screen
    if (remoteConnectionHasEstablished) {
        [ORIAUISplashWindow showForCompletion];
    }
}

//  13. Method to run when "helpMeButton" is tapped
- (IBAction)helpMeButtonDidTouchUpInside:(id)sender {
    // Displaying startup screen and initiate "ORIASession"
    if (self.controller.canOpen) {
        [ORIAUISplashWindow showWithBlock:^{
            [self.session open];
        }];
    }
}
...
```

### 4. Configure App Transport Security

"optim.co.jp" and its subdomains must be set as an exception to App Transport Security (ATS), which as added in iOS 9.

For the next setup, avoid interruptions of SDK communications by ATS.
Add the ATS settings to the "plist" element of "Info.plist."

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
...
    <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSExceptionDomains</key>
        <dict>
            <key>optim.co.jp</key>
            <dict>
                <key>NSExceptionRequiresForwardSecrecy</key>
                <false/>
                <key>NSIncludesSubdomains</key>
                <true/>
            </dict>
        </dict>
    </dict>
...
</dict>
</plist>
```

### 5. Set Background Modes

Please add Background Modes settings to the "plist" element of "Info.plist".
This prevents VoIP from disconnecting when the application is running in the background.

```Info.plist
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
...
    <key>UIBackgroundModes</key>
    <array>
        <string>audio</string>
    </array>
...
</dict>
</plist>
```

This will complete the preparations to be made on iOS application side.

### 6. Connecting to the Operator Tool

After building your app, run the app from the device with access to the Internet. Tap `helpMeButton` to display "Receipt Number". Enter this Receipt Number from Operator Tool. Operator Tool and App is connected and app screen is displayed on Operator Tool. Now you are ready to go!

This completes the tutorial for SDK. Please contact us if you experience problems connecting to the Operator Tool.

### 7. Support for iOS 11 and later

The following issue occurs when displaying a dialog using UIAlertView on iOS 11 and later.

- The disconnect confirmation dialog is not displayed. As a result, disconnection from the device cannot be performed.
- When remote control is requested from the operator tool, the remote control permission dialog will not be displayed. As a result, remote control cannot be performed.

The cause is that the keyWindow setting was unintentionally changed, which caused the above event.
UIAlertView is a deprecated module since iOS 8, and it is recommended to use UIAlertController to display dialogs.
[UIAlertView](https://developer.apple.com/documentation/uikit/uialertview)

Therefore, if you plan to support iOS 11 and later, please use UIAlertController for displaying dialogs, and implement branching processes as necessary if you plan to support versions of under iOS 11.

This completes the tutorial. If you cannot connect to the operator tool successfully, please contact us.

### 8. Configure Privacy Manifest

Starting in spring 2024, if your new app or app update submission to the App Store, you’ll need to include the privacy manifest for the SDK.
Please refer to the following documents for more information on privacy manifests.

- [Privacy manifest files](https://developer.apple.com/documentation/bundleresources/privacy_manifest_files)

The SDK includes the privacy manifest (PrivacyInfo.xcprivacy), but we have confirmed that apps incorporating the SDK do not include the SDK's privacy manifest.

Therefore, please include the following items in the privacy manifest of your application.

#### NSPrivacyTracking

A Boolean that indicates whether your app or third-party SDK uses data for tracking as defined under the App Tracking Transparency framework.

In the SDK, NO (false) because the data is not used for tracking.

#### NSPrivacyTrackingDomains

An array of strings that lists the internet domains your app or third-party SDK connects to that engage in tracking.

Empty because it is not tracked by the SDK.

#### NSPrivacyCollectedDataTypes

An array of dictionaries that describes the data types your app or third-party SDK collects.

The SDK collects the following data.
See [Describing data use in privacy manifests](https://developer.apple.com/documentation/bundleresources/privacy_manifest_files/describing_data_use_in_privacy_manifests) for the following keys and values.

| NSPrivacyCollectedDataType                | NSPrivacyCollectedDataTypeLinked | NSPrivacyCollectedDataTypeTracking | NSPrivacyCollectedDataTypePurposes                |
| ----------------------------------------- | -------------------------------- | ---------------------------------- | ------------------------------------------------- |
| NSPrivacyCollectedDataTypeAudioData       | false                            | false                              | NSPrivacyCollectedDataTypePurposeAppFunctionality |
| NSPrivacyCollectedDataTypeCustomerSupport | false                            | false                              | NSPrivacyCollectedDataTypePurposeAppFunctionality |

#### NSPrivacyAccessedAPITypes

An array of dictionaries that describe the API types your app or third-party SDK accesses that have been designated as APIs that require reasons to access.

The SDK accesses the following API types.See [Describing use of required reason API](https://developer.apple.com/documentation/bundleresources/privacy_manifest_files/describing_use_of_required_reason_api) for the following keys and values.

| NSPrivacyAccessedAPIType                   | NSPrivacyAccessedAPITypeReasons |
| ------------------------------------------ | ------------------------------- |
| NSPrivacyAccessedAPICategoryUserDefaults   | CA92.1                          |
| NSPrivacyAccessedAPICategoryFileTimestamp  | C617.1                          |
| NSPrivacyAccessedAPICategorySystemBootTime | 35F9.1                          |
| NSPrivacyAccessedAPICategoryDiskSpace      | E174.1                          |

### 9. App Privacy on App Store Connect

This information about your app’s privacy practices, including the practices of third-party partners whose code you integrate into your app, is required to submit new apps and app updates to the App Store.

When submitting your app, please describe the following "Types of data" and "Data use".

| Types of data    | Data use          |
| ---------------- | ----------------- |
| Audio Data       | App Functionality |
| Customer Support | App Functionality |
