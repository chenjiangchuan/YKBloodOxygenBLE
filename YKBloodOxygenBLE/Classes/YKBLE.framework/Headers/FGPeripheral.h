//
//  FGPeripheral.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface FGPeripheral : NSObject<NSCoding>

/** 通过设备对象UDID映射的设备名
 @note：由于iOS蓝牙缓存问题，修改设备名后，搜索出来的还是旧名称，需要重新进行连接通讯才会更新，所以采用设备对象映射设备名称的方式
 */
@property (nonatomic, copy) NSString *localName;
/** 设备对象 */
@property (nonatomic, strong) CBPeripheral *peripheral;
/** 广播数据 */
@property (nonatomic, strong) NSDictionary<NSString *,id> *advertisementData;
/** UUID */
@property (nonatomic, strong) NSUUID *UUID;
/** UUID(字符串) */
@property (nonatomic, copy) NSString *UUIDString;
/** 信号 */
@property(nonatomic, strong) NSNumber *RSSI;


/**
 初始化
 
 @param peripheral 设备对象
 @param advertisementData 广播数据
 @param RSSI 信号
 @return FGPeripheral *
 */
+ (FGPeripheral *)peripheralWithPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary<NSString *,id> *)advertisementData RSSI:(NSNumber *)RSSI;

/**
 根据设备对象获取FGPeripheral
 
 @param peripheral 设备对象
 @return FGPeripheral *
 */
+ (FGPeripheral *)fgperipheralWithPeripheral:(CBPeripheral *)peripheral;
@end

NS_ASSUME_NONNULL_END

