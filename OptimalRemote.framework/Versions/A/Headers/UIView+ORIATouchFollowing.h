/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import <UIKit/UIKit.h>

@interface UIView (ORIATouchFollowing)

- (void)addTapRecognizer:(void (^)(UITapGestureRecognizer *gestureRecognizer))block;

- (void)enableTouchFollowing;
- (void)enableTouchFollowingForRotation;
- (void)setCenterInSuperviewBounds;
- (void)setCenterInSuperviewBoundsWithDuration:(NSTimeInterval)duration;

@end
