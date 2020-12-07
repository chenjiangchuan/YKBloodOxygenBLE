//
//  FGMileageModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGMileageModel : FGBaseModel

/** MSB First,总里程,单位：千米【4-7】 */
@property (nonatomic, assign) CGFloat total_mileage;
/** 驱动板温度 【8-9】*/
@property (nonatomic, assign) NSInteger drive_temperature;
/** 电机温度 【10-11】*/
@property (nonatomic, assign) NSInteger machinery_temperature;
/** 当前行驶里程【17-18】 */
@property (nonatomic, assign) CGFloat current_mileage;

+ (FGMileageModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END

