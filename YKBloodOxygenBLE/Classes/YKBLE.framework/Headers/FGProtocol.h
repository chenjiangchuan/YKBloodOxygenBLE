//
//  FGProtocol.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "FGBaseModel.h"
#import "FGImport.h"

NS_ASSUME_NONNULL_BEGIN

@interface FGProtocol : NSObject

/**
 修改设备名的命令封装
 
 @param name 需要修改成设备名
 @return 命令
 */
- (NSData *)changeDeviceNameCmdWith:(NSString *)name;

/**
 获取设备当前状态命令封装
 
 @return 命令
 */
- (NSData *)getDeviceStatus;
/**
 解析蓝牙返回的数据
 
 @param peripheral 设备
 @param characteristic 特征
 @param error 错误信息
 @return 解析完成的model
 */
- (FGBaseModel *)peripheral:(CBPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

/**
 解析监听到的蓝牙数据
 
 @param peripheral 设备
 @param characteristic 特征
 @param error 错误信息
 @return 解析完成的model
 */
- (FGBaseModel *)peripheral:(CBPeripheral *)peripheral didUpdateNotificationStateForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
