/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import "OptimalRemote/ORIASessionController.h"

@protocol ORIAUIBackgroundViewSetting <NSObject>
- (UIView *)createBackgroundBanner:(UIView *)parent;
- (UIButton *)createCancelButtonOn:(UIView *)parent;
- (void)backgroundView:(UIView *)parent setPositionOf:(UIView *)banner cancelButton:(UIButton *)cancelButton;
@end

@protocol ORIAUIReserveViewSetting <NSObject>
- (UIView *)createReserveProgressView:(UIView *)parent;
- (UIView *)createReserveMessageLabel:(UIView *)parent;
- (void)reserveView:(UIView *)parent setPositionOf:(UIView *)progressView messageLabel:(UIView *)messageLabel;
@end

@protocol ORIAUIResolveViewSetting <NSObject>
- (UIView *)createResolveTicketLabel:(UIView *)parent ticket:(NSString *)ticket;
- (UIView *)createResolveMessageLabel:(UIView *)parent;
- (void)resolveView:(UIView *)parent setPositionOf:(UIView *)ticketLabel messageLabel:(UIView *)messageLabel;
@end

@protocol ORIAUIConnectViewSetting <NSObject>
- (UIView *)createConnectProgressView:(UIView *)parent;
- (UIView *)createConnectMessageLabel:(UIView *)parent reconnecting:(BOOL)reconnecting;
- (void)connectView:(UIView *)parent setPositionOf:(UIView *)progressView messageLabel:(UIView *)messageLabel;
@end

@protocol ORIAUIAssistiveButtonViewSetting <NSObject>
- (UIView *)createAssistiveBalloon:(UIView *)parent;
- (UIButton *)createAssistiveButton:(UIView *)parent;
- (void)assistiveButtoView:(UIView *)parent setPositionOf:(UIView *)balloon button:(UIButton *)button;
@end

@protocol ORIAUIAssistiveMenuViewSetting <NSObject>
- (UIView *)createAssistiveMenuPanel:(UIView *)parent;
- (UIButton *)getSpeakerButton;
- (UIButton *)getMuteButton;
- (UIButton *)getDisconnectButton;
- (void)showAssistiveMenu:(CGPoint)center animations:(void (^)(void))animations completion:(void (^)(void))completion;
- (void)hideAssistiveMenu:(CGPoint)center animations:(void (^)(void))animations completion:(void (^)(void))completion;
@end

@protocol ORIAUIAlertViewSetting <NSObject>
- (UIAlertView *)createCancelConfirmationDialog;
- (UIAlertView *)createNotReachableDialog;
- (UIAlertView *)createConnectionConfirmationDialog:(NSString *)peerName;
- (UIAlertView *)createFatalErrorDialog:(NSError *)error;
- (UIAlertView *)createConnectionFailureDialog;
- (UIAlertView *)createReconnectConfirmationDialog;
- (UIAlertView *)createRemoteControlConfirmationDialog:(BOOL)temporally;
- (UIAlertView *)createDisconnectConfirmationDialog;
- (UIAlertView *)createCancelIndicatorDialog;
- (UIAlertView *)createAcceptIndicatorDialog;
- (UIAlertView *)createDeclineIndicatorDialog;
- (UIAlertView *)createDisconnectIndicatorDialog;
@end

@interface ORIAUIViewSettings : NSObject<ORIAUIViewSetting, ORIASessionControllerAlertDelegate>
@property (nonatomic, strong) id<ORIAUIBackgroundViewSetting> backgroundViewSetting;
@property (nonatomic, strong) id<ORIAUIReserveViewSetting> reserveViewSetting;
@property (nonatomic, strong) id<ORIAUIResolveViewSetting> resolveViewSetting;
@property (nonatomic, strong) id<ORIAUIConnectViewSetting> connectViewSetting;
@property (nonatomic, strong) id<ORIAUIAssistiveButtonViewSetting> assistiveButtonViewSetting;
@property (nonatomic, strong) id<ORIAUIAssistiveMenuViewSetting> assistiveMenuViewSetting;
@property (nonatomic, strong) id<ORIAUIAlertViewSetting> alertViewSetting;
@end

@interface ORIAUIDefaultMessageLabelFactory : NSObject
- (UILabel *)createMessageLabel:(NSString *)text;
@property (nonatomic) CGFloat fontSizeMultiplierForiPad;
@end
