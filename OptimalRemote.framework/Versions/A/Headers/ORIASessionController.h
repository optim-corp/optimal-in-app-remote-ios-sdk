/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import "OptimalRemote/ORIASession.h"

@class ORIAUIViewFactory;

@protocol ORIASessionControllerAppDelegate;
@protocol ORIASessionControllerAlertDelegate;

@interface ORIASessionController : NSObject<ORIASessionDelegate>

+ (instancetype)defaultController;

- (void)pauseOnServerConnectionWorking;
- (void)progressOnServerConnectionWorking:(BOOL)continueOrNot;
- (void)progressOnNotReachable:(BOOL)continueOrNot;
- (void)progressOnDidNeedAccept:(BOOL)continueOrNot;
- (void)progressOnDidFailToConnect:(BOOL)continueOrNot;
- (void)progressOnDidNeedReconnect:(BOOL)continueOrNot;
- (void)progressOnRemoteConnectionWorking:(BOOL)continueOrNot;

- (void)setSpeakerActive:(BOOL)beActive;
- (void)setMicrophoneActive:(BOOL)beActive;

@property (nonatomic, strong) ORIAUIViewFactory *viewFactory;
@property (nonatomic, strong) id<ORIASessionControllerAppDelegate> appDelegate;
@property (nonatomic, strong) id<ORIASessionControllerAlertDelegate> alertDelegate;
@property (nonatomic, readonly) BOOL canOpen;

@end

@protocol ORIASessionControllerAppDelegate <NSObject>
@optional
- (void)controllerDidOpen:(ORIASessionController *)controller;
- (void)controllerDidComplete:(ORIASessionController *)controller remoteConnectionHasEstablished:(BOOL)remoteConnectionHasEstablished;
- (void)controllerDidReceiveURL:(ORIASessionController *)controller urlString:(NSString *)urlString;
@end

@protocol ORIASessionControllerAlertDelegate <NSObject>
@required
- (void)controller:(ORIASessionController *)controller didFailByNotReachable:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller didNeedAccept:(ORIASession *)session from:(NSString *)peerName;
- (void)controller:(ORIASessionController *)controller didFailByFatalError:(ORIASession *)session with:(NSError *)error;
- (void)controller:(ORIASessionController *)controller didFailToConnect:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller didNeedReconnect:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller didRequestRemoteControl:(ORIASession *)session temporally:(BOOL)temporally;
- (void)controller:(ORIASessionController *)controller shouldDismissRemoteControlConfirmation:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller shouldDismissPendingDialog:(ORIASession *)session;
@optional
- (void)controller:(ORIASessionController *)controller didCancel:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller shouldDismissCancelIndicator:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller didAccept:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller shouldDismissAcceptIndicator:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller didDecline:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller shouldDismissDeclineIndicator:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller didDisconnect:(ORIASession *)session;
- (void)controller:(ORIASessionController *)controller shouldDismissDisconnectIndicator:(ORIASession *)session;
@end

@protocol ORIAUIViewSource <NSObject>
@optional
- (UIView *)createBackgroundView:(ORIASessionController *)controller;
- (UIView *)createReserveView:(ORIASessionController *)controller;
- (UIView *)createResolveView:(ORIASessionController *)controller ticket:(NSString *)ticket;
- (UIView *)createConnectView:(ORIASessionController *)controller reconnecting:(BOOL)reconnecting;
- (UIView *)createAssistiveButtonView:(ORIASessionController *)controller;
- (UIView *)createAssistiveMenuView:(ORIASessionController *)controller;
@end

@protocol ORIAUIViewSetting <NSObject>
@optional
- (void)view:(UIView *)parent setupBackgroundView:(ORIASessionController *)controller;
- (void)view:(UIView *)parent setupReserveView:(ORIASessionController *)controller;
- (void)view:(UIView *)parent setupResolveView:(ORIASessionController *)controller ticket:(NSString *)ticket;
- (void)view:(UIView *)parent setupConnectView:(ORIASessionController *)controller reconnecting:(BOOL)reconnecting;
- (void)view:(UIView *)parent setupAssistiveButtonView:(ORIASessionController *)controller;
- (void)view:(UIView *)parent setupAssistiveMenuView:(ORIASessionController *)controller;
@end

@protocol ORIAUIViewDelegate <NSObject>
@optional
- (void)didShowView:(UIView *)view;
- (void)willDismissView:(UIView *)view;

- (void)assistiveMenuView:(UIView *)view setVoiceChatControlsActive:(BOOL)beActive;
- (void)assistiveMenuView:(UIView *)view setVoiceChatSpeakerActive:(BOOL)beActive;
- (void)assistiveMenuView:(UIView *)view setVoiceChatMicrophoneActive:(BOOL)beActive;

- (void)didShowBackgroundView:(UIView *)view;
- (void)didShowReserveView:(UIView *)view;
- (void)didShowResolveView:(UIView *)view;
- (void)didShowConnectView:(UIView *)view;
- (void)didShowAssistiveButtonView:(UIView *)view;
- (void)didShowAssistiveMenuView:(UIView *)view;

- (void)dismissBackgroundView:(UIView *)view;
- (void)dismissReserveView:(UIView *)view;
- (void)dismissResolveView:(UIView *)view;
- (void)dismissConnectView:(UIView *)view;
- (void)dismissAssistiveButtonView:(UIView *)view;
- (void)dismissAssistiveMenuView:(UIView *)view;
@end

@interface ORIAUIViewFactory : NSObject<ORIAUIViewSource>
@property (nonatomic, strong) id<ORIAUIViewSource> viewSource;
@property (nonatomic, strong) id<ORIAUIViewSetting> viewSetting;
@property (nonatomic, strong) id<ORIAUIViewDelegate> viewDelegate;

@property (nonatomic, strong, readonly) UIView *backgroundView;
@property (nonatomic, strong, readonly) UIView *reserveView;
@property (nonatomic, strong, readonly) UIView *resolveView;
@property (nonatomic, strong, readonly) UIView *connectView;
@property (nonatomic, strong, readonly) UIView *assistiveButtonView;
@property (nonatomic, strong, readonly) UIView *assistiveMenuView;

- (void)dismissBackgroundView;
- (void)dismissReserveView;
- (void)dismissResolveView;
- (void)dismissConnectView;
- (void)dismissAssistiveButtonView;
- (void)dismissAssistiveMenuView;

- (void)setVoiceChatControlsActive:(BOOL)beActive;
- (void)setVoiceChatSpeakerActive:(BOOL)beActive;
- (void)setVoiceChatMicrophoneActive:(BOOL)beActive;

@end
