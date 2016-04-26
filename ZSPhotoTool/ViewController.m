//
//  ViewController.m
//  ZSPhotoTool
//
//  Created by 开发 on 16/4/26.
//  Copyright © 2016年 开发. All rights reserved.
//

#import "ViewController.h"

#import "ZSPhotoTool.h"
@interface ViewController ()
{
    NSMutableArray<ZBPhotoAblumList *> *_arrayDataSources;
    
    
}
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    _arrayDataSources = [NSMutableArray array];
    
    
    [_arrayDataSources addObjectsFromArray:[[ZSPhotoTool sharePhotoTool] getPhotoAblumList]];
    
    
    UIButton *sender = [[UIButton alloc]initWithFrame:CGRectMake(100, 100, 100, 100)];
    [self.view addSubview:sender];
    
    for (ZBPhotoAblumList *image in _arrayDataSources) {
        //        NSLog(@"%@",[image class]);
        PHImageRequestOptions *options = [[PHImageRequestOptions alloc] init];
        options.deliveryMode = PHImageRequestOptionsDeliveryModeHighQualityFormat;
        
        [[PHImageManager defaultManager] requestImageForAsset:image.headImageAsset targetSize:[UIScreen mainScreen].bounds.size contentMode:PHImageContentModeAspectFit options:options resultHandler:^(UIImage *result, NSDictionary *info) {
            
            [sender setBackgroundImage:result forState:UIControlStateNormal];
        }];
    }
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
