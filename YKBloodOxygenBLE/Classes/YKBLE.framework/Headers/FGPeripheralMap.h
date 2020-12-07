//
//  FGPeripheralMap.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "FGPeripheral.h"
NS_ASSUME_NONNULL_BEGIN

@interface FGPeripheralMap : NSObject

/**
 创建单例
 
 @return 单例
 */
+ (FGPeripheralMap *)sharedMap;

/**
 根据设备获取设备名
 
 @param peripheral 设备对象
 @return 设备名
 */
- (NSString *)getLocalNameWithPeripheral:(CBPeripheral *)peripheral;

/**
 设置对象对应的设备名
 
 @param localName 设备名
 @param peripheral 设备对象
 */
- (void)setLocalName:(NSString *)localName peripheral:(CBPeripheral *)peripheral;

/**
 清除Map
 */
- (void)destoryMap;

@end

NS_ASSUME_NONNULL_END
