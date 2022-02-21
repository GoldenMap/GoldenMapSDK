//
//  GHRoutePoint.h
//  GoldenMap
//
//  Created by YaNan_L on 2019/12/13.
//  Copyright © 2019 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHMapView.h"
/**
融合路径规划点
*/
@interface GHRoutePoint : NSObject

/**
 楼层
 */
@property (nonatomic,strong) NSString *floorName;

/**
 路线类型 人行或车行
 */
@property (nonatomic,assign) GHRouteType routeType;

/**
 坐标
 */
@property (nonatomic,assign) GHPoint point;

@end
