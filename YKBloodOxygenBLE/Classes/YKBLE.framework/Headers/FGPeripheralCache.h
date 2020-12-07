//
//  FGPeripheralCache.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FGPeripheral.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGPeripheralCache : NSObject

/**
 单例
 
 @return 单例
 */
+ (FGPeripheralCache *)cache;

/**
 添加到缓存中
 
 @param peripheral FGPeripheral *
 */
- (void)addToFGPeripheralList:(FGPeripheral *)peripheral;

/**
 根据设备对象获取FGPeripheral *
 
 @param peripheral 设备对象
 @return FGPeripheral *
 */
- (FGPeripheral *)peripheralWithPeripheral:(CBPeripheral *)peripheral;

/**
 清空
 */
- (void)clear;
@end

NS_ASSUME_NONNULL_END

