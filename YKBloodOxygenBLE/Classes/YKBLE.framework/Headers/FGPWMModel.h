//
//  FGPWMModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGPWMModel : FGBaseModel
/** 行驶平衡值 【4-5】*/
@property (nonatomic, assign) uint16_t run_value;
/** 自平衡值 【6-7】*/
@property (nonatomic, assign) uint16_t balancing_value;
/** 行驶准值调节 【8-9】*/
@property (nonatomic, assign) uint16_t run_collimator;
/** 行驶方向值 【11-12】 */
@property (nonatomic, assign) uint16_t run_deriction;

+ (FGPWMModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END

