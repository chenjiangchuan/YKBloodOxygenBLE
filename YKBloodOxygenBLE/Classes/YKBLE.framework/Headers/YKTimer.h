//
//  YKTimer.h
//  YKBracelet
//
//  Created by winson on 2019/11/11.
//  Copyright © 2019 xhx. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 @note
 定时器开启时只能暂停和关闭
 定时器关闭时只能重新开启
 定时器暂停时只能恢复
 定时器恢复时只能暂停和关闭
 */
typedef NS_ENUM(NSInteger,YKTimerStatus) {
    YKTimerStatusIng,       //开启
    YKTimerStatusSuspend,   //暂停
    YKTimerStatusStop,      //关闭
};

@interface YKTimer : NSObject
/** 当前状态 */
@property (nonatomic, assign) YKTimerStatus status;

/**
 开始定时器
 
 @param interval 时间戳
 @param block 回调
 */
- (void)startTimerWithInterval:(float)interval block:(void(^)(BOOL result))block;

- (void)startTimerWithStart:(float)start interval:(float)interval block:(void (^)(BOOL))block;
/**
 恢复
 */
- (void)resume;

/**
 暂停
 */
- (void)suspend;

/**
 关闭
 */
- (void)stopTimer;

@end

NS_ASSUME_NONNULL_END
