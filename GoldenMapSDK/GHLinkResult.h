//
//  GHLinkResult.h
//  GoldenMap
//
//  Created by YaNan_L on 2019/7/25.
//  Copyright © 2019 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GHGeometry.h"

@interface GHLinkResult : NSObject

/**
 通行类型
 */
@property (nonatomic,assign) GHLinkType linkType;

/**
 是否向上
 */
@property (nonatomic,assign) BOOL up;

/**
 楼层的数量
 */
@property (nonatomic,assign) NSUInteger count;

@end
