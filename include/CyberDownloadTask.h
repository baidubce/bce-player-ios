// 
//  CyberDownloadTask.h
//  CyberDownloader
//
//  Copyright © 2016 Bailu. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 前置声明。
@class CyberMediaItem;

/**
 *  @brief 下载任务的状态。
 */
typedef NS_ENUM(NSUInteger, CyberDownloadTaskState) {
    
    /**
     *  等待中。
     */
    CyberDownloadTaskStateWait,
    /**
     *  下载中。
     */
    CyberDownloadTaskStateRunning,
    /**
     *  已挂起。
     */
    CyberDownloadTaskStateSuspend,
    /**
     *  已取消。
     */
    CyberDownloadTaskStateCanceled,
    /**
     *  已完成。
     */
    CyberDownloadTaskStateFinish,
    /**
     *  已失败。
     */
    CyberDownloadTaskStateFailure
};

/**
 *  @brief 抽象一个下载任务。
 */
@interface CyberDownloadTask : NSObject

/**
 *  @brief 下载任务相关信息。
 */
@property(nonatomic, copy, readonly) CyberMediaItem* item;

/**
 *  @brief 下载状态。
 */
@property(nonatomic, assign, readonly) CyberDownloadTaskState state;

/**
 *  @brief 下载进度。
 */
@property(nonatomic, assign, readonly) float progress;

- (instancetype)init NS_UNAVAILABLE;

@end
