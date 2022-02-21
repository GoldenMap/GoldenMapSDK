//
//  GHSearch.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/8/31.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHGeometry.h"
#import "GHOverlay.h"

typedef enum
{
    GHSearchModeEqual = 1,  ///全匹配
    GHSearchModeContains,   ///包含
} GHSearchMode;///搜索模式

//单元层layer
extern NSString *const LAYER_ID_SPACE;
//公共设施layer
extern NSString *const LAYER_ID_POI;
//装饰层layer
extern NSString *const LAYER_ID_DECFACE;


/**
 地图元素搜索
 */
@interface GHSearch : NSObject

/**
 获取指定楼层的全部数据层

 @param floorName 楼层明显
 @return 数据层名称数组
 */
+ (NSArray *)getDataLayersInFloor:(NSString *)floorName;

/**
 获取全部楼层的全部数据层

 @return 数据层名称数组
 */
+ (NSArray *)getDataLayersInBuilding;

/**
 在指定楼层内通过坐标搜索

 @param layerID 数据层唯一标示
 @param floorName 楼层名称
 @param point 坐标
 @return 数组
 */
+ (GHSearchResult *)search:(NSString *)layerID inFloor:(NSString *)floorName point:(GHPoint)point;

/**
 在全部楼层内通过坐标搜索

 @param layerID 数据层唯一标示
 @param point 坐标
 @return 数组
 */
+ (NSArray *)searchInBuilding:(NSString *)layerID point:(GHPoint)point;

/**
 在当前楼层内通过坐标搜索

 @param layerID 数据层唯一标示
 @param point 坐标
 @return 数组
 */
+ (GHSearchResult *)searchInCurrentFloor:(NSString *)layerID point:(GHPoint)point;

/**
 在指定楼层内通过关键字搜索

 @param layerID 数据层唯一标示
 @param floorName 楼层名称
 @param keyword 关键字
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)search:(NSString *)layerID inFloor:(NSString *)floorName keyword:(NSString *)keyword searchMode:(GHSearchMode)mode;

/**
 在全部楼层内通过关键字搜索

 @param layerID 数据层唯一标示
 @param keyword 关键字
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)searchInBuilding:(NSString *)layerID keyword:(NSString *)keyword searchMode:(GHSearchMode)mode;

/**
 在指定楼层内通过code查询

 @param layerID 数据层唯一标示
 @param floorName 楼层名称
 @param code 用户自定字段
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)search:(NSString *)layerID inFloor:(NSString *)floorName code:(NSString *)code searchMode:(GHSearchMode)mode;

/**
 在全部楼层内通过code搜索

 @param layerID 数据层唯一标示
 @param code 用户自定字段
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)searchInBuilding:(NSString *)layerID code:(NSString *)code searchMode:(GHSearchMode)mode;


/**
 在指定楼层内、指定范围内通过关键字搜索

 @param layerID 数据层唯一标示
 @param floorName 楼层名称
 @param keyword 关键字
 @param point 坐标
 @param radius 半径（米）
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)search:(NSString *)layerID inFloor:(NSString *)floorName keyword:(NSString *)keyword point:(GHPoint)point radius:(float)radius search:(GHSearchMode)mode;

/**
 在当前楼层指定数据层、指定字段通过关键字查询

 @param layerID 数据层唯一标示
 @param fieldName 字段
 @param keyword 关键字
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)searchInCurrentFloor:(NSString *)layerID fieldName:(NSString *)fieldName keyword:(NSString *)keyword searchMode:(GHSearchMode)mode;

/**
 在指定楼层指定数据层、指定字段通过关键字查询

 @param layerID 数据层唯一标示
 @param floorName 楼层名称
 @param fieldName 字段
 @param keyword 关键字
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)search:(NSString *)layerID inFloor:(NSString *)floorName fieldName:(NSString *)fieldName keyword:(NSString *)keyword searchMode:(GHSearchMode)mode;

/**
 在全部楼层指定数据层、指定字段通过关键字查询

 @param layerID 数据层唯一标示
 @param fieldName 字段
 @param keyword 关键字
 @param mode 搜索模式
 @return 数组
 */
+ (NSArray *)searchInBuilding:(NSString *)layerID fieldName:(NSString *)fieldName keyword:(NSString *)keyword searchMode:(GHSearchMode)mode;

/**
 检查单击的坐标是否在楼层内

 @param screenPoint 屏幕坐标
 @param floorName 楼层名称
 @return 是否在楼层内
 */
+ (BOOL)checkPointInFloor:(GHPoint)screenPoint floorName:(NSString *)floorName;

/**
 检查单击的坐标是否在当前楼层内

 @param screenPoint 屏幕坐标
 @return 是否在楼层内
 */
+ (BOOL)checkPointInCurrentFloor:(GHPoint)screenPoint;

/**
搜索最近的通行POI，并按距离目标坐标的距离由近到远进行排序

@param fromFloorName 起始楼层
@param toFloorName 目标楼层
@param targetPoint 目标坐标
@return 通行POI数组
*/
+ (NSArray *)searchPassPoi:(NSString *)fromFloorName toFloorName:(NSString *)toFloorName targetPoint:(GHPoint)targetPoint;
@end
