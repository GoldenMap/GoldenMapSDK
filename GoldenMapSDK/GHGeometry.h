//
//  GHGeometry.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/6/29.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#ifdef __OBJC__

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#endif

/*基础对象定义及构造函数*/
struct GHPoint {
    double x;
    double y;
    double z;
};
typedef struct GHPoint GHPoint;

struct GHSize {
    double width;
    double height;
};
typedef struct GHSize GHSize;

struct GHBox {
    GHPoint swPoint;
    GHPoint nePoint;
};
typedef struct GHBox GHBox;

struct GHMargin
{
    float topMargin;
    float bottomMargin;
    float leftMargin;
    float rightMargin;
};
typedef struct GHMargin GHMargin;

inline static GHPoint
GHPointMake(double x, double y)
{
    GHPoint p; p.x = x; p.y = y;p.z = 0; return p;
}

static inline GHPoint
GHPointMake3D(double x, double y, double z)
{
    GHPoint p; p.x = x; p.y = y;p.z = z; return p;
}

inline static GHSize
GHSizeMake(double width, double height)
{
    GHSize size; size.width = width; size.height = height; return size;
}

inline GHBox
GHBoxMake(GHPoint swPoint, GHPoint nePoint)
{
    GHBox box; box.swPoint = swPoint; box.nePoint = nePoint; return box;
}

inline GHMargin
GHMarginMake(float top, float bottom, float left, float right)
{
    GHMargin m;m.topMargin = top; m.bottomMargin = bottom; m.leftMargin = left; m.rightMargin = right; return m;
}

inline bool
GHPointEqualToPoint(GHPoint point1, GHPoint point2)
{
    return point1.x == point2.x && point1.y == point2.y && point1.z == point2.z;
}

inline bool
GHSizeEqualToSize(GHSize size1, GHSize size2)
{
    return size1.width == size2.width && size1.height == size2.height;
}

/**
 图形类型定义

 - GHGeometryTypePoint: 点
 - GHGeometryTypeLine: 线
 - GHGeometryTypePolygon: 面
 */
typedef NS_ENUM(NSUInteger, GHGeometryType) {
    GHGeometryTypePoint,
    GHGeometryTypeLine,
    GHGeometryTypePolygon,
};

typedef enum : NSUInteger {
    UNUSUAL = 0,
    NORTH = 1,//正北
    NORTH_EAST = 2,//东北
    EAST = 3,//正东
    SOUTH_EAST = 4,//东南
    SOUTH = 5,//正南
    SOUTH_WEST = 6,//西南
    WEST = 7,//正西
    NORTH_WEST = 8,//西北
    RIGHT_FRONT = 15,      //右前方
    RIGHT_BACK = 17,      //右后方
    RIGHT = 12,             //右拐
    LEFT_FRONT = 16,         //左前方
    LEFT_BACK = 18,         //左后方
    LEFT = 11,               //左拐
    UPSTAIRS = 13,           //上楼
    DOWNSTAIRS = 14,         //下楼
    DESTINATION = 100        //到达目的地
} GHDirection;

//int direction;//方向 1正北 ，2东北 ，3正东 ，4东南 ，5正南 ，6西南 ，7正西 ，8西北 11左 ，12右 13上 ，14下，15右前方，16左前方 17右后方 18左后方 只针对通行POI

typedef enum : NSUInteger {//typedef enum//1 步行梯 2 直梯 3 扶梯 5 货梯 9 其他
    STRAIGHT_LADDER = 2 ,       //直梯
    HAND_LADDER = 3,            //扶梯
    WALKING_LADDER = 1,          //步行梯
    GOODS_LANDER = 5,            //货梯
    OTHER = 9
} GHLinkType;

typedef enum : NSUInteger {//typedef enum//1 步行梯 2 直梯 3 扶梯 5 货梯 9 其他
    GH_Horizontal = 1,
    GH_Vertical = 2
} GHOrientation;

@interface NSValue (GHValue)

+ (NSValue *)valueWithGHPoint:(GHPoint)point;


@property (readonly)GHPoint GHPointValue;

@end


/**
 数据层类定义
 */
@interface GHLayer : NSObject

/**
 所属楼层名称
 */
@property (nonatomic,strong) NSString *floorName;

/**
 名称
 */
@property (nonatomic,strong) NSString *name;

/**
 标识符
 */
@property (nonatomic,strong) NSString *identifier;

/**
 类型
 */
@property (nonatomic,assign) GHGeometryType type;

/**
 是否隐藏
 */
@property (nonatomic,assign) BOOL hidden;

/**
 是否响应用户点击
 */
@property (nonatomic,assign) BOOL clickEnable;

/**
 最大显示级别
 */
@property (nonatomic,assign) int maxDisplayZoom;

/**
 最小显示级别
 */
@property (nonatomic,assign) int minDisplayZoom;

/**
 字段名称
 */
@property (nonatomic,strong) NSArray *fieldNames;

@end

@interface GHSearchResult : NSObject

/**
 所属楼层
 */
@property (nonatomic,strong) NSString *floorName;

/**
 类型
 */
@property (nonatomic,assign) GHGeometryType type;

/**
 数据字典
 */
@property (nonatomic,strong) NSDictionary *values;

/**
 坐标数据，只有线类型才有
 */
@property (nonatomic,strong) NSArray *points;

/**
 中心点，只有点和面类型数据才有
 */
@property (nonatomic,assign) GHPoint center;

@end


/**
 GHPoint包装类，包含楼层
 */
@interface GHPointer : NSObject

/**
 坐标
 */
@property (nonatomic,assign) GHPoint point;

/**
 楼层
 */
@property (nonatomic,strong) NSString *floorName;

@end





