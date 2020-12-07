//
//  FGChangeNameModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGChangeNameModel : FGBaseModel
/** 修改结果 */
@property (nonatomic, assign) BOOL success;

/**
 解析
 
 @param bytes 蓝牙数据
 @return FGChangeNameModel *
 */
+ (FGChangeNameModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END
