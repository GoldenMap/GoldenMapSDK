//
//  GHMapView.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/6/29.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GHGeometry.h"
#import "GHMapOptions.h"
#import "GHMapViewDelegate.h"
#import "GHRouteBook.h"
#import "GHRouteOption.h"

typedef enum
{
    GHRouteTypePerson = 1,  /// 人行
    GHRouteTypeVehicle,     /// 车行
} GHRouteType;

@class GHBuilding;

/*!
 @class
 @abstract GHMapView，地图类，使用此View可以显示地图，并对地图进行操作
 */
@interface GHMapView : UIView


/**
 GHMapView的delegate
 */
@property (nonatomic,weak) id<GHMapViewDelegate> delegate;

/**
 地图数据是否自动更新
 */
@property (nonatomic,assign) BOOL mapAutoUpdate;

/**
 地图预置状态
 */
@property (nonatomic,strong) GHMapOptions *mapOptions;

/*!
 @property
 @abstract 地图路径，设置此值加载数据并开始渲染地图。
 */
@property (nonatomic,strong) NSString *mapPath;

/*!
 @property
 @abstract 当前楼层名称，设置此值切换至相应楼层。
 */
@property (nonatomic,strong) NSString *currentFloorName;

/*!
 @property
 @abstract 地图模式，设置此值切换地图模式。
 */
@property (nonatomic,assign) GHMapMode mapMode;

/**
 是否显示精细模型
 */
@property (nonatomic,assign) BOOL showFineModels;

/*!
 @property
 @abstract 地图背景色，设置此值切换地图背景色。
 */
@property (nonatomic,strong) UIColor *backgroundColor;

/*!
 @property
 @abstract 地图建筑物信息。
 */
@property (nonatomic,readonly) GHBuilding *buildingInfo;

/*!
 @property
 @abstract 夜间模式，设置此值切换是否使用夜间模式。
 */
@property (nonatomic,assign) BOOL nightMode;

/*!
 @property
 @abstract 语言，设置此值切换语言。
 */
@property (nonatomic,assign) GHLanguage language;

/*!
 @property
 @abstract POI是否隐藏，设置此值显示/隐藏POI。
 */
@property (nonatomic,assign) BOOL poiVisible;

/**
 是否显示文字标注，默认为显示
 */
@property (nonatomic,assign) BOOL showsLabels;

/*!
 @property
 @abstract 指南针图标，设置此值改变指南针图标。
 */
@property (nonatomic,strong) UIImage *compassImage;

/*!
 @property
 @abstract 点击是否变色。
 */
@property (nonatomic,assign) BOOL changeOnClick;

/*!
 @property
 @abstract 缩放级别。
 */
@property (nonatomic,assign) float zoomLevel;

/*!
 @property
 @abstract 最大缩放级别。
 */
@property (nonatomic,assign) float maxZoomLevel;

/*!
 @property
 @abstract 最小缩放级别。
 */
@property (nonatomic,assign) float minZoomLevel;

/*!
 @property
 @abstract 双击是否放大地图。
 */
@property (nonatomic,assign) BOOL zoomEnabledWithDoubleClick;

/*!
 @property
 @abstract 是否启用缩放手势。
 */
@property (nonatomic,assign) BOOL zoomEnabled;

/*!
 @property
 @abstract 地图旋转角度。
 */
@property (nonatomic,assign) float rotate;

/*!
 @property
 @abstract 是否使用手势旋转地图。
 */
@property (nonatomic,assign) BOOL rotateEnabled;

/*!
 @property
 @abstract 地图倾斜角度。
 */
@property (nonatomic,assign) float pitch;

/*!
 @property
 @abstract 是否使用手势倾斜地图角度。
 */
@property (nonatomic,assign) BOOL pitchEnabled;

/*!
 @property
 @abstract 地图最大倾斜角度，最小为0。
 */
@property (nonatomic,assign) float maxPitch;

/*!
 @property
 @abstract 地图中心点，设置此值可移动地图中心点。
 */
