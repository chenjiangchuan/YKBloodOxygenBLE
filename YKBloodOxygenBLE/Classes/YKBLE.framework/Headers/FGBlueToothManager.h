//
//  FGBlueToothManager.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "FGDefinitions.h"
#import "FGImport.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FGBlueToothManagerDelegate <NSObject>

/**
 蓝牙状态更改回调函数
 
 @param from 上一个状态
 @param to  当前状态
 */
- (void)blueToothManagerStatusFrom:(FGBlueToothStatus)from
                                to:(FGBlueToothStatus)to;

/**
 匹配设备结果
 
 @param peripheral 匹配的设备
 @param advertisementData 广播数据
 @param RSSI RSSI
 @param error 错误信息
 */
- (void)didDiscoverMatchPeripheral:(FGPeripheral *)peripheral
                 advertisementData:(NSDictionary *)advertisementData
                              RSSI:(NSNumber *)RSSI
                         withError:(FGOperationError)error;

/**
 设备已连接
 
 @param peripheral 设备对象
 @param error 错误信息
 */
- (void)didConnectedPeripheral:(FGPeripheral *)peripheral
                         error:(FGOperationError)error;


/**
 设备断开连接
 
 @param periperal 设备对象
 @param error 错误信息
 */
- (void)didDisConnectedPeripheral:(FGPeripheral *)periperal
                            error:(FGOperationError)error;

@end

@protocol FGBlueToothManagerDataDelegate <NSObject>

@optional;
/**
 发送命令结果返回
 
 @param peripheral 接收命令的设备对象
 @param characteristic 接收命令的设备特征
 @param error 错误信息
 */
- (void)didWriteFinishInPeripheral:(FGPeripheral *)peripheral cmd:(uint8_t)cmd
                 forCharacteristic:(CBCharacteristic *)characteristic
                         withError:(NSError *)error;

/**
 数据回调
 
 @param peripheral 设备对象
 @param characteristic 设备特征
 @param error 错误信息
 */
- (void)peripheral:(FGPeripheral *)peripheral
didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic
             error:(NSError *)error;

@end

@interface FGBlueToothManager : NSObject

@property (nonatomic, weak) id <FGBlueToothManagerDelegate>delegate;
@property (nonatomic, weak) id <FGBlueToothManagerDataDelegate>responseDelegate;

/**
 单例
 
 @return FGBlueToothManager对象
 */
+ (instancetype)shareManager;

/**
 搜索设备
 */
- (void)searchDevice;

/**
 搜索指定设备
 
 @param name 设备名
 */
- (void)searchDeviceWithName:(NSString *)name;

/**
 停止扫描
 */
- (void)stopSearch;

/**
 连接设备
 
 @param peripheral 设备对象
 @param isAutoConnect 是否是重连
 */
- (void)connectDevice:(FGPeripheral *)peripheral isAutoConnect:(BOOL)isAutoConnect;

/**
 断开连接
 
 @param peripheral 设备对象
 */
- (void)disConnectDevice:(FGPeripheral *)peripheral;

/**
 添加到重连列表中
 
 @param peripheral 设备对象
 */
- (void)addToHoldPeripheral:(FGPeripheral *)peripheral;

/**
 重连设备
 */
- (void)autoConnectHoldPeripheral;

/**
 取消重连
 */
- (void)cancelAutoConnectHoldPeripheral;

/**
 发送数据
 
 @param data 数据
 */
- (void)sendPackageToCharacteristic:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
