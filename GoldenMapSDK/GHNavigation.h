//
//  GHNavigation.h
//  GoldenMap
//
//  Created by YaNan_L on 2018/4/8.
//  Copyright © 2018年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHMapView.h"
#import "GHNaviBook.h"

typedef enum
{
    GHNaviMode_NORMAL = 1,//正常模式
    GHNaviMode_ROAD,//图随路转
} GHNaviMode;

typedef enum  {
    NO_START_INFO = 1,      //没有起点信息
    NO_END_INFO,        //没有终点信息
    AUTO_ROUTING_START,     //自动算路开始
    AUTO_ROUTING_COMPLETE,  //自动算路结束
    AUTO_ROUTING_ERROR,     //自动算路失败
    ROUTING_START,          //路径规划开始
    ROUTING_COMPLETE,       //路径规划结束
    ROUTING_ERROR,          //路径规划失败
    NAVI_START,             //导航开始
    NAVI_END,               //导航结束
    NAVI_PAUSE,              //导航暂停
    NAVI_RESUME,            //导航重启
    NAVI_TRACKING,           //导航进行中
    NAVI_RESTART            //重新规划导航
} GHNaviResultCode;

/**
 GHNavigation代理方法
 */
@protocol GHNavigationDelegate <NSObject>

/**
 导航回调方法

 @param code 导航状态码
 @param naviBook 路书
 */
- (void)onNavigationCallback:(int)code naviBook:(GHNaviBook *)naviBook;

@end

/**
 导航模块
 */
@interface GHNavigation : NSObject

@property (nonatomic,weak) id delegate;

/**
 导航模式：跟随、图随路转
 */
@property (nonatomic,assign) GHNaviMode naviMode;

/**
 是否自动算路，默认为YES
 */
@property (nonatomic,assign) BOOL autoRoute;

/**
 偏离路线多少米开始重新算路，默认为5米
 */
@property (nonatomic,assign) float threshold;

/**
 最大偏离次数，默认为5次
 */
@property (nonatomic,assign) int maxOffCount;

/**
 剩余距离在这个范围内时 提示导航结束
 */
@property (nonatomic,assign) float endThreshold;

/**
 模拟导航速度
 */
@property (nonatomic,assign) float mockSpeed;

/**
 判定回退的距离，默认为3米
 */
@property (nonatomic,assign) float backThreshold;

/**
 判定回退的次数，默认为3次
 */
@property (nonatomic,assign) int maxBackCount;

/**
 图随路转模式导航时地图切换角度的动画时间
 */
@property (nonatomic,assign) int rotateDuration;

/**
 开始导航
 */
- (void)start;

/**
 暂停
 */
- (void)pause;

/**
 继续
 */
- (void)resume;

/**
 结束
 */
- (void)end;

/**
 传入定位点

 @param point 定位点坐标
 @param floorName 楼层名称
 */
- (void)setLocation:(GHPoint)point floorName:(NSString *)floorName;

/**
 开始模拟导航
 */
- (void)startsSimulateNavi;

@end
