//
//  FGBLEManager.h
//  YKBracelet
//
//  Created by winson on 2019/9/27.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <YKBLE/FGDefinitions.h>
#import <YKBLE/FGImport.h>
#import <YKBLE/FGBaseModel.h>
#import <YKBLE/FGPeripheral.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FGBLEManagerDelegate <NSObject>

@optional

/// 收到mac地址设备的心率数据
/// @param heardRate 心率
/// @param mac 设备的mac地址
- (void)didReceivedHeartRate:(int)heardRate ofMac:(NSString *)mac;

/// 收到mac地址设备的血氧和体温数据
/// @param bloodOx 血氧
/// @param temperature 体温
/// @param mac 设备的mac地址
- (void)didReceivedBloodOx:(int)bloodOx temperature:(int)temperature ofMac:(NSString *)mac;

/// 收到mac地址设备的电量和PI数据
/// @param battery 电量
/// @param PI PI
/// @param mac 设备的mac地址
- (void)didReceivedBattery:(int)battery PI:(float)PI ofMac:(NSString *)mac;

/// 匹配设备结果
/// @param peripheral 匹配的设备
/// @param RSSI RSSI
/// @param error 错误信息
- (void)didDiscoverMatchPeripheral:(FGPeripheral *)peripheral RSSI:(NSNumber *)RSSI withError:(FGOperationError)error;

/**
 蓝牙状态更改回调函数
 
 @param from 上一个状态
 @param to  当前状态
 */
- (void)blueToothManagerStatusFrom:(FGBlueToothStatus)from
                                to:(FGBlueToothStatus)to;

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

@protocol FGBLEManagerDataSource <NSObject>
/**
 发送命令结果返回
 
 @param peripheral 接收命令的设备对象
 @param cmd 当前命令
 @param characteristic 接收命令的设备特征
 @param error 错误信息
 */
- (void)didWriteFinishInPeripheral:(FGPeripheral *)peripheral
                               cmd:(uint8_t)cmd
                 forCharacteristic:(CBCharacteristic *)characteristic
                         withError:(NSError *)error;

/**
 数据回调
 
 @param peripheral 设备对象
 @param characteristic 设备特征
 @param model 解析后的数据模型
 */
- (void)peripheral:(FGPeripheral *)peripheral didUpdateValueForCharacteristic:(CBCharacteristic *)characteristic responseData:(FGBaseModel *)model;

@end

@interface FGBLEManager : NSObject
/** 蓝牙相关 */
@property (nonatomic, weak) id<FGBLEManagerDelegate>delegate;
/** 蓝牙数据相关 */
@property (nonatomic, weak) id<FGBLEManagerDataSource>dataSource;
/** 当前蓝牙状态 */
@property (nonatomic, assign) FGBlueToothStatus status;
/** 当前操作状态 */
@property (nonatomic, assign) FGOperationStatus operation;
/** 是否自动连接重连设备 */
@property (nonatomic, assign) BOOL autoConnect;
/**
 创建单例
 
 @return 单例
 */
+ (FGBLEManager *)shareInstance;

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
 停止搜索
 */
- (void)stopSearch;

/**
 连接设备
 
 @param peripheral 设备对象
 */
- (void)connectDevice:(FGPeripheral *)peripheral;

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
 清空重连列表
 */
- (void)clearHoldPeripheralList;

/**
 修改设备名
 
 @param name 名字
 */
- (void)changeDeviceName:(NSString *)name;

/**
 获取设备当前状态
 */
- (void)getDeviceStatus;

/**
 锁车
 */
- (void)lockBalanceCar;

/**
 开锁
 */
- (void)unlockBalanceCar;

@end

NS_ASSUME_NONNULL_END