@property (nonatomic,assign) GHPoint mapCenter;

/*!
 @property
 @abstract 是否使用手势平移地图。
 */
@property (nonatomic,assign) BOOL scrollEnabled;

/*!
 @property
 @abstract 长按手势开关。
 */
@property (nonatomic,assign) BOOL longPressEnabled;

/**
 路径优先通行数组（1 2 3 4的NSNumber对象）
 */
@property (nonatomic,strong) NSArray *routePriority;

/**
 类方法，用于设置数据目录和KEY

 @param mapPath 地图数据的存储目录
 @param key key
 */
+ (void)initMapPath:(NSString *)mapPath key:(NSString *)key;

/// 私有化部署设置URL
/// @param url url地址
+ (void)initURL:(NSString *)url;

/**
 清理地图数据

 @param mapNum 地图编号
 */
+ (void)clearMapDataWithMapNum:(NSString *)mapNum;

/**
 获取两点之间的距离

 @param p1
 @param p2
 @return 距离
 */
+ (double)getDistance:(GHPoint)p1 p2:(GHPoint)p2;

/**
 SDK版本

 @return 版本号
 */
- (NSString *)sdkVersion;

/**
 开启地图

 @param mapNum 地图编号
 */
- (void)openMapWithNum:(NSString *)mapNum;

/**
 释放MapView

 @return 返回是否成功。
 */
- (BOOL)releaseMapView;

/**
 MapView生命周期方法，viewWillAppear时调用
 */
- (void)mapViewWillAppear;


/**
 MapView生命周期方法，viewWillDisappear时调用
 */
- (void)mapViewWillDisappear;

/**
 设置是否打印日志

 @param isShowLog 是否打印日志
 */
- (void)setIsShowLog:(BOOL)isShowLog;

/**
 刷新地图
 */
- (void)refresh;

/**
 重新加载地图
 */
- (void)reload;

/**
 显示全部楼层
 */
- (void)showAllFloors:(BOOL)animated;

/**
 取消全部楼层显示
 */
- (void)cancelShowAllFloors:(BOOL)animated;

/**
 平铺全部楼层

 @param animated 是否启用动画
@param orientation 方向，水平或垂直
 */
- (void)tileAllFloors:(BOOL)animated orientation:(GHOrientation)orientation;

/**
 取消平铺全部楼层

 @param animated 是否启用动画
 */
- (void)cancelTileAllFloors:(BOOL)animated;

/**
 设置文字渲染优先

 @param priority 是否优先
 */
- (void)setLabelRenderingPriority:(BOOL)priority;

/**
 设置图层是否隐藏

 @param layerID 图层ID
 @param floorName 楼层名称
 @param hidden 是否隐藏
 */
- (void)setLayerHidden:(NSString *)layerID floorName:(NSString *)floorName hidden:(BOOL)hidden;

/**
 设置显示鹰眼

 @param show 是否显示
 */
- (void)showHawkEye:(BOOL)show;

/**
 获取全部楼层

 @return 全部楼层的字符串数组
 */
- (NSArray *)getFloors;

/**
 通过坐标获取对象

 @param layerID 图层
 @param floorName 楼层名称
 @param point 屏幕坐标
 @param effect 使用效果
 @return GHSearchResult
 */
- (GHSearchResult *)getResultByClick:(NSString *)layerID floorName:(NSString *)floorName screenPoint:(GHPoint)point effect:(BOOL)effect;

/**
 多选图形

 @param layerID 图层名
 @param field 字段
 @param keys 值
 */
- (void)selectMultiPolygons:(NSString *)layerID field:(NSString *)field keys:(NSArray <__kindof NSString *> *)keys;

- (void)selectMultiPolygons:(NSString *)floorName layerID:(NSString *)layerID field:(NSString *)field keys:(NSArray <__kindof NSString *> *)keys;

/**
 清除多选面
 */
- (void)clearSelectedMultiPolygons;

