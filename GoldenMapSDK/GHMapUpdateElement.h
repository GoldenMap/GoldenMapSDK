//
//  GHMapUpdateElement.h
//  GoldenMap
//
//  Created by YaNan_L on 2018/4/2.
//  Copyright © 2018年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 地图更新信息类
 */
@interface GHMapUpdateElement : NSObject

/**
 建筑物名称
 */
@property (nonatomic,strong) NSString *buildingName;

/**
 建筑物编号
 */
@property (nonatomic,strong) NSString *buildingNum;

/**
 当前（本地）版本
 */
@property (nonatomic,strong) NSString *localVersion;

/**
 最新（服务器）版本
 */
@property (nonatomic,strong) NSString *lastestVersion;

/**
 最新版本的文件大小
 */
@property (nonatomic,strong) NSString *size;

/**
 最新版本的更新时间
 */
@property (nonatomic,strong) NSString *timeUpdated;

/**
 新版本更新说明
 */
@property (nonatomic,strong) NSString *feature;

@end
