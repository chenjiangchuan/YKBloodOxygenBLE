//
//  FGSpeedModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGSpeedModel : FGBaseModel

/** 当前脉冲计数，即轮子转数。（瞬时）【4】 */
@property (nonatomic, assign) uint8_t revolution;
/** 行驶速度(单位：KM/h)【5】 */
@property (nonatomic, assign) uint8_t speed;
/**
 系统错误代码 【6】
 
 @note:
 
 常用状态值：
 0x01:启动中
 0x02：电机锁定
 0x03：踏板切换
 0x07:充电中
 0x08:电池电量过低
 0x09:电机极限
 0x0a：驱动板温度过高
 0x0b:温度过高
 0x0d：驱动损坏
 0x0e：超速
 0x0f:驱动板严重过温
 0x10:运行良好
 */
@property (nonatomic, assign) uint8_t code;

/**
 陀螺仪状态:【7】
 
 @note:
 0x0:水平
 0x1:向前
 0x2:向后
 
 */
@property (nonatomic, assign) uint8_t gyroscope_status;

/**
 转向状态：【8】
 
 @note:
 0x0:正常
 0x1：向右转
 0x2：向左转
 */
@property (nonatomic, assign) uint8_t turn_direction;

+ (FGSpeedModel *)analyzWithData:(uint8_t *)bytes;

@end

NS_ASSUME_NONNULL_END
