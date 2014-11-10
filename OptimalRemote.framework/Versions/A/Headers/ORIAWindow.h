/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import <UIKit/UIKit.h>

@interface ORIAView : UIView

#pragma mark - Properties
@property (nonatomic) BOOL throughUserInteractionEnabled;

@end

@interface ORIAWindow : UIWindow

+ (UIView *)prepareContainer:(UIView *)parent;

#pragma mark - Constructors
+ (instancetype)windowAtLevel:(UIWindowLevel)level;
+ (instancetype)windowOverNormal;
+ (instancetype)windowOverNormal:(UIWindowLevel)leadingLevel;
+ (instancetype)windowUnderAlert;
+ (instancetype)windowUnderAlert:(UIWindowLevel)trailingLevel;

#pragma mark - Public Methods
- (void)setOrientation;
- (void)setOrientation:(UIInterfaceOrientation)orientation;
- (void)setOrientation:(UIInterfaceOrientation)orientation withDuration:(NSTimeInterval)duration;

#pragma mark - Class Methods
+ (void)setOrientation:(UIInterfaceOrientation)orientation withDuration:(NSTimeInterval)duration;

#pragma mark - Properties
@property (nonatomic) BOOL throughUserInteractionEnabled;
@property (nonatomic) BOOL rotatesSubviewsOnSetOrientation;

@end
