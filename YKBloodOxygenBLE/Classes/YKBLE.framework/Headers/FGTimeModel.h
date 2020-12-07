//
//  FGTimeModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FGTimeModel : NSObject
/** 天 */
@property (nonatomic, assign) uint8_t day;
/** 时 */
@property (nonatomic, assign) uint8_t hour;
/** 分 */
@property (nonatomic, assign) uint8_t minute;
/** 秒 */
@property (nonatomic, assign) uint8_t second;

@end

NS_ASSUME_NONNULL_END

