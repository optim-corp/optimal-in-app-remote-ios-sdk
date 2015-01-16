# Optimal In-App Remote SDK for iOS

"Optimal In-App Remote SDK for iOS" is a developer kit that provides remote assistance features for your iOS app.
By incorporating this SDK into your iOS application, you can provide remote assistance for your app using [Optimal Remote](http://en.optim.co.jp/contents/5480).

Android version of SDK is also available soon.

##Operating environment
 - Operating Environment for app
     1. iOS 6 or later
     2. iPhone or iPad running on operating system above are supported.
     3. English / Japanese environment
         - UIs will be displayed in English for languages not listed above.
     4. Access to the Internet is required.
 - Required development environment
     1. Xcode 6.1 or later

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

 1. Profile and key pair required for SDK
 2. Optimal Remote Operator Tool (for Windows)
 3. User account (user ID and password) for using Optimal Remote Operator Tool

### 0. Run checkout on the following git repository.
When downloaded as a ZIP file, files contained in "OptimalRemote.framework" lose structure and becomes invalid. Make sure to use Git repository instead and run checkout.

Next, unzip "OptimalRemote.framework.zip" in the directory that you checked out.

### 1. Add "OptimalRemote.framework" directory to your project.
"OptimalRemote.framework" directory contains a set of header files and static library files. Follow the instructions below to add "OptimalRemote.framework" contained in the Git repository to your project.

 - [Project Navigator Help: Adding an Existing File or Folder](https://developer.apple.com/library/ios/recipes/xcode_help-structure_navigator/articles/Adding_an_Existing_File_or_Folder.html)

### 2. Add "OptimalRemoteResources" directory to your project.
"OptimalRemoteResources" directory contains a set of text and image files required to use this SDK. Follow the instructions below to add "OptimalRemoteResources" contained in the Git repository to your project.

 - [Project Navigator Help: Adding an Existing File or Folder](https://developer.apple.com/library/ios/recipes/xcode_help-structure_navigator/articles/Adding_an_Existing_File_or_Folder.html)

### 3. Adding Framework links required by SDK
To successfully build apps with SDK features, following Framework links need to be added to your project.

 1. AssetsLibrary.framework
 2. AudioToolbox.framework
 3. AVFoundation.framework
 4. CoreMedia.framework
 5. CoreVideo.framework
 6. OpenGLES.framework
 7. SystemConfiguration.framework
 8. Security.framework
 9. libsqlite3.dylib

Follow instructions below to add Framework links to your project.

 - [Project Editor Help: Linking to a Library or Framework](https://developer.apple.com/library/ios/recipes/xcode_help-project_editor/Articles/AddingaLibrarytoaTarget.html)

### 4. Adding linker flags required for SDK
Because SDK utilizes category classes, you need to add "-ObjC" linker flags before building your project. Or you can add "-lc++ -lstdc++" before building. Follow instructions below to add linker flags to your project.

 - [Technical Q&A QA1490: Building Objective-C static libraries with categories](https://developer.apple.com/library/mac/qa/qa1490/_index.html)

## Tutorials for using SDK
Following describes sets of codes frequently used in apps utilizing this SDK.

### 1. Supporting device's screen rotation
Following code is not necessary if your app does not support screen rotation.

Screen displayed by SDK is displayed in window that is not "keyWindow". Therefore, device's screen rotation needs to be implemented separately.

Insert following codes to `application:willChangeStatusBarOrientation:duration:` method in `UIApplicationDelegate` protocol.

```XxxAppDelegate.m
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

### 2. Create an instance of "ORIASession" class.
For this tutorial, instance of "ORIASession" class is created using `viewDidLoad` method derived from `UIViewController` class. "ORIASession" class is one of SDK's core classes for implementing iOS app remote support.

```XxxViewController.m
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
In this tutorial, the derived class of "UIViewController" class has  "UIButton" class property "helpMeButton".  We insert following codes so that "ORIASession"  is initiated when this button is tapped.

```XxxViewController.m
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

This will complete the preparations to be made on iOS application side.

### 4. Connecting to the Operator Tool
After building your app, run the app from the device with access to the Internet. Tap `helpMeButton` to display "Receipt Number". Enter this Receipt Number from Operator Tool. Operator Tool and App is connected and app screen  is displayed on Operator Tool. Now you are ready to go!

This completes the tutorial for SDK. Please contact us if you experience problems connecting to the Operator Tool.