//
//  GHRouteBook.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/6/30.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHGeometry.h"
#import "GHLinkResult.h"

@class GHRouteBookItem;

@interface GHRouteBook : NSObject

/*!
 @property
 @abstract 状态,-1:起点为空 -2:终点为空 -3:没有设置开始楼层 -4:没有设置终点楼层 1:路径规划成功
 */
@property (nonatomic,assign) int state;

/**
 * 总长度
 */
@property (nonatomic,assign) double distance;
/**
 * 全程描述
 */
@property (nonatomic,assign) NSString *distanceDesc;
/**
 * 路书列表
 */
@property (nonatomic,strong) NSArray<__kindof GHRouteBookItem *> *items;


@property (nonatomic,strong) NSArray<__kindof GHLinkResult *> *linkResultList;

@end

@interface GHRouteItem : NSObject<NSCopying,NSMutableCopying>

/**
 *   坐标点
 */
@property (nonatomic,assign) GHPoint point;

/**
 楼层名称
 */
@property (nonatomic,strong) NSString *floorName;

/**
 * 长度
 */
@property (nonatomic,assign) float length;
/**
 * 方向 1正北 ，2东北 ，3正东 ，4东南 ，5正南 ，6西南 ，7正西 ，8西北 11左 ，12右 13上 ，14下，只针对通行POI
 */
@property (nonatomic,assign) GHDirection direction;
/**
 * 1 步行梯 2 直梯 3 扶梯 5 货梯 9 其他
 */
@property (nonatomic,assign) GHLinkType linkType;

@property (nonatomic,assign) float betAngle;

@end

@interface GHRouteBookItem : NSObject<NSCopying,NSMutableCopying>
/**
 * 路书描述
 */
@property (nonatomic,strong) NSString *desc;
/**
 * 路书项
 */
@property (nonatomic,strong) GHRouteItem *item;

@end
