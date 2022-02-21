//
//  GHOverlay.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/6/29.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHGeometry.h"

typedef enum
{
    GHIconLayoutCenter = 1,
    GHIconLayoutTopCenter,
} GHIconLayout;

typedef enum
{
    GHMarkerTextLayoutTop    = 0,
    GHMarkerTextLayoutBottom = 1,
    GHMarkerTextLayoutLeft   = 2,
    GHMarkerTextLayoutRight  = 3,
}GHMarkerTextLayout;

/*!
 @class
 @abstract GHOverlay，所有覆盖物均继承此类。
 */
@interface GHOverlay : NSObject

/*!
 @property
 @abstract 唯一索引，自动维护。
 */
@property (nonatomic,readonly) int identifier;

/*!
 @property
 @abstract 覆盖物的额外信息。
 */
@property (nonatomic,strong) NSDictionary *extraInfo;

/*!
 @property
 @abstract 覆盖物是否显示，默认为YES。
 */
@property (nonatomic,assign) BOOL visible;

/*!
 @property
 @abstract 排序，数字越大显示越排上。
 */
@property (nonatomic,assign) int zIndex;

/*!
 @property
 @abstract 相对高度，距离楼层面的高度。
 */
@property (nonatomic,assign) float relativeHeight;

/*!
 @property
 @abstract 是否响应单击事件，默认为YES。
 */
@property (nonatomic,assign) BOOL canClick;

/*!
 @property
 @abstract 业务编码，由用户自行定义。
 */
@property (nonatomic,strong) NSString *code;

/*!
 @property
 @abstract 楼层名称。
 */
@property (nonatomic,strong) NSString *floorName;

@end

/*!
 @class
 @abstract GHLine，线状覆盖物，继承自GHOverlay。
 */
@interface GHLine : GHOverlay

/*!
 @property
 @abstract 点坐标，参照GHGeometry方法，将GHPoint转换至NSValue对象存入数组。
 */
@property (nonatomic,strong) NSArray<__kindof NSValue *> *points;

/*!
 @property
 @abstract 线条宽度，默认为1。
 */
@property (nonatomic,assign) float width;

/*!
 @property
 @abstract 线条颜色，默认为红色。
 */
@property (nonatomic,strong) UIColor *color;

/*!
 @property
 @abstract 是否为虚线，默认为NO。
 */
@property (nonatomic,assign) BOOL dotted;

/*!
 @property
 @abstract 高度，本身高度。
 */
@property (nonatomic,assign) float height;

@end

/**
 GHTextureLine，纹理线覆盖物，继承自GHOverlay
 */
@interface GHTextureLine : GHOverlay

/*!
 @property
 @abstract 点坐标，参照GHGeometry方法，将GHPoint转换至NSValue对象存入数组。
 */
@property (nonatomic,strong) NSArray<__kindof NSValue *> *points;

/*!
 @property
 @abstract 高度，本身高度。
 */
@property (nonatomic,assign) float height;

/**
 纹理图片,须是正方形，宽高是2的整数幂，如64*64，否则无效
 */
@property (nonatomic,strong) UIImage *textureImage;

@end

/*!
 @class
 @abstract GHPolygon，面状覆盖物，继承自GHOverlay。
 */
@interface GHPolygon : GHOverlay

/*!
 @property
 @abstract 点坐标，参照GHGeometry方法，将GHPoint转换至NSValue对象存入数组。
 */
@property (nonatomic,strong) NSArray<__kindof NSValue *> *points;

/*!
 @property
 @abstract 中心点。
 */
@property (nonatomic,assign) GHPoint center;

#warning 是否改为GHLine对象
/*!
 @property
 @abstract 边线宽度，默认为1。
 */
@property (nonatomic,assign) float strokeWidth;

/*!
 @property
 @abstract 边线颜色，默认为浅灰。
 */
@property (nonatomic,strong) UIColor *strokeColor;

/*!
 @property
 @abstract 填充颜色，默认为白色。
 */
@property (nonatomic,strong) UIColor *fillColor;

/*!
 @property
 @abstract 高度，本身高度，默认0。
 */
@property (nonatomic,assign) float height;

/*!
 @property
 @abstract 名称。
 */
@property (nonatomic,strong) NSString *name;

/*!
 @property
 @abstract 其他名称。
 */
@property (nonatomic,strong) NSString *oName;

@end

/*!
 @class
 @abstract GHCircle，圆状覆盖物，继承自GHOverlay。
 */
@interface GHCircle : GHOverlay

/*!
 @property
 @abstract 中心点坐标。
 */
@property (nonatomic,assign) GHPoint center;

/*!
 @property
 @abstract 半径（米）。
 */
@property (nonatomic,assign) float radius;

/*!
 @property
 @abstract 边线宽度，默认为1。
 */
@property (nonatomic,assign) float strokeWidth;

/*!
 @property
 @abstract 边线颜色，默认为浅灰。
 */
@property (nonatomic,strong) UIColor *strokeColor;

/*!
 @property
 @abstract 填充颜色，默认为白色。
 */
@property (nonatomic,strong) UIColor *fillColor;

