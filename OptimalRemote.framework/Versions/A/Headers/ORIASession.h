/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, ORIASessionError) {
	ORIASessionErrorRevokeFailure,
	ORIASessionErrorCancelFailure,
	ORIASessionErrorReserveFailure,
	ORIASessionErrorResolveFailure,
	ORIASessionErrorResolveFailureByExpired,
	ORIASessionErrorAcceptFailure,

	ORIASessionErrorCreateDescriptionFailure,
	ORIASessionErrorCreateRemoteConnectionFailure,
	ORIASessionErrorRemoteConnectionFailure,
};

typedef enum ORIASessionRemoteControlOperation {
	ORIASessionRemoteControlOperationAccept,
	ORIASessionRemoteControlOperationDecline,
	ORIASessionRemoteControlOperationAbort,
} ORIASessionRemoteControlOperation;

typedef enum ORIASessionVoiceChatStatus {
	ORIASessionVoiceChatStatusNone,
	ORIASessionVoiceChatStatusHandshaking,
	ORIASessionVoiceChatStatusReady,
	ORIASessionVoiceChatStatusConnecting,
	ORIASessionVoiceChatStatusConnected,
	ORIASessionVoiceChatStatusNotAvailable,
	ORIASessionVoiceChatStatusDisconnected,
	ORIASessionVoiceChatStatusError,
} ORIASessionVoiceChatStatus;

@protocol ORIASessionDelegate;

@interface ORIASession : NSObject

#pragma mark - Constructors
+ (instancetype)sessionForProfile:(NSString *)profile signedBy:(NSString *)key;

- (void)loadDefaultPointerImages;

- (BOOL)open;
- (BOOL)close;
- (BOOL)shutdown;
- (void)resume;
- (void)pause;

- (void)acceptRemoteConnection;

- (BOOL)canOperateRemoteControl:(ORIASessionRemoteControlOperation)operation;
- (BOOL)acceptRemoteControl:(BOOL)acceptsPermanently;
- (BOOL)declineRemoteControl;
- (BOOL)abortRemoteControl;

- (void)setSpeakerActive:(BOOL)beActive;
- (void)setMicrophoneActive:(BOOL)beActive;

#pragma mark - Properties
@property (nonatomic, strong) id<ORIASessionDelegate> delegate;

@property (nonatomic) NSUInteger remoteConnectionRetryIntervalMillis;
@property (nonatomic) NSUInteger remoteConnectionRetryCount;
@property (nonatomic) NSUInteger remoteConnectionSipTimeoutMillis;
@property (nonatomic) NSUInteger remoteConnectionTotalTimeoutMillis;

@property (nonatomic, readonly) BOOL remoteConnectionWorking;
@property (nonatomic, readonly) BOOL remoteConnectionHasEstablished;
@property (nonatomic) BOOL remoteInputEnabled;
@property (nonatomic) BOOL remoteInputAcceptsAutomaticallyEnabled;

@property (nonatomic) CGFloat pointerImageAlpha;
@property (nonatomic, strong) UIImage *pointerImageForNormal;
@property (nonatomic, strong) UIImage *pointerImageForGood;

#pragma mark Voice Chat Properties
@property (nonatomic) BOOL voiceChatEnabled;
@property (nonatomic) BOOL voiceChatOverridesSpeakerWhenNoHeadphones;

@end


@protocol ORIASessionDelegate <NSObject>
@required
- (void)oriaSessionDidReserve:(ORIASession *)session by:(NSString *)ticket;
- (void)oriaSessionShouldDismissTicket:(ORIASession *)session;
- (void)oriaSessionDidNeedAccept:(ORIASession *)session from:(NSString *)peerName;
- (void)oriaSessionDidFailByNotReachable:(ORIASession *)session;
- (void)oriaSessionDidFail:(ORIASession *)session with:(NSError *)error;
@optional
- (void)oriaSessionDidOpen:(ORIASession *)session;
- (void)oriaSessionWillConnect:(ORIASession *)session;
- (void)oriaSessionDidConnect:(ORIASession *)session;
- (void)oriaSessionDidClose:(ORIASession *)session by:(BOOL)sessionHasNotClosedGracefully;
- (void)oriaSessionWillProgress:(ORIASession *)session;
- (void)oriaSessionDidProgress:(ORIASession *)session;
- (void)oriaSessionDidKeepAlive:(ORIASession *)session;
- (void)oriaSessionShouldUpdateRemoteControlStatus:(ORIASession *)session;
- (void)oriaSessionDidRequestRemoteControl:(ORIASession *)session temporally:(BOOL)temporally;
- (void)oriaSessionShouldDismissRemoteControlConfirmation:(ORIASession *)session;
- (void)oriaSessionDidReceiveURL:(ORIASession *)session urlString:(NSString *)urlString;
- (void)oriaSessionWillConnectVoiceChat:(ORIASession *)session;
- (void)oriaSessionDidConnectVoiceChat:(ORIASession *)session;
- (void)oriaSessionShouldEnableVoiceChatControls:(ORIASession *)session;
- (void)oriaSessionShouldDisableVoiceChatControls:(ORIASession *)session;
- (void)oriaSessionDidChangeSpeakerActive:(ORIASession *)session beActive:(BOOL)beActive;
- (void)oriaSessionDidSetMicrohponeEnabled:(ORIASession *)session enabled:(BOOL)enabled;
@end
