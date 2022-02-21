//
//  GHMapOptions.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/6/30.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "GHGeometry.h"

typedef enum
{
    GHMapMode2D = 1,
    GHMapMode3D,
} GHMapMode;

typedef enum
{
    GHCompassPositionLeftTop = 1,
    GHCompassPositionRightTop,
} GHCompassPosition;

typedef enum
{
    GHScaleBarPositionRightBottom = 1,
    GHScaleBarPositionLeftBottom,
} GHScaleBarPosition;

typedef enum
{
    GHLogoPositionLeftBottom = 1,
    GHLogoPositionRightBottom,
} GHLogoPosition;

typedef enum
{
    GHLanguageChinese = 1,
    GHLanguageOther,
} GHLanguage;

typedef enum
{
    GHFloorControlPositionRight  = 1,
    GHFloorControlPositionLeft,
} GHFloorControlPosition;

typedef enum
{
    GHScaleControlPositionRight   = 1,
    GHScaleControlPositionLeft,
} GHScaleControlPosition;

/*!
 @class
 @abstract GHMapOptions，地图状态类，用于预置地图状态。
 */
@interface GHMapOptions : NSObject

/*!
 @property
 @abstract 地图角度，默认为0。
 */
@property (nonatomic,assign) float rotate;

/*!
 @property
 @abstract 倾斜角度，默认为45度。
 */
@property (nonatomic,assign) float pitch;

/*!
 @property
 @abstract 地图模式，默认为三维。
 */
@property (nonatomic,assign) GHMapMode mapMode;

/*!
 @property
 @abstract 比例尺是否显示，默认显示。
 */
@property (nonatomic,assign) BOOL scaleBarVisible;

/*!
 @property
 @abstract 比例尺位置，默认为右下角。
 */
@property (nonatomic,assign) GHScaleBarPosition scaleBarPosition;

/*!
 @property
 @abstract logo的位置，默认为左下角。
 */
@property (nonatomic,assign) GHLogoPosition logoPosition;

/*!
 @property
 @abstract 语言，默认为中文。
 */
@property (nonatomic,assign) GHLanguage language;

/*!
 @property
 @abstract 图形选中颜色，默认为红色。
 */
@property (nonatomic,strong) UIColor *selectedPolygonColor;

/*!
 @property
 @abstract 线选中颜色，默认为红色。
 */
@property (nonatomic,strong) UIColor *selectedLineColor;

/*!
 @property
 @abstract 默认显示的楼层，默认为F1。
 */
@property (nonatomic,strong) NSString *defaultFloorName;

/*!
 @property
 @abstract 中心点，默认为建筑物（地图）中心点。
 */
@property (nonatomic,assign) GHPoint center;

/*!
 @property
 @abstract 缩放级别，默认为2。
 */
@property (nonatomic,assign) float zoomLevel;

/*!
 @property
 @abstract 最大缩放级别，默认为6。
 */
@property (nonatomic,assign) float maxZoomLevel;

/*!
 @property
 @abstract 最小缩放级别，默认为1。
 */
@property (nonatomic,assign) float minZoomLevel;

/*!
 @property
 @abstract 地图背景色，默认为白色。
 */
@property (nonatomic,strong) UIColor *backgroundColor;

/*!
 @property
 @abstract POI是否显示，默认为YES。
 */
@property (nonatomic,assign) BOOL poiVisible;

/*!
 @property
 @abstract POI选中的缩放比，默认为1.5。
 */
@property (nonatomic,assign) float selectedPOIScale;

/*!
 @property
 @abstract 指南针图标。
 */
@property (nonatomic,strong) UIImage *compassImage;

/*!
 @property
 @abstract 指南针大小。
 */
@property (nonatomic,assign) GHSize compassSize;

/*!
 @property
 @abstract 指南针是否显示，默认为显示。
 */
@property (nonatomic,assign) BOOL compassVisible;

/*!
 @property
 @abstract 指南针位置，默认为左上角。
 */
@property (nonatomic,assign) GHCompassPosition compassPosition;

/**
 指南针位置差值，默认为{0, 0}
 */
@property (nonatomic,assign) GHPoint compassOffset;

/*!
 @property
 @abstract 字体。
 */
@property (nonatomic,strong) UIFont *font;

/**
 文字颜色
 */
@property (nonatomic,strong) UIColor *textColor;//废弃

/**
 文字描边颜色
 */
@property (nonatomic,strong) UIColor *textStrokeColor;//废弃

/**
 楼层控件是否显示，默认显示
 */
@property (nonatomic,assign) BOOL floorControlVisible;

/*!
 @property
 @abstract 楼层控件位置，默认为右侧，地图模式切换集成在楼层控件上方。
 */
@property (nonatomic,assign) GHFloorControlPosition floorControlPosition;

/**
 缩放控件是否显示，默认显示
 */
@property (nonatomic,assign) BOOL scaleControlVisible;

/*!
 @property
 @abstract 缩放控件位置，默认为右侧。
 */
@property (nonatomic,assign) GHScaleControlPosition scaleControlPosition;

/**
 缩放控件的位置差值，默认为{0, 0}
 */
@property (nonatomic,assign) GHPoint scaleControlOffset;

@end
