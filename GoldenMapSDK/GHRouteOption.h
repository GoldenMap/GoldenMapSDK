//
//  GHRouteOption.h
//  GoldenMap
//
//  Created by YaNan_L on 2017/6/30.
//  Copyright © 2017年 BeiJing GuangYiHengXin Technology Co. Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GHRouteOption : NSObject

/**
 *   1 步行梯 2 直梯 3 扶梯  5 货梯  9 其他，将编号以字符串的形式存入数组
 */
@property (nonatomic,strong) NSArray<__kindof NSString *> *linkTypeFliter;

/**
 *   路径节点的数组
 */
@property (nonatomic,strong) NSArray<__kindof NSNumber *> *linkFilter;

/**
 *   路径节点的权重
 */
@property (nonatomic,assign) float linkDiscount;

@end
