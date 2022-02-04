# Optimal In-App Remote SDK for iOS

Optimal In-App Remote SDK for iOS は、iOS アプリの遠隔支援を実現するための開発キットです。
この SDK をアプリに組み込むことで、そのアプリを [Optimal Remote](http://www.optim.co.jp/products-detail/top/40) で遠隔支援できるようになります。

Android 版 SDK も近日中に対応予定です。

## 対象環境
 - アプリ動作環境
     1. iOS 9 〜 iOS 15
     2. 上記 OS で動作している iPhone または iPad
     3. 英語、日本語
         - 上記以外の言語環境では英語表記になります
     4. インターネットに接続できるネットワーク環境
 - 開発環境
     1. Xcode 7.0 以降

## この SDK でできること

### 画面共有機能
SDK を組み込んだアプリの画面をオペレーターがリアルタイムに閲覧できます。

### 遠隔操作機能
SDK を組み込んだアプリをオペレーターが操作できます。

### 赤ペン機能
SDK を組み込んだアプリの画面にオペレーターが赤ペンで書き込むことでユーザーに操作を指示することができます。

### 指さし機能
SDK を組み込んだアプリの画面にオペレーターから指マークを表示することでユーザーに操作を指示することができます。

### 音声通話機能
オペレーターがユーザーと VoIP で音声通話しながら遠隔支援を効果的に実施することができます。

## SDK をプロジェクトに導入する
以下の手順を進める前に、開発者登録をしていただき以下をご用意ください。

[詳しい手順はこちらを参照してください。](docs/REGISTRATION.md)

 1. SDK を利用するためのプロファイル・キーペア
 2. オペレーターツール (Windows 版)
 3. オペレーターツールを利用するためのアカウント (ID・パスワード)

### 0. この Git レポジトリをチェックアウトする
ZIP としてダウンロードすると OptimalRemote.framework の構成が不正になるので Git レポジトリとしてチェックアウトしてください。

### 1. OptimalRemote.framework ディレクトリをプロジェクトに追加する
OptimalRemote.framework には、SDK を利用するのに必要なヘッダファイル・静的ライブラリファイルファイルが含まれています。OptimalRemote.framework をプロジェクトに追加するには、この Git レポジトリに含まれる OptimalRemote.framework ディレクトリを以下を参考に追加してください。

 - [Embedding Frameworks In An App : Embedding a Framework in iOS, macOS, watchOS, and tvOS Apps](https://developer.apple.com/library/archive/technotes/tn2435/_index.html#//apple_ref/doc/uid/DTS40017543-CH1-EMBED_IN_APP_SECTION)
 - [Project Navigator Help: Adding an Existing File or Folder](https://developer.apple.com/library/ios/recipes/xcode_help-structure_navigator/articles/Adding_an_Existing_File_or_Folder.html)

### 2. OptimalRemoteResources ディレクトリ をプロジェクトに追加する
OptimalRemoteResources ディレクトリには、SDK を利用するのに必要な文字列ファイル・画像ファイル一式が含まれています。OptimalRemoteResources ディレクトリをプロジェクトに追加するには、この Git レポジトリに含まれる OptimalRemoteResources ディレクトリを以下を参考に追加してください。

 - [Managing Files and Folders in Your Xcode Project: Add Existing Files and Folders to a Project](https://developer.apple.com/documentation/xcode/managing-files-and-folders-in-your-xcode-project)

### 3. SDK に必要な Framework へのリンクを追加する
SDK を利用したアプリをビルドするには、以下の Framework へのリンクを追加する必要があります。

 1. AssetsLibrary.framework
 2. AudioToolbox.framework
 3. AVFoundation.framework
 4. CoreMedia.framework
 5. CoreVideo.framework
 6. OpenGLES.framework
 7. SystemConfiguration.framework
 8. Security.framework
 9. libsqlite3.tbd

### 4. SDK に必要なリンカフラグを追加する
SDK はカテゴリクラスを利用しているため、リンカフラグに「-ObjC」を追加してビルドする必要があります。また「-lc++ -lstdc++」を追加してビルドする必要があります。リンカフラグを追加するには以下を参考にしてください。

 - [Technical Q&A QA1490: Building Objective-C static libraries with categories](https://developer.apple.com/library/mac/qa/qa1490/_index.html)

## SDK の利用するためのチュートリアル
SDK を利用するには、いくらかお決まりのコードを記述する必要があります。

### 1. 端末の画面回転に対応する
アプリが端末の画面対応に対応していない場合、以下の対応は不要です。

SDK が表示する画面は、keyWindow とは別のウィンドウに表示されます。そのため、端末の画面対応に手動で対応する必要があります。

App-Based Life-Cycle のアプリの場合、`UIApplicationDelegate` プロトコルの `application:willChangeStatusBarOrientation:duration:` メソッドに以下のようにコードを追加することで対応することができます。

```XxxAppDelegate.m
...
// 1. SDK を利用するためのヘッダをインポートする
#import "OptimalRemote/OptimalRemote.h"
...

- (void)application:(UIApplication *)application willChangeStatusBarOrientation:
  (UIInterfaceOrientation)newStatusBarOrientation duration:(NSTimeInterval)duration {
    ...
    // 2. 画面が回転した時に SDK が表示する画面を回転させる
    [ORIAWindow setOrientation:newStatusBarOrientation withDuration:duration];
}
...
```

Scene-Based Life-Cycle のアプリの場合、`UIWindowSceneDelegate` プロトコルの `windowScene:didUpdateCoordinateSpace:interfaceOrientation:traitCollection:` メソッドに以下のようにコードを追加することで対応することができます。

```XxxSceneDelegate.m
...
// 1. SDK を利用するためのヘッダをインポートする
#import "OptimalRemote/OptimalRemote.h"
...

- (void)windowScene:(UIWindowScene *)windowScene
    didUpdateCoordinateSpace:(id<UICoordinateSpace>)previousCoordinateSpace
    interfaceOrientation:(UIInterfaceOrientation)previousInterfaceOrientation
    traitCollection:(UITraitCollection *)previousTraitCollection {
    ...
    // 2. 画面が回転した時に SDK が表示する画面を回転させる
    [ORIAWindow setOrientation:[windowScene interfaceOrientation] withDuration:0];
}
...
```

App-Based Life-Cycle や Scene-Based Life-Cycle については以下を参考にしてください。
- [Managing Your App's Life Cycle](https://developer.apple.com/documentation/uikit/app_and_environment/managing_your_app_s_life_cycle?language=objc)

### 2. ORIASession クラスのインスタンスを作る
ここでは例として、`UIViewController` クラスの派生クラスの `viewDidLoad` メソッドで `ORIASession` クラスのインスタンスを作ります。`ORIASession` クラスは、SDK で iOS アプリの遠隔支援を実現するためのコアクラスのひとつです。

```XxxViewController.m
...
// 3. SDK を利用するためのヘッダをインポートする
#import "OptimalRemote/OptimalRemote.h"
...
// 4. 
@interface XxxViewController () <ORIASessionControllerAppDelegate>
...
// 5. ORIASession の制御クラスをプロパティに追加する
@property (nonatomic, strong) ORIASessionController *controller;
// 6. ORIASession クラスをプロパティに追加する
@property (nonatomic, strong) ORIASession *session;
...
@end
...
- (void)viewDidLoad {
    [super viewDidLoad];
    ...
    // 7. .profile の内容を以下に貼り付ける
    NSString *PROFILE = @"XXXXXXXX";
    // 8. .key の内容を以下に貼り付ける
    NSString *KEY = @"XXXXXXXX";

    // 9. ORIASession の制御クラスのインスタンスを作る
    self.controller = [ORIASessionController defaultController];
    self.controller.appDelegate = self;

    // 10. ORIASession クラスのインスタンスを作る
    self.session = [ORIASession sessionForProfile:PROFILE signedBy:KEY];
    // VoIP を有効にする (既定では NO)
    self.session.voiceChatEnabled = YES;
    // ヘッドフォンがない場合にスピーカーから音声を出力する (既定では NO)
    self.session.voiceChatOverridesSpeakerWhenNoHeadphones = YES;
    self.session.delegate = self.controller;
    [self.session loadDefaultPointerImages];
}
```

### 3. ボタンがタップされたら ORIASession を開始する
ここでは例として、`UIViewController` クラスの派生クラスが `helpMeButton` という `UIButton` クラスのプロパティを持っていると仮定し、そのボタンがタップされたら ORIASession を開始する、というコードを追加します。

```XxxViewController.m
...
// 11. ORIASession が開始したときのメソッド
- (void)controllerDidOpen:(ORIASessionController *)controller {
    // ORIASession が完了するまでボタンを無効化する
    self.helpMeButton.enabled = NO;
}

// 12. ORIASession が完了したときのメソッド
- (void)controllerDidComplete:(ORIASessionController *)controller remoteConnectionHasEstablished:
  (BOOL)remoteConnectionHasEstablished {
    // ORIASession が完了したのでボタンを有効化する
    self.helpMeButton.enabled = YES;
    // 完了画面を表示する
    if (remoteConnectionHasEstablished) {
        [ORIAUISplashWindow showForCompletion];
    }
}

//  13. helpMeButton がタップされたときのメソッド
- (IBAction)helpMeButtonDidTouchUpInside:(id)sender {
    // 開始画面を表示して ORIASession を開始する
    if (self.controller.canOpen) {
        [ORIAUISplashWindow showWithBlock:^{
            [self.session open];
        }];
    }
}
...
```

### 4. App Transport Securityを設定する
iOS 9 から追加された App Transport Security(ATS) へ optim.co.jp とそのサブドメインを例外として設定する必要があります。

次の設定を行うことで SDK の通信が ATS によって中断されることを回避します。
Info.plist の plist 要素へ ATS の設定を追加してください。

```Info.plist
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

これで iOS アプリ側の準備は完了です。

### 5. オペレーターツールと接続する
アプリをビルドしたら、インターネットに接続された端末でアプリを実行し、`helpMeButton` をタップすると「受付番号」が表示されます。オペレーターツールでこの受付番号を入力すると、オペレーターツールとアプリが接続され、オペレーターツールにアプリの画面が表示されます！

### 6. iOS 11 の対応について
iOS 11 にて UIAlertView を用いたダイアログ表示を行うと以下の事象が発生します。
 - 切断確認ダイアログが表示されない。これに伴い、端末から切断が行えない。
 - オペレーターツールから遠隔操作をリクエストした場合に、遠隔操作許可ダイアログが表示されない。これに伴い、遠隔操作が行えない。

原因は keyWindow の設定が意図せず変更されており、これの影響を受けて上記の事象が発生しております。
UIAlertView は iOS 8 以降は非推奨となっているモジュールで、ダイアログの表示には UIAlertController を用いることが推奨されています。
[UIAlertView](https://developer.apple.com/documentation/uikit/uialertview)

ですので iOS 11 に対応される場合には、ダイアログ表示には UIAlertController を使用し、 iOS 11 未満にも対応される場合には必要に応じて分岐の処理を実装いただけますようお願い致します。

以上でチュートリアルは完了です。うまくオペレーターツールと接続できない場合、お問い合わせください。