/**
 多选点

 @param layerID 图层名
 @param field 字段
 @param keys 值
 */
- (void)selectMultiPoints:(NSString *)layerID field:(NSString *)field keys:(NSArray <__kindof NSString *> *)keys;

- (void)selectMultiPoints:(NSString *)floorName layerID:(NSString *)layerID field:(NSString *)field keys:(NSArray <__kindof NSString *> *)keys;

/**
 清除多选点
 */
- (void)clearSelectedMultiPoints;

/**
 多选线

 @param layerID 图层名
 @param field 字段
 @param keys 值
 */
- (void)selectMultiLines:(NSString *)layerID field:(NSString *)field keys:(NSArray <__kindof NSString *> *)keys;

- (void)selectMultiLines:(NSString *)floorName layerID:(NSString *)layerID field:(NSString *)field keys:(NSArray <__kindof NSString *> *)keys;

/**
 清除多选线
 */
- (void)clearSelectedMultiLines;

#pragma mark - 地图缩放


/**
 放大一个级别
 */
- (void)zoomIn;

/**
 缩小一个级别
 */
- (void)zoomOut;

/**
 缩放至地图适应屏幕
 */
- (void)zoomToExtent;

/**
 缩放地图至特定级别

 @param box 包围盒
 @param margin 边距
 */
- (void)zoomToBox:(GHBox)box margin:(GHMargin)margin;

/**
 设置地图缩放级别，可选使用动画

 @param zoomLevel 地图级别
 @param animated 是否启用动画
 */
- (void)setZoomLevel:(float)zoomLevel animated:(BOOL)animated;


#pragma mark - 地图旋转

/**
 设置地图角度，可选使用动画

 @param rotate 角度
 @param animated 是否使用动画
 */
- (void)setRotate:(float)rotate animated:(BOOL)animated;

/**
 重置地图角度，可选使用动画

 @param animated 是否使用动画
 */
- (void)resetRotateWithAnimated:(BOOL)animated;

/**
 设置地图倾斜角度，可选使用动画

 @param pitch 倾斜角度
 @param animated 是否使用动画
 */
- (void)setPitch:(float)pitch animated:(BOOL)animated;

/**
 设置地图中心点，可选使用动画

 @param mapCenter 中心点
 @param animated 是否使用动画
 */
- (void)setMapCenter:(GHPoint)mapCenter animated:(BOOL)animated;

/**
 设置地图中心点、缩放级别，可选使用动画

 @param mapCenter 地图中心点
 @param zoomLevel 缩放级别
 @param animated 是否使用动画
 */
- (void)setMapCenter:(GHPoint)mapCenter zoomLevel:(float)zoomLevel animated:(BOOL)animated;

#pragma mark - 覆盖物

/**
 通过自定义字段匹配polygon图形，然后修改它显示的文字，颜色，边线颜色。

 @param layerID 图层ID
 @param fieldName 字段名称
 @param keyword 关键字
 @param text 文字
 @param color 颜色
 @param borderColor 边线颜色
 */
- (void)setPolygon:(NSString *)layerID fieldName:(NSString *)fieldName keyword:(NSString *)keyword text:(NSString *)text color:(UIColor *)color borderColor:(UIColor *)borderColor;

/**
 弹出自定义视图

 @param view 自定义视图
 @param point 地图坐标
 */
- (void)popUpView:(UIView *)view point:(GHPoint)point;


/**
 移除自定义视图

 @param view 自定义视图
 */
- (void)dismissView:(UIView *)view;

/**
 添加覆盖物

 @param overlay 覆盖物
 */
- (void)addOverlay:(GHOverlay *)overlay;

/**
 添加一组覆盖物

 @param overlays 覆盖物数组
 */
- (void)addOverlays:(NSArray *)overlays;

/**
 移除覆盖物

 @param overlay 覆盖物
 */
- (void)removeOverlay:(GHOverlay *)overlay;

