//
//  FGLockStatusModel.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGBaseModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGLockStatusModel : FGBaseModel
/** 锁状态【2】
 @note:
 5:解锁成功
 6:解锁失败
 7:锁车成功
 */
@property (nonatomic, assign) uint8_t lock_status;

+ (FGLockStatusModel *)analyzWithData:(uint8_t *)bytes;
@end

NS_ASSUME_NONNULL_END
