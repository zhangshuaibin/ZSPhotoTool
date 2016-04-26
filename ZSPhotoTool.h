//
//  ZSPhotoTool.h
//  ZSPhotoTool
//
//  Created by 开发 on 16/4/26.
//  Copyright © 2016年 开发. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Photos/Photos.h>

@interface ZBSelectPhotoModel : NSObject

@property (nonatomic, strong) PHAsset *asset;
@property (nonatomic, copy) NSString *imageName;

@end

@interface ZBPhotoAblumList : NSObject

@property (nonatomic, copy) NSString *title; //相册名字
@property (nonatomic, assign) NSInteger count; //该相册内相片数量
@property (nonatomic, strong) PHAsset *headImageAsset; //相册第一张图片缩略图
@property (nonatomic, strong) PHAssetCollection *assetCollection; //相册集，通过该属性获取该相册集下所有照片

@end

@interface ZSPhotoTool : NSObject
+ (instancetype)sharePhotoTool;

/**
 * @brief 获取用户所有相册列表
 */
- (NSArray<ZBPhotoAblumList *> *)getPhotoAblumList;


/**
 * @brief 获取相册内所有图片资源
 * @param ascending 是否按创建时间正序排列 YES,创建时间正（升）序排列; NO,创建时间倒（降）序排列
 */
- (NSArray<PHAsset *> *)getAllAssetInPhotoAblumWithAscending:(BOOL)ascending;


/**
 * @brief 获取指定相册内的所有图片
 */
- (NSArray<PHAsset *> *)getAssetsInAssetCollection:(PHAssetCollection *)assetCollection ascending:(BOOL)ascending;


/**
 * @brief 获取每个Asset对应的图片
 */
- (void)requestImageForAsset:(PHAsset *)asset size:(CGSize)size resizeMode:(PHImageRequestOptionsResizeMode)resizeMode completion:(void (^)(UIImage *image))completion;


/**
 * @brief 点击确定时，获取每个Asset对应的图片（imageData）
 */
- (void)requestImageForAsset:(PHAsset *)asset scale:(CGFloat)scale resizeMode:(PHImageRequestOptionsResizeMode)resizeMode completion:(void (^)(UIImage *image))completion;

/**
 * @brief 获取数组内图片的字节大小
 */
- (void)getPhotosBytesWithArray:(NSArray *)photos completion:(void (^)(NSString *photosBytes))completion;


/**
 * @brief 判断图片是否存储在本地/或者已经从iCloud上下载到本地
 */
- (BOOL)judgeAssetisInLocalAblum:(PHAsset *)asset ;


@end