/**
 移除一组覆盖物

 @param overlays 覆盖物数组
 */
- (void)removeOverlays:(NSArray *)overlays;

/**
 获取Marker的数量

 @return Marker的数量
 */
- (NSUInteger)getMarkerCount;

/**
 通过索引获取Marker

 @param index 索引
 @return Marker
 */
- (GHMarker *)getMarkerByIndex:(int)index;

/**
 通过主键获取Marker

 @param identifier 主键
 @return Marker
 */
- (GHMarker *)getMarkerByIdentifier:(int)identifier;

/**
 通过定义的主键移除Marker

 @param index 索引
 */
- (void)removeMarkerByIndex:(int)index;

/**
 通过主键移除Marker

 @param identifier 主键
 */
- (void)removeMarkerByIdentifier:(int)identifier;

/**
 移除全部Marker
 */
- (void)clearMarkers;

/**
 获取Label的数量
 
 @return Label的数量
 */
- (NSUInteger)getLabelCount;

/**
 通过索引获取Label
 
 @param index 索引
 @return Label
 */
- (GHLabel *)getLabelByIndex:(int)index;

/**
 通过主键获取Label

 @param identifier 主键
 @return Label
 */
- (GHLabel *)getLabelByIdentifier:(int)identifier;

/**
 通过索引移除Label
 
 @param index 主键
 */
- (void)removeLabelByIndex:(int)index;

/**
 通过主键删除label

 @param identifier 主键
 */
- (void)removeLabelByIdentifier:(int)identifier;

/**
 移除全部Label
 */
- (void)clearLabels;

/**
 获取Line的数量
 
 @return Line的数量
 */
- (NSUInteger)getLineCount;

/**
 通过索引获取Line
 
 @param index 索引
 @return Line
 */
- (GHLine *)getLineByIndex:(int)index;

/**
 通过主键获取line

 @param identifier 主键
 @return Line
 */
- (GHLine *)getLineByIdentifier:(int)identifier;

/**
 通过索引移除Line
 
 @param index 索引
 */
- (void)removeLineByIndex:(int)index;

/**
 通过主键删除line

 @param identifier 主键
 */
- (void)removeLineByIdentifier:(int)identifier;

/**
 移除全部Line
 */
- (void)clearLines;

/**
 获取Line的数量
 
 @return Line的数量
 */
- (NSUInteger)getTextureLineCount;

/**
 通过索引获取Line
 
 @param index 索引
 @return Line
 */
- (GHTextureLine *)getTextureLineByIndex:(int)index;

/**
 通过主键获取line
 
 @param identifier 主键
 @return Line
 */
- (GHTextureLine *)getTextureLineByIdentifier:(int)identifier;

/**
 通过索引移除Line
 
 @param index 索引
 */
- (void)removeTextureLineByIndex:(int)index;

/**
 通过主键删除line
 
 @param identifier 主键
 */
- (void)removeTextureLineByIdentifier:(int)identifier;

/**
 移除全部纹理线
 */
- (void)clearTextureLines;

/**
 获取Polygon的数量
 
 @return Polygon的数量
 */
- (NSUInteger)getPolygonCount;

/**
 通过索引获取Polygon
 
 @param index 索引
 @return Polygon
 */
- (GHPolygon *)getPolygonByIndex:(int)index;

/**
 通过主键获取polygon

 @param identifier 主键
 @return Polygon
 */
- (GHPolygon *)getPolygonByIdentifier:(int)identifier;

/**
 通过索引移除Polygon
 
 @param index 索引
 */
- (void)removePolygonByIndex:(int)index;

/**
 通过主键移除polygon

 @param identifier 主键
 */
- (void)removePolygonByIdentifier:(int)identifier;

/**
 移除全部Polygon
 */
- (void)clearPolygons;

/**
 获取Circle的数量
 
 @return Circle的数量
 */
- (NSUInteger)getCircleCount;

/**
 通过索引获取Circle
 
 @param index 索引
 @return Circle
 */
