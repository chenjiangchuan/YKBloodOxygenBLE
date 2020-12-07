//
//  YKViewController.m
//  YKBloodOxygenBLE
//
//  Created by chenjiangchuan on 10/21/2020.
//  Copyright (c) 2020 chenjiangchuan. All rights reserved.
//

#import "YKViewController.h"
#import <YKBloodOxygenBLE/YKBloodOxygenBLE.h>

@interface YKViewController () <FGBLEManagerDelegate>

@end

@implementation YKViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)buttonAction:(id)sender {
    if ([FGBLEManager shareInstance].status != FGBlueToothStatusOn) {
        NSLog(@"蓝牙未开启");
        return;
    }
    [[FGBLEManager shareInstance] searchDevice];
    [FGBLEManager shareInstance].delegate = self;
}

#pragma mark -
#pragma mark - YKBloodOxygenBLEDelagate
- (void)didReceivedHeartRate:(int)heardRate ofMac:(NSString *)mac {
    NSLog(@"心率 = %d， mac地址 = %@", heardRate, mac);
}

- (void)didReceivedBloodOx:(int)bloodOx temperature:(int)temperature ofMac:(NSString *)mac {
    NSLog(@"血氧 = %d, 体温 = %d, mac地址 = %@", bloodOx, temperature, mac);
}

- (void)didReceivedBattery:(int)battery PI:(float)PI ofMac:(NSString *)mac {
    NSLog(@"电量 = %d, PI = %f, mac地址 = %@", battery, PI, mac);
}

- (void)didDiscoverMatchPeripheral:(FGPeripheral *)peripheral RSSI:(NSNumber *)RSSI withError:(FGOperationError)error {
    NSLog(@"name: %@", peripheral.localName);
}

@end
