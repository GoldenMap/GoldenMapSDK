//
//  GHMapViewDelegate.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/6/30.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//



#ifndef GHMapViewDelegate_h
#define GHMapViewDelegate_h


#endif /* GHMapViewDelegate_h */

#import "GHGeometry.h"
#import "GHOverlay.h"
#import "GHMapUpdateElement.h"

@protocol GHMapViewDelegate <NSObject>
@optional

/**
 地图加载完成

 @param mapView GHMapView的实例
 */
- (void)onMapLoaded:(id)mapView;

/**
 地图加载失败

 @param mapView GHMapView的实例
 @param error 错误
 */
- (void)onMapLoadFailed:(id)mapView error:(NSError *)error;

/**
 楼层切换事件

 @param mapView GHMapView的实例
 @param fromFloorName 切换前的楼层名称
 @param toFloorName 切换后的楼层名称
 */
- (void)onMapFloorChange:(id)mapView fromFloorName:(NSString *)fromFloorName toFloorName:(NSString *)toFloorName;

/**
 地图点击事件

 @param mapView GHMapView的实例
 @param point 点击的图内坐标点
 */
- (void)mapView:(id)mapView onMapClick:(GHPoint)point screenPoint:(GHPoint)screenPoint;

/**
 地图双击事件

 @param mapView GHMapView的实例
 @param point 双击的图内坐标点
 */
- (void)mapView:(id)mapView onMapDoubleClick:(GHPoint)point;

/**
 地图移动事件

 @param mapView GHMapView的实例
 @param state 手势状态
 */
- (void)mapView:(id)mapView onMapScroll:(UIGestureRecognizerState)state;

/**
 地图长按事件

 @param mapView GHMapView的实例
 @param point 长按的图内坐标点
 */
- (void)mapView:(id)mapView onMapLongPress:(GHPoint)point;

/**
 地图缩放事件

 @param mapView GHMapView的实例
 @param state 手势状态
 */
- (void)mapView:(id)mapView onMapZoom:(UIGestureRecognizerState)state;

/**
 地图旋转事件

 @param mapView GHMapView的实例
 @param state 手势状态
 */
- (void)mapView:(id)mapView onMapRotate:(UIGestureRecognizerState)state;

/**
 地图倾斜事件

 @param mapView GHMapView的实例
 @param state 手势状态
 */
- (void)mapView:(id)mapView onMapPitch:(UIGestureRecognizerState)state;

/**
 marker单击事件

 @param mapView GHMapView的实例
 @param marker GHMarker的实例
 */
- (void)mapView:(id)mapView onMarkerClick:(GHMarker *)marker;

/**
 polygon单击事件

 @param mapView GHMapView的实例
 @param polygon GHPolygon的实例
 */
- (void)mapView:(id)mapView onPolygonClick:(GHPolygon *)polygon;

/**
 line单击事件

 @param mapView GHMapView的实例
 @param line GHLine的实例
 */
- (void)mapView:(id)mapView onLineClick:(GHLine *)line;

#pragma mark - 地图更新回调

/**
 检查地图更新回调方法

 @param mapView GHMapView的实例
 @param updateElement 更新信息实例
 */
- (void)mapView:(id)mapView didCheckComplete:(GHMapUpdateElement *)updateElement;

/**
 检查地图更新失败

 @param mapView GHMapView的实例
 @param error 错误信息
 */
- (void)mapView:(id)mapView didCheckFaild:(NSError *)error;

/**
 下载地图数据成功回调
 
 @param mapView GHMapView的实例
 */
- (void)downloadMapDataComplete:(id)mapView;

/**
 下载地图数据失败回调
 
 @param mapView GHMapView的实例
 @param error 错误信息
 */
- (void)mapView:(id)mapView downloadMapDataFaild:(NSError *)error;

/**
 下载地图数据进度回调
 
 @param mapView GHMapView的实例
 @param progress 进度
 */
- (void)mapView:(id)mapView downloadMapDataProgress:(float)progress;

#pragma mark - 地图动画回调

/**
 动画启动回调

 @param mapView  GHMapView的实例
 */
- (void)onAnimationActive:(id)mapView;

/**
 动画结束回调

 @param mapView  GHMapView的实例
 */
- (void)onAnimationStoped:(id)mapView;

@end
