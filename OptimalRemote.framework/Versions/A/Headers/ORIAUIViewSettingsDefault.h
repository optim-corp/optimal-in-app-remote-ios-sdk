/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import "OptimalRemote/ORIAUIViewSettings.h"

@interface ORIAFontManager : NSObject

- (CGFloat)scaledFontSize:(CGFloat)fontSize;

- (UIFont *)scaledFont;
- (UIFont *)scaledFontWithSize:(CGFloat)fontSize;

@property (nonatomic, strong) UIFont *font;
@property (nonatomic) CGFloat fontSizeScaleForPad;

@end

@interface ORIAUIBackgroundViewSettingDefault : NSObject<ORIAUIBackgroundViewSetting>
@end

@interface ORIAUIReserveViewSettingDefault : NSObject<ORIAUIReserveViewSetting>
@end

@interface ORIAUIResolveViewSettingDefault: NSObject<ORIAUIResolveViewSetting>
@end

@interface ORIAUIConnectViewSettingDefault: NSObject<ORIAUIConnectViewSetting>
@end

@interface ORIAUIAssistiveButtonViewSettingDefault : NSObject<ORIAUIAssistiveButtonViewSetting>
@end

@interface ORIAUIAssistiveMenuViewSettingDefault : NSObject<ORIAUIAssistiveMenuViewSetting>
@end

@interface ORIAUIAlertViewSettingDefault: NSObject<ORIAUIAlertViewSetting>
@end

@interface ORIAUIViewDelegateDefault : NSObject<ORIAUIViewDelegate>
@end

@interface ORIAUISplashWindow : NSObject
+ (void)showWithBlock:(void (^)())blockOnFadeOut;
+ (void)showForCompletion;
@end
