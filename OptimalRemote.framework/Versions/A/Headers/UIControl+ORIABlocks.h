/*
 * Copyright (c) 2014 OPTiM CORPORATION. (http://www.optim.co.jp/)
 * Permission to use, copy, modify and redistribute are strongly controlled
 * under the rights of OPTiM CORPORATION.
 */

#import <UIKit/UIKit.h>

@interface UIControl (ORIABlocks)

- (void)addTarget:(UIControlEvents)event block:(void (^)())block;

@end
