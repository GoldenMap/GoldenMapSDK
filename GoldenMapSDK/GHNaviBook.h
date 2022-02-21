//
//  GHNaviBook.h
//  GoldenMap
//
//  Created by YaNan_L on 2018/4/18.
//  Copyright © 2018年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHGeometry.h"
#import "GHLinkResult.h"

@interface GHNaviBook : NSObject

/**
 定位点
 */
@property (nonatomic,assign) GHPoint point;

/**
 楼层名称
 */
@property (nonatomic,strong) NSString *floorName;

/**
 当前路段剩余距离
 */
@property (nonatomic,assign) double distance;

/**
 全部路程剩余距离
 */
@property (nonatomic,assign) double remainDistance;

/**
 当前路线角度
 */
@property (nonatomic,assign) float angle;

/**
 下一个路口描述
 */
@property (nonatomic,assign) GHDirection nextDirection;

/**
 下一个楼层名称
 */
@property (nonatomic,strong) NSString *nextFloorName;

/**
 * 1 步行梯 2 直梯 3 扶梯 5 货梯 9 其他
 */
@property (nonatomic,assign) GHLinkType nextNaviLinkType;       //下一个路口通行类型

/**
 描述
 */
@property (nonatomic,strong) NSMutableString *desc;

/**
 路口放大图
 */
@property (nonatomic,strong) UIImageView *image;

/**
 下一条路书
 */
@property (nonatomic,strong) GHNaviBook *nextNaviBook;

/**
 路口坐标点
 */
@property (nonatomic,assign) GHPoint roadCrossPoint;

/**
 上次路口坐标点
 */
@property (nonatomic,assign) GHPoint preCrossPoint;

/**
 左转右转角度
 */
@property (nonatomic,assign) float roadCrossAngle;

/**
 是否在前进
 */
@property (nonatomic,assign) BOOL isGoAhead;

/**
 走过的距离
 */
@property (nonatomic,assign) float passDistance;

@property (nonatomic,strong) NSArray<__kindof GHLinkResult *> *linkResultList;

/**
 当前路段走过的距离
 */
@property (nonatomic,assign) double curPassedDistance;

/**
 到达途经点index，-1未到达途经点
 */
@property (nonatomic,assign) int wayPointIndex;

/**
 通行类型 0：人行 1：车行
 */
@property (nonatomic,assign) int routeType;

@end
