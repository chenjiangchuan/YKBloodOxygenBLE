//
//  FGBaseModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGDefinitions.h"

NS_ASSUME_NONNULL_BEGIN

@interface FGBaseModel : NSObject
/** 数据类型 */
@property (nonatomic, assign) FGMessageType msg_type;
/** 序列号 */
@property (nonatomic, assign) uint8_t serial_num;
/** 参数长度 */
@property (nonatomic, assign) uint8_t param_length;
/** 错误类型 */
@property (nonatomic, assign) FGResponseError error;

+ (int)getIntWithTotal:(uint8_t *)total length:(int)length;

+ (FGBaseModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END
