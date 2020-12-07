//
//  FGCmdPackage.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FGCmdPackage : NSObject

/** 命令是否完毕 */
@property (nonatomic, assign) BOOL cmdEnd;
/** 命令码 */
@property (nonatomic, assign) uint8_t cmd;
/** 命令描述 */
@property (nonatomic, copy) NSString *cmdDescription;
/** 参数 */
@property (nonatomic, strong) NSMutableData *param;

@end

NS_ASSUME_NONNULL_END
