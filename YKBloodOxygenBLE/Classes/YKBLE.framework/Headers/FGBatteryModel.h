//
//  FGBatteryModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
#import "FGTimeModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGBatteryModel : FGBaseModel
/** 电量【2-3】 */
@property (nonatomic, assign) uint16_t battery;
/** 当前电量可以使用时间(根据电量计算得出) */
@property (nonatomic, strong) FGTimeModel *validTime;
/** 充电状态【4】 */
@property (nonatomic, assign) uint8_t status;

+ (FGBatteryModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END