- (GHCircle *)getCircleByIndex:(int)index;

/**
 通过主键获取circle

 @param identifier 主键
 @return Circle
 */
- (GHCircle *)getCircleByIdentifier:(int)identifier;

/**
 通过索引移除Circle
 
 @param index 索引
 */
- (void)removeCircleByIndex:(int)index;

/**
 通过主键移除circle

 @param identifier 主键
 */
- (void)removeCircleByIdentifier:(int)identifier;

/**
 移除全部Circle
 */
- (void)clearCircles;

/**
 获取Collada的数量
 
 @return Collada的数量
 */
- (NSUInteger)getColladaCount;

/**
 通过索引获取Collada
 
 @param index 索引
 @return Collada
 */
- (GHColladaObject *)getColladaByIndex:(int)index;

/**
 通过主键获取Collada

 @param identifier 主键
 @return Collada
 */
- (GHColladaObject *)getColladaByIdentifier:(int)identifier;

/**
 通过索引移除Collada
 
 @param index 索引
 */
- (void)removeColladaByIndex:(int)index;

/**
 通过主键移除Collada

 @param identifier 主键
 */
- (void)removeColladaByIdentifier:(int)identifier;

/**
 移除全部Collada
 */
- (void)clearColladas;

/**
 移除全部覆盖物
 */
- (void)clearAll;

/**
 获取全部Marker的包围盒
 */
- (GHBox)getMarkersBox;

/**
 获取全部Line的包围盒
 */
- (GHBox)getLinesBox;

/**
 获取全部Polygon的包围盒
 */
- (GHBox)getPolygonsBox;

/**
 获取全部Label的包围盒
 */
- (GHBox)getLabelsBox;

#pragma mark - 定位点

/**
 添加定位点

 @param location 定位点的实例
 */
- (void)addLocation:(GHLocation *)location;

/**
 通过索引获取定位点

 @param index 索引
 @return 定位点的实例
 */
- (GHLocation *)getLocationByIndex:(int)index;

/**
 通过主键获取定位点

 @param identifier 主键
 @return GHLocation
 */
- (GHLocation *)getLocationByIdentifier:(int)identifier;

/**
 通过索引删除定位点

 @param index 唯一主键
 */
- (void)removeLocationByIndex:(int)index;

/**
 通过主键删除定位点

 @param identifier 主键
 */
- (void)removeLocationByIdentifier:(int)identifier;

/**
 移除全部定位点
 */
- (void)removeAllLocation;


#pragma mark - 路径规划

/**
 路径规划

 @param startPoint 起点坐标
 @param startFloorName 起点楼层名称
 @param endPoint 终点坐标
 @param endFloorName 终点楼层名称
 @param type 类型（人行、车行）
 @return 路书
 */
- (GHRouteBook *)routing:(GHPoint)startPoint startFloorName:(NSString *)startFloorName endPoint:(GHPoint)endPoint endFloorName:(NSString *)endFloorName type:(GHRouteType)type priority:(NSArray *)priority;

/**
融合路径规划

@param routePoints 路线节点数组
@param priority 优先级数组（只对人行路线起作用）
@return 路书
*/
- (GHRouteBook *)routing:(NSArray *)routePoints priority:(NSArray *)priority;

/**
 获取路径规划数组

 @return 路径规划数组
 */
- (NSArray *)getRouteResult;

/**
 设置路径规划起点

 @param startPoint 起点坐标
 @param startFloorName 起点楼层名称
 */
- (void)setRoutingStartPoint:(GHPoint)startPoint startFloorName:(NSString *)startFloorName;

/**
 设置路径规划终点

 @param endPoint 终点坐标
 @param endFloorName 终点楼层名称
 */
- (void)setRoutingEndPoint:(GHPoint)endPoint endFloorName:(NSString *)endFloorName;

/**
 清除路径规划
 */
- (void)clearRoutePlan;

/**
 设置路径规划途经点

 @param points 途经点数组
 @param routeType 类型（人行、车行）
 */
