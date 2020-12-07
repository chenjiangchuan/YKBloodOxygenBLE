//
//  FGDefinitions.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//
#import <UIKit/UIKit.h>

#ifndef FGDefinitions_h
#define FGDefinitions_h

#define CMD_SET_BALANCE_DEGREE  (0x90)//设置车平衡度和准直度
#define CMD_SET_BEGINNER_MODE   (0x81)//设置新手模式
#define CMD_SET_MAX_SPEED       (0x82)//设置最大限速值
#define CMD_RESET_PWM           (0x83)//设置PWM值为系统在值（此用于出厂设置，用户不需要）
#define CMD_SET_PWM_DEFAULT     (0x84)//恢复PWM系统默认值
#define CMD_SET_LIGHT_MODE      (0x85)//设置灯光模式
#define CMD_READ_PWM            (0x86)//读取PWM参数
#define CMD_READ_SYS_STATUS     (0x87)//读取系统状态值
#define CMD_LOCK                (0x88)//锁车
#define CMD_UNLOCK              (0x89)//解锁
#define CMD_SET_PEDAL           (0x8a)//设置踏板
#define CMD_SET_DEVICE_NAME     (0x8b)//设置蓝牙名称

#define kHOLDERPERIPHERALKEY    @"holdPeripheral"
//蓝牙名称本地映射开关
#define kMAP_ON 1
typedef NS_ENUM(NSInteger, FGBlueToothStatus) {
    FGBlueToothStatusUnknown,   //未知
    FGBlueToothStatusOn,        //蓝牙开启
    FGBlueToothStatusOff,       //蓝牙关闭
};

typedef NS_ENUM(NSInteger, FGOperationStatus) {
    FGOperationStatusIdle,                  //闲置
    FGOperationStatusScanning,              //扫描中
    FGOperationStatusConnecting,            //连接中
    FGOperationStatusDisConnecting,         //断开连接
    FGOperationStatusSendPackage,           //发送命令
};

typedef NS_ENUM(NSInteger, FGOperationError) {
    FGOperationErrorNon,            //成功
    FGOperationErrorTimeout,        //超时
    FGOperationErrorInner,          //蓝牙内部错误
    FGOperationErrorService,        //发现服务报错
    FGOperationErrorCharacteristics,//特征
    FGOperationErrorOther,          //连上了其他设备或者其他设备断开连接
};

typedef NS_ENUM(NSInteger, FGResponseError) {
    FGResponseErrorNon,     //无错误
    FGResponseErrorHeader,  //包头错误
    FGResponseErrorInner,   //蓝牙内部错误
    FGResponseErrorCheck,   //校验码错误
    FGResponseErrorLength,  //长度错误
    FGResponseErrorOther,   //其他设备返回
    FGResponseErrorDataEmpty,   //返回数据长度为0
};

typedef NS_ENUM(NSInteger, FGMessageType) {
    FGMessageTypeSpeed = 16,  //速度
    FGMessageTypeMileage,     //里程
    FGMessageTypeBattery,     //电池
    FGMessageTypePWM,         //PWM
    FGMessageTypeStatus,      //设备状态
    FGMessageTypeLockStatus,  //当前锁的状态
    FGMessageTypeChangeDevName,//修改设备名称
};

typedef NS_ENUM(NSInteger, FGThirdLoginType) {
    FGThirdLoginTypeFacebook = 1,   //Facebook
    FGThirdLoginTypeTwitter,    //Twitter
};

#ifdef DEBUG

#define FGLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#else

#define  FGLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#endif

#endif /* FGDefinitions_h */
