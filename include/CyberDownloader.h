// 
//  CyberDownloader.h
//  CyberDownloader
//
//  Copyright © 2016 Bailu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CyberMediaItem.h"
#import "CyberDownloadTask.h"

/**
 *  @brief CyberDownloader类的downloadTaskWithURL方法返回错误时，这里是关于错误码的定义。
 */
typedef NS_ENUM(NSUInteger, CyberDownloadErrorCode) {
    /**
     *  可以下载。
     */
    CyberDownloadErrorCodeOK,
    /**
     *  已经存在且已下载完毕。
     */
    CyberDownloadErrorCodeAlreadyExists,
    /**
     *  协议不被支持。
     */
    CyberDownloadErrorCodeProtocolNotSupport,
};

/**
 *  @brief CyberDownloader类的一些回调函数定义。
 */
@protocol CyberDownloaderDelegate <NSObject>

@optional

/**
 *  @brief 任务开始。
 *  @param task 任务。
 */
- (void)taskStart:(CyberDownloadTask*)task;

/**
 *  @brief 任务进度上报。
 *  @param task     任务。
 *  @param progress 进度。0~100
 */
- (void)task:(CyberDownloadTask*)task progress:(float)progress;

/**
 *  @brief 任务完成。
 *  @param task  任务。
 *  @param error 错误，不为空表示发生了错误。
 */
- (void)taskEnd:(CyberDownloadTask*)task error:(NSError*)error;

@end

/**
 *  @brief 下载管理器。必须指定用户名和代理进行初始化。
 */
@interface CyberDownloader : NSObject

/**
 *  @brief 指定用户名和代理进行初始化。在没有账户系统时，可指定默认值。
 *  @param user     用户名。
 *  @param delegate 代理。
 *  @return 下载管理器。
 */
- (instancetype)initWithUser:(NSString*)user
                    delegate:(id<CyberDownloaderDelegate>)delegate;

/**
 *  @brief 当前所有(下载中、下载完成)的item。
 *  @return item数组。
 */
- (NSArray<CyberMediaItem*>*)mediaItems;

/**
 *  @brief 删除一个item
 *  @param item
 */
- (void)removeMediaItem:(CyberMediaItem*)item;

/**
 *  @brief 下载指定的URL，并为其指定一个标题。如果返回值为空，表示发生了错误，其查看error。
 *  @param url   URL地址。
 *  @param title 标题。
 *  @param error 错误信息，错误码与CyberDownloadErrorCode中定义的值对应。
 *  @return 下载任务。
 */
- (CyberDownloadTask*)downloadTaskWithURL:(NSString*)url title:(NSString*)title error:(NSError**)error;

/**
 *  @brief 挂起下载任务。
 *  @param task 下载任务。
 */
- (void)suspendTask:(CyberDownloadTask*)task;

/**
 *  @brief 继续下载任务。
 *  @param task 下载任务。
 */
- (void)resumeTask:(CyberDownloadTask*)task;

/**
 *  @brief 取消下载任务，并删除已下载的数据。
 *  @param task 下载任务。
 */
- (void)cancelTask:(CyberDownloadTask*)task;

/**
 *  @brief 继续上次未完成的下载任务。
 *  @return 返回下载任务的数组。
 */
- (NSArray<CyberDownloadTask*>*)resumeUncompletedTasks;

/**
 *  @brief 停止所有下载任务。
 */
- (void)stopAllTasks;

@end

