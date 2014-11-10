/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import <UIKit/UIKit.h>

@interface UIView (ORIALayout)

- (NSLayoutConstraint *)constraintForPinToParent:(UIView *)parent left:(CGFloat)space;
- (NSLayoutConstraint *)constraintForPinToParent:(UIView *)parent top:(CGFloat)space;
- (NSLayoutConstraint *)constraintForPinToParent:(UIView *)parent right:(CGFloat)space;
- (NSLayoutConstraint *)constraintForPinToParent:(UIView *)parent bottom:(CGFloat)space;
- (NSLayoutConstraint *)constraintForCenterXToParent:(UIView *)parent;
- (NSLayoutConstraint *)constraintForCenterYToParent:(UIView *)parent;

- (void)pinToParent:(UIView *)parent left:(CGFloat)space;
- (void)pinToParent:(UIView *)parent top:(CGFloat)space;
- (void)pinToParent:(UIView *)parent right:(CGFloat)space;
- (void)pinToParent:(UIView *)parent bottom:(CGFloat)space;

- (void)pinToParent:(UIView *)parent leftTop:(CGPoint)space;
- (void)pinToParent:(UIView *)parent leftBottom:(CGPoint)space;
- (void)pinToParent:(UIView *)parent rightTop:(CGPoint)space;
- (void)pinToParent:(UIView *)parent rightBottom:(CGPoint)space;

- (void)pinToParent:(UIView *)parent leftRight:(CGFloat)space;
- (void)pinToParent:(UIView *)parent topBottom:(CGFloat)space;

- (void)centerXToParent:(UIView *)parent;
- (void)centerYToParent:(UIView *)parent;
- (void)centerToParent:(UIView *)parent;

- (void)snapToParent:(UIView *)parent left:(CGPoint)space;
- (void)snapToParent:(UIView *)parent top:(CGPoint)space;
- (void)snapToParent:(UIView *)parent bottom:(CGPoint)space;
- (void)snapToParent:(UIView *)parent right:(CGPoint)space;

- (void)pinToView:(UIView *)view parent:(UIView *)parent above:(CGFloat)space;
- (void)pinToView:(UIView *)view parent:(UIView *)parent below:(CGFloat)space;

- (void)fitSizeToSuperview;

@end