/*!
 @property
 @abstract 高度，本身高度，默认0。
 */
@property (nonatomic,assign) float height;

/*!
 @property
 @abstract 名称。
 */
@property (nonatomic,strong) NSString *name;

/*!
 @property
 @abstract 其他名称。
 */
@property (nonatomic,strong) NSString *oName;

@end

/*!
 @class
 @abstract GHMarker，标记类覆盖物，继承自GHOverlay。
 */
@interface GHMarker : GHOverlay

/*!
 @property
 @abstract 坐标点。
 */
@property (nonatomic,assign) GHPoint position;

/*!
 @property
 @abstract 图标。
 */
@property (nonatomic,strong) UIImage *icon;

/*!
 @property
 @abstract 角度。
 */
@property (nonatomic,assign) float rotate;

/*!
 @property
 @abstract 透明度。
 */
@property (nonatomic,assign) float alpha;

/*!
 @property
 @abstract 缩放比。
 */
@property (nonatomic,assign) float scale;

/*!
 @property
 @abstract 图片位置，默认为GHIconLayoutCenter。
 */
@property (nonatomic,assign) GHIconLayout iconLayout;

/*!
 @property
 @abstract 名称。
 */
@property (nonatomic,strong) NSString *name;

/*!
 @property
 @abstract 其他名称。
 */
@property (nonatomic,strong) NSString *oName;


/**
 字体 默认为[UIFont systemFontOfSize:20]
 */
@property (nonatomic,strong) UIFont *font;

/*!
 @property
 @abstract 文字颜色，默认为黑色。
 */
@property (nonatomic,strong) UIColor *textColor;

/*!
 @property
 @abstract 文字描边颜色，默认为白色。
 */
@property (nonatomic,strong) UIColor *strokeColor;

/*!
 @property
 @abstract 文字描边宽度。
 */
@property (nonatomic,assign) int strokeWidth;

/*!
 @property
 @abstract 文字相对图标位置，默认为GHMarkerTextLayoutTop。
 */
@property (nonatomic,assign) GHMarkerTextLayout textLayout;

/*!
 @property
 @abstract 文字与图标的间距，默认为5。
 */
@property (nonatomic,assign) int spacing;

/**
 是否使用动画
 */
@property (nonatomic,assign) BOOL animated;

@end

/*!
 @class
 @abstract GHLabel，文本类覆盖物，继承自GHOverlay。
 */
@interface GHLabel : GHOverlay

/*!
 @property
 @abstract 坐标点。
 */
@property (nonatomic,assign) GHPoint position;
/*!
 @property
 @abstract 透明度。
 */
@property (nonatomic,assign) float alpha;
/*!
 @property
 @abstract 缩放比。
 */
@property (nonatomic,assign) float scale;
/*!
 @property
 @abstract 名称。
 */
@property (nonatomic,strong) NSString *name;

/*!
 @property
 @abstract 其他名称。
 */
@property (nonatomic,strong) NSString *oName;

/**
 字体 默认为[UIFont systemFontOfSize:20]
 */
@property (nonatomic,strong) UIFont *font;

/*!
 @property
 @abstract 文字颜色，默认为黑色。
 */
@property (nonatomic,strong) UIColor *textColor;

/*!
 @property
 @abstract 文字描边颜色，默认为白色。
 */
@property (nonatomic,strong) UIColor *strokeColor;

/*!
 @property
 @abstract 文字描边宽度。
 */
@property (nonatomic,assign) int strokeWidth;

/*!
 @property
 @abstract 背景色，默认为白色。
 */
@property (nonatomic,strong) UIColor *backgroundColor;

/*!
 @property
 @abstract 背景边框颜色，默认为白色。
 */
@property (nonatomic,strong) UIColor *boardColor;

/*!
 @property
 @abstract 背景边框宽度，默认为1。
 */
@property (nonatomic,assign) int boardWidth;

/**
 是否启动动画，默认启用
 */
@property (nonatomic,assign) BOOL animated;

@end

/**
 定位点
 */
@interface GHLocation : GHOverlay

/**
 定位点坐标
 */
@property (nonatomic,assign) GHPoint location;

/**
 角度
 */
@property (nonatomic,assign) float locationAngle;

/**
 图标缩放比例
 */
@property (nonatomic,assign) float locationImageScale;

/**
 定位点图标
 */
@property (nonatomic,strong) UIImage *locationImage;

/**
 定位点环绕圆
 */
@property (nonatomic,strong) UIImage *locationCircleImage;

/**
 是否启动动画，默认启用
 */
@property (nonatomic,assign) BOOL animated;

/**
 是否导航模式，默认为false
 */
@property (nonatomic,assign) BOOL navigationMode;

@end

@interface GHColladaObject : GHOverlay

/**
 角度 0-360
 */
@property (nonatomic,assign) float rotate;

/**
 缩放级别
 */
@property (nonatomic,assign) float scale;

/**
 位置
 */
@property (nonatomic,assign) GHPoint position;

/**
路径
*/
@property (nonatomic,strong) NSString *filePath;

@end
