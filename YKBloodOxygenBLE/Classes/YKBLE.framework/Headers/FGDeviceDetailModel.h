//
//  FGDeviceDetailModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGDeviceDetailModel : FGBaseModel
/**
 电机极限【4】
 
 @note:
 0x00:正常
 0x01:异常
 */
@property (nonatomic, assign) uint8_t torq_limit_motor;
/**
 驱动板状态【5】
 @note:
 0x00:已损坏
 0x01:运行ok
 */
@property (nonatomic, assign) uint8_t driver_board_status;

/**
 踏板状态【6】
 
 @note:
 0x0:未踏板
 0x1:已踏板
 */
@property (nonatomic, assign) uint8_t footboard_status;

/**
 电量值【7-8】
 
 @note:
 电池电压：=（电量值*5000）/1024
 */
@property (nonatomic, assign) uint16_t battery;

/**
 设备当前运行时间 【13-16】
 */
@property (nonatomic, assign) uint32_t current_time;

+ (FGDeviceDetailModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END
