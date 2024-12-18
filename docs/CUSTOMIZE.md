# Optimal In-App Remote SDK for iOS アプリのカスタマイズ

## 遠隔操作機能

既定では、オペレーターからの遠隔操作が有効になっています。

オペレーターから遠隔操作を要求された場合、既定ではそれを許可するかどうかのダイアログが表示され、ユーザーの選択結果に応じて以下のように振る舞います。

- 「許可」を選択した場合
  - オペレーターからの遠隔操作を受け入れるようになります
  - 再度遠隔操作を要求した場合、自動的に遠隔操作を受け入れます
- 「許可 (今回のみ)」を選択した場合
  - オペレーターからの遠隔操作を受け入れるようになります
  - 再度遠隔操作を要求した場合、ダイアログが表示されます
- 「拒否」を選択した場合
  - オペレーターからの遠隔操作を受け入れません
  - 再度遠隔操作を要求した場合、ダイアログが表示されます

### 遠隔操作機能を無効化する

オペレーターからの遠隔操作を無効にしたい場合、`ORIASession` クラスのインスタンスを作成した直後に `remoteInputEnabled` プロパティを `NO` にしてください。`NO` にすると、遠隔操作を許可するかどうかのダイアログは表示されず、遠隔操作も実行されません。

### 遠隔操作機能をダイアログなしで自動的に許可する

オペレーターからの遠隔操作をダイアログなしで自動的に許可したい場合、`ORIASession` クラスのインスタンスを作成した直後に `remoteInputAcceptsAutomaticallyEnabled` プロパティを `YES` にしてください。`YES` にすると、遠隔操作を許可するかどうかのダイアログは表示されず、自動的に遠隔操作が許可されます。

## 音声通話機能

既定では、オペレーターとの音声通話が無効になっています。

オペレーターとの音声通話が有効になっている場合、オペレーターから音声通話を要求されると音声通話を開始します。

ユーザーは、オペレーターとの接続中に表示されるアイコンをタップすると開くメニューから、必要に応じて以下を調整できます。

- スピーカーから音声を出力するようにするかどうか (ハンズフリー)
  − マイクをミュートするかどうか

### 音声通話機能を有効化する

オペレーターとの音声通話を有効にしたい場合、`ORIASession` クラスのインスタンスを作成した直後に `voiceChatEnabled` プロパティを `YES` にしてください。

### ヘッドフォンがない場合にスピーカーから音声を出力するようにする

ヘッドフォンがない場合にスピーカーから音声を出力するようにしたい場合、`ORIASession` クラスのインスタンスを作成した直後に `voiceChatOverridesSpeakerWhenNoHeadphones` プロパティを `YES` にしてください。ヘッドフォンを接続すると、スピーカーから音声を出力するように設定していてもヘッドフォンから音声を出力するようになりますが、ユーザーがメニューからスピーカーから音声を出力するように設定した場合はその限りではありません。

## WKWebView の画面共有

iOS 8 以降で WKWebView の表示画面を画面共有したい場合、 `ORIASession` クラスのインスタンスを作成した直後に `screenSharingBestEffortCaptureEnabled` プロパティを `YES` にしてください。

### ソースコード例

<details open>
<summary>Swift</summary>

```swift
if let systemVersion = Float(UIDevice.current.systemVersion) {
    session.screenSharingBestEffortCaptureEnabled = systemVersion >= 8.0
}
```

</details>

<details>
<summary>Objective-C</summary>

```objectivec
self.session.screenSharingBestEffortCaptureEnabled = [[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0;
```

</details>

## SDK 表示 の言語切り替え

SDK が UI 上に表示している言語を切り替えるには以下のように`ORIASession`クラスの`setLocale`メソッドを呼び出してください。

<details open>
<summary>Swift</summary>

```swift
// 英語に切り替える
self.session.setLocale(Locale.en)

// 日本語に切り替える
self.session.setLocale(Locale.ja)

// 端末設定に従う
self.session.setLocale(Locale.system)
```

</details>

<details>
<summary>Objective-C</summary>

```objc
// 英語に切り替える
[self.session setLocale:LocaleEn];

// 日本語に切り替える
[self.session setLocale:LocaleJa];

// 端末設定に従う
[self.session setLocale:LocaleSystem];
```

</details>