- (void)setPassPoints:(NSArray *)points routeType:(GHRouteType)routeType;

/**
 根据编号设置目标点拥挤系数，默认拥挤系数为1，拥挤程度0-100依次递增

 @param code 编号
 @param level 拥挤程度
 @param routeType 类型（人行、车行）
 */
- (void)setCrowdedBySpaceCode:(NSString *)code level:(int)level routeType:(GHRouteType)routeType;

/**
 根据名称设置目标点拥挤系数，默认拥挤系数为1，拥挤程度0-100依次递增

 @param name 名称
 @param level 拥挤程度
 @param routeType 类型（人行、车行）
 */
- (void)setCrowdedBySpaceName:(NSString *)name level:(int)level routeType:(GHRouteType)routeType;

/**
 给路径添加权重

 @param routeOption routeOption对象
 @param routeType 类型（人行、车行
 */
- (void)setSpecialLink:(GHRouteOption *)routeOption routeType:(GHRouteType)routeType;


/**
 给路径增加避让点

 @param points 点数组
 @param radius 半径
 */
- (void)setAvoidPoints:(NSArray *)points radius:(float)radius;

- (NSArray *)getAllRoutes:(int)type;

#pragma mark - 地图更新接口

/**
 检查地图更新
 */
- (void)checkMapUpdate;

/**
 下载最新地图数据
 */
- (void)downloadLastestMap;

#pragma mark - 坐标转换

/**
 像素转图内坐标

 @param px 像素坐标
 @return 图内坐标
 */
- (GHPoint)px2gp:(GHPoint)px;

/**
 图内转像素坐标

 @param gp 图内坐标
 @return 像素坐标
 */
- (GHPoint)gp2px:(GHPoint)gp;

/**
 图内转墨卡托坐标

 @param gp 图内坐标
 @return 墨卡托坐标
 */
- (GHPoint)gp2mect:(GHPoint)gp;

/**
 墨卡托转图内坐标

 @param mect 墨卡托坐标
 @return 图内坐标
 */
- (GHPoint)mect2gp:(GHPoint)mect;

/**
 墨卡托转经纬度坐标

 @param mect 墨卡托坐标
 @return 经纬度坐标
 */
- (GHPoint)mect2lonlat:(GHPoint)mect;

/**
 经纬度转墨卡托坐标

 @param lonlat 经纬度坐标
 @return 墨卡托坐标
 */
- (GHPoint)lonlat2mect:(GHPoint)lonlat;

/**
 设置指南针的位置差值

 @param point 坐标
 */
- (void)setComapssViewOffset:(GHPoint)point;

/**
 设置缩放控件的位置差值

 @param point 坐标
 */
- (void)setScaleControlOffset:(GHPoint)point;

@end

























/*!
 @class
 @abstract GHBuilding，建筑物类，用于存储建筑物（地图）的信息。
 */
@interface GHBuilding : NSObject

/*!
 @property
 @abstract 建筑物名称。
 */
@property (nonatomic,strong) NSString *name;

/*!
 @property
 @abstract 建筑物编号。
 */
@property (nonatomic,strong) NSString *buildNum;

/*!
 @property
 @abstract 建筑物角度。
 */
@property (nonatomic,assign) float angle;

/*!
 @property
 @abstract 建筑物缩放比。
 */
@property (nonatomic,assign) float scale;

/*!
 @property
 @abstract 地图版本号。
 */
@property (nonatomic,strong) NSString *version;

/*!
 @property
 @abstract 过期时间。
 */
@property (nonatomic,assign) long deadLine;

/*!
 @property
 @abstract 西南角坐标。
 */
@property (nonatomic,assign) GHPoint swPosition;

/*!
 @property
 @abstract 东北角坐标。
 */
@property (nonatomic,assign) GHPoint nePosition;

/*!
 @property
 @abstract 建筑物中心点。
 */
@property (nonatomic,assign) GHPoint center;

@end
