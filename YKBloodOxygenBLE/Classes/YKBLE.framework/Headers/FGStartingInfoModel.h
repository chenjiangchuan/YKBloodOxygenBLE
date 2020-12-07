//
//  FGStartingInfoModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGStartingInfoModel : FGBaseModel
/** 转向值【2-3】 */
@property (nonatomic, assign) uint16_t turn_value;
/** 加速度值【4-5】 */
@property (nonatomic, assign) uint16_t accelerated_value;

+ (FGStartingInfoModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END
