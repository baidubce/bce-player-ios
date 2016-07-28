//
//  CyberPlayerController.h
//  cyberplayer
//
//  Copyright Baidu.com All rights reserved.
//
#ifndef cyberplayer_CyberPlayerController_h
#define cyberplayer_CyberPlayerController_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#ifdef __cplusplus
#define CBP_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define CBP_EXTERN     extern __attribute__((visibility ("default")))
#endif

CBP_EXTERN NSString * const CyberPlayerLoadDidPreparedNotification;
CBP_EXTERN NSString * const CyberPlayerPlaybackDidFinishNotification;
CBP_EXTERN NSString * const CyberPlayerStartCachingNotification;
CBP_EXTERN NSString * const CyberPlayerGotCachePercentNotification;
CBP_EXTERN NSString * const CyberPlayerPlaybackErrorNotification;
CBP_EXTERN NSString * const CyberPlayerSeekingDidFinishNotification;
CBP_EXTERN NSString * const CyberPlayerPlaybackStateDidChangeNotification;
CBP_EXTERN NSString * const CyberPlayerMeidaTypeAudioOnlyNotification;
CBP_EXTERN NSString * const CyberPlayerGotPlayQualityNotification;
CBP_EXTERN NSString * const CyberPlayerGotAVSyncDiffNotification;
CBP_EXTERN NSString * const CyberPlayerGotNetworkBitrateNotification;
CBP_EXTERN NSString * const CyberPlayerCurrentPositionNotification;

CBP_EXTERN NSString * const CBPUOnSniffCompletionNotification;
CBP_EXTERN NSString * const CBPUOnSniffErrorNotification;

enum {
    CBPMovieScalingModeNone,       // 无缩放
    CBPMovieScalingModeAspectFit,  // 同比适配，某个方向会有黑边
    CBPMovieScalingModeAspectFill, // 同比填充，某个方向的显示内容可能被裁剪
    CBPMovieScalingModeAspect_5_4, // 5:4比例播放
    CBPMovieScalingModeAspect_4_3, // 4:3比例播放
    CBPMovieScalingModeAspect_16_9, // 16:9比例播放
    CBPMovieScalingModeFill         // 满屏填充，与原始视频比例不一致
};
typedef NSInteger CBPMovieScalingMode;

enum {
    CBPMoviePlaybackStateStopped, // 播放器处于停止状态
    CBPMoviePlaybackStatePlaying, // 播放器正在播放视频
    CBPMoviePlaybackStatePaused, // 播放器处于播放暂停状态，需要调用start或play重新回到播放状态
    CBPMoviePlaybackStateInterrupted, // 播放器由于内部原因中断播放
    CBPMoviePlaybackStatePrepared // 播放器完成对视频的初始化
};
typedef NSInteger CBPMoviePlaybackState;


enum{
    CBP_ERR_NO_INPUTFILE = 301,
    CBP_ERR_INVALID_INPUTFILE = 302,
    CBP_ERR_NO_SUPPORT_CODEC = 303,
    CBP_ERR_DISPLAY = 304,
    CBP_ERR_EIO = 305,
    CBP_ERR_UAS_ERRPARAM = 513,
    CBP_ERR_UAS_USER_NOT_EXIST = 543,
    CBP_ERR_UAS_USER_SIGN = 546
};
typedef NSInteger CBPErrorCode;

/**
 百度媒体云播放器iOS SDK（以下简称“播放器iOS SDK”）是百度开放云推出的iOS平台视频播放器软件开发工具包（SDK），为iOS开发者提供简单、便捷的开发接口，帮助开发者在iPad/iPhone/iPod和Apple TV设备上实现媒体播放功能。播放器SDK内嵌百度自主研发的T5播放内核，提供简单、便捷的媒体应用开发能力，具有以下的特色功能：
 
 * 本地全媒体格式支持
    * 突破iOS平台对视频格式的限制，支持目前所有主流的媒体格式（mp4、avi、wmv、flv、mkv、mov、rmvb等）。
 * 支持广泛的流式视频格式
    * 支持多种格式文件渐进式和流式播放：HLS、RTMP、HTTP Pseudo-Streaming（伪流）。
 * 性能强大
    * 资源CPU/内存占用率低，视频加载速度快。
 * 低门槛、高灵活度实现播放功能
    * 简单易用的API，提供快速媒体播放功能开发和示开发例。播放器SDK提供了与系统播放器MPMoviePlayerController高度相似的调用接口。非常方便用户使用。
 
 当本文档无法帮助您解决在开发中遇到的具体问题，请通过以下方式联系我们，百度工程师会在第一时间回复您：
 
 * 邮箱:  dev_support@baidu.com
 
 */
@interface CyberPlayerController : NSObject
/**
 @abstract 初始化播放器并设置播放地址，与[initWithContentString]([CyberPlayerController initWithContentString:])功能一致。
 @param url 视频播放地址，该地址可以是本地地址或者服务器地址.
 @return 返回CyberPlayerController对象，该对象的视频播放地址ContentURL已经初始化。此时播放器状态为CBPMoviePlaybackStateStopped.
 @discussion 该方法初始化了播放器，并设置了播放地址。但是并没有将播放器对视频文件进行初始化，需要调用 [prepareToPlay]([CyberPlayerController prepareToPlay])方法对视频文件进行初始化。
 @since Available in CyberPlayerController 1.0 and later.
 @warning CyberPlayerController 当前版本只支持单示例的CyberPlayerController对象，多实例将导致播放异常。
 @see initWithContentString:
 */
- (id)initWithContentURL:(NSURL *)url;

/**
 @abstract 初始化播放器并设置播放地址，与[initWithContentURL]([CyberPlayerController initWithContentURL:])功能一致。
 @param url 视频播放地址，该地址可以是本地地址或者服务器地址.
 @return 返回CyberPlayerController对象，该对象的视频播放地址ContentURL已经初始化。此时播放器状态为CBPMoviePlaybackStateStopped.
 @discussion u该方法初始化了播放器，并设置了播放地址。但是并没有将播放器对视频文件进行初始化，需要调用 [prepareToPlay]([CyberPlayerController prepareToPlay])方法对视频文件进行初始化。
 @since Available in CyberPlayerController 1.0 and later.
 @warning CyberPlayerController 当前版本只支持单示例的CyberPlayerController对象，多实例将导致播放异常。
 @see initWithContentURL:
 */
- (id)initWithContentString:(NSString *)url;

/**
 @abstract 播放器初始化视频文件。
 @discussion 错误码枚举数据类型
 
 * CBP_ERR_NO_INPUTFILE，无视频地址。
 * CBP_ERR_INVALID_INPUTFILE，无效的视频文件地址。
 * CBP_ERR_NO_SUPPORT_CODEC，视频编码格式不支持。
 * CBP_ERR_ DISPLAY，视频显示初始化失败。
 * CBP_ERR_EIO，网络视频IO错误。
 * CBP_ERR_UAS_ERRPARAM，参数错误。
 * CBP_ERR_UAS_USER_NOT_EXIT，开发者账号不存在。
 * CBP_ERR_UAS_USER_SIGN，开发者账号认证错误。
 
 当播放器发送CyberPlayerPlaybackErrorNotification通知时，将携带object表征错误信息，请根据错误码判断错误原因。

    enum{
        CBP_ERR_NO_INPUTFILE = 301,
        CBP_ERR_INVALID_INPUTFILE = 302,
        CBP_ERR_NO_SUPPORT_CODEC = 303,
        CBP_ERR_DISPLAY = 304,
        CBP_ERR_EIO = 305,
        CBP_ERR_UAS_ERRPARAM = 513,
        CBP_ERR_UAS_USER_NOT_EXIST = 543,
        CBP_ERR_UAS_USER_SIGN = 546
    };
    typedef NSInteger CBPErrorCode;
 
 @discussion 通知类型
 
    //播放器完成对视频文件的初始化时发送该通知
    CBP_EXTERN NSString * const CyberPlayerLoadDidPreparedNotification; 
    //播放器播放完成发送该通知。
    CBP_EXTERN NSString * const CyberPlayerPlaybackDidFinishNotification;
    //播放器开始缓冲视频时发送该通知。
    CBP_EXTERN NSString * const CyberPlayerStartCachingNotification;
    //播放器缓冲视频过程中不断发送该通知。
    CBP_EXTERN NSString * const CyberPlayerGotCachePercentNotification;
    //播放器播放失败发送该通知。
    CBP_EXTERN NSString * const CyberPlayerPlaybackErrorNotification;
    //播放器播放位置改变完成后发送该通知。
    CBP_EXTERN NSString * const CyberPlayerSeekingDidFinishNotification;
    //播放器播放状态改变后发送该通知。
    CBP_EXTERN NSString * const CyberPlayerPlaybackStateDidChangeNotification;
    //视频文件只包含音频文件时发送该通知。
    CBP_EXTERN NSString * const CyberPlayerMeidaTypeAudioOnlyNotification;
    //视频播放过程中，发送网络传输速率（比特率）
    CBP_EXTERN NSString * const CyberPlayerGotNetworkBitrateNotification;
 
 通知发送时间：
 
 * 当播放器发送CyberPlayerLoadDidPreparedNotificationt通知时，isPreparedToPlay属性将为YES。同时naturalSize、videoHeight、videoWidth、duration属性值有效。
 * 以下多种情况会发送CyberPlayerPlaybackDidFinishNotification通知：
    * 当调用stop停止视频；
    * 视频正常播放完成；
    * 视频播放失败；
    * 调用prepareToPlay初始化视频文件失败。
 * 当播放网络视频文件时，开始进行缓冲则发送CyberPlayerStartCachingNotification通知。网络视频播放过程中该通知会在以下几种情况下触发：
    * 网络状况不佳；
    * 调用了[seekTo]([CyberPlayerController seekTo:])方法；
    * 设置了[currentPlaybackTime]([CyberPlayerController currentPlaybackTime])属性。
 * 以下多种情况会发生CyberPlayerPlaybackErrorNotification通知，失败原因请参考CBPErrorCode失败类型：
    * 调用prepareToPlay初始化视频文件失败；
    * 播放过程中播放失败；
 * 当调用了[seekTo]([CyberPlayerController seekTo:])方法或者设置了[currentPlaybackTime]([CyberPlayerController currentPlaybackTime])属性，则将播放位置切换到指定位置。如果切换位置完成，则发送CyberPlayerPlaybackDidFinishNotification通知。如果新位置切换不成功，则将导致播放失败并发送CyberPlayerPlaybackErrorNotification通知。
 * 播放状态[playbackState]([CyberPlayerController playbackState])类型请见CBPMoviePlaybackState，如果发生改变则发送CyberPlayerPlaybackStateDidChangeNotification通知。建议开发者监听该通知，并根据播放状态[playbackState]([CyberPlayerController playbackState])属性不同更新相关UI状态显示。
 * 当视频文件只包含音频信息时发送CyberPlayerMeidaTypeAudioOnlyNotification通知。
 
 @discussion prepareToPlay实现逻辑如下：
 
 * 当调用[play]([CyberPlayerController play])或[start]([CyberPlayerController start])方法前未调用prepareToPlay完成播放器对视频文件的初始化，则播放器自动调用prepareToPlay进行视频文件的初始化工作。
 * 当调用prepareToPlay方法前，视频正在播前视频，则播放器自动调用[stop]([CyberPlayerController stop])方法停止当前视频播放，当视频停止后立即开始调用prepareToPlay方法。
 *  prepareToPlay完成时，播放器发送CyberPlayerLoadDidPreparedNotification通知并将[isPreparedToPlay]([CyberPlayerController isPreparedToPlay])属性置为YES，此时播放器状态为CBPMoviePlaybackStatePrepared。
 * 如果prepareToPlay初始化失败，则发送CyberPlayerPlaybackErrorNotification，此时播放器状态为CBPMoviePlaybackStateStopped。CyberPlayerPlaybackErrorNotification通知中带有CBPErrorCode类型常量，表征初始化失败的原因。
 * 如果prepareToPlay完成，且[shouldAutoplay]([CyberPlayerController shouldAutoplay])属性为YES，则播放器自动调用[start]([CyberPlayerController start])或[play]([CyberPlayerController play])方法开始播放视频。
 * 如果prepareToPlay完成，且[shouldAutoplay]([CyberPlayerController shouldAutoplay])属性为NO，需要切换视频播放，需要首先调用[stop]([CyberPlayerController stop])方法停止当前初始化状态。然后调用setContenString或setContenURL方法改变播放视频地址，并重新调用prepareToPlay方法。

 @since Available in CyberPlayerController 1.0 and later.
 */
- (void) prepareToPlay;

/**
 @abstract 播放当前视频，功能和[play]([CyberPlayerController play])一致。
 @discussion start的使用逻辑：
 
 * 如果调用start方法前已经调用[prepareToPlay]([CyberPlayerController prepareToPlay])完成播放器对视频文件的初始化，且[shouldAutoplay]([CyberPlayerController shouldAutoplay])属性为NO，则调用start方法将开始播放当前视频。此时播放器状态为CBPMoviePlaybackStatePlaying。
 * 如果调用start方法前已经调用[prepareToPlay]([CyberPlayerController prepareToPlay])完成播放器对视频文件的初始化，且[shouldAutoplay]([CyberPlayerController shouldAutoplay])属性为YES，则调用start方法将暂停播放当前视频，实现效果和pause一致。
 * 如果调用start方法前未调用[prepareToPlay]([CyberPlayerController prepareToPlay])完成播放器对视频文件的初始化，则播放器自动调用[prepareToPlay]([CyberPlayerController prepareToPlay])进行视频文件的初始化工作。
 * 如果调用start方法前已经调用pause暂停了正在播放的视频，则重新开始启动播放视频。
 @since Available in CyberPlayerController 1.0 and later.
 @see play
 */
- (void) start;

/**
 @abstract 播放当前视频，功能和[start]([CyberPlayerController start])一致。
 @discussion play的使用逻辑：
 
 * 如果调用play方法前已经调用[prepareToPlay]([CyberPlayerController prepareToPlay])完成播放器对视频文件的初始化，且[shouldAutoplay]([CyberPlayerController shouldAutoplay])属性为NO，则调用play方法将开始播放当前视频。此时播放器状态为CBPMoviePlaybackStatePlaying。
 * 如果调用play方法前已经调用[prepareToPlay]([CyberPlayerController prepareToPlay])完成播放器对视频文件的初始化，且[shouldAutoplay]([CyberPlayerController shouldAutoplay])属性为YES，则调用play方法将暂停播放当前视频，实现效果和pause一致。
 * 如果调用play方法前未调用[prepareToPlay]([CyberPlayerController prepareToPlay])完成播放器对视频文件的初始化，则播放器自动调用[prepareToPlay]([CyberPlayerController prepareToPlay])进行视频文件的初始化工作。
 * 如果调用play方法前已经调用pause暂停了正在播放的视频，则重新开始启动播放视频。
 @since Available in CyberPlayerController 1.0 and later.
 @see start
 */
- (void) play;

/**
 @abstract 结束当前视频的播放。
 @discussion 调用stop结束当前播放，如果需要重新播放该视频，需要调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法。
 调用stop方法后，播放器开始进入关闭当前播放的操作，操作完成将发送CyberPlayerPlaybackDidFinishNotification通知。
 @since Available in CyberPlayerController 1.0 and later.
 */
- (void) stop;

/**
 @abstract 暂停播放当前视频。
 @discussion pause调用逻辑：
 
 * 如果当前视频播放已经暂停，调用该方法将不产生任何效果。
 * 重新回到播放状态，需要调用[play]([CyberPlayerController play])或[start]([CyberPlayerController start])方法。
 * 如果调用pause方法后视频暂停播放，此时播放器状态处于CBPMoviePlaybackStatePaused。
 * 播放器内部监听了UIApplicationWillEnterForegroundNotification通知，该通知发生时如果视频仍然在播放，将自动调用pause暂停当前视频播放。
 @since Available in CyberPlayerController 1.0 and later.
 */
- (void) pause;

/**
 @abstract 设置显示字幕或者隐藏字幕。
 @discussion setSubtitleVisibility调用逻辑：
 
 * 在start之后开始使用。默认为显示字幕（如果有内置或者外挂字幕）。
 * 可以多次调用来切换字幕显示与隐藏。
 * 如果退出播放，则重置为显示字幕。
 * 0为隐藏字幕，1为显示字幕
 @since Available in CyberPlayerController 1.3.3 and later.
 */
- (void) setSubtitleVisibility:(int) isShow;

/**
 @abstract 设置字幕颜色。
 @discussion setSubtitleColor调用逻辑：
 * 字体颜色格式为 RGBA,iColor= (R<<24)|(G<<16)|(B<<8)|(A)
 * (1) iColor 的使用请查询 RGB 列表进行设置。
 * (2) 不管播放内核在播放还是暂停状态,都可以调用此函数。
 * (3) 默认值为字幕编码格式中的颜色。
 * (4) RGBA 的 A 表示透明度,0 为不透明,255 为最透明。建议为 0。
 * (5) 参考值颜色列表:
 红色: RGBA-> 238 0 0 0 绿色:RGBA-> 0 255 0 0 蓝色:RGBA-> 0 0 255 0
 @since Available in CyberPlayerController 1.0 and later.
 */
- (void) setSubtitleColor:(int) iColor;

/**
 @abstract 设置字幕字体的比例。
 @discussion setSubtitleFontScale调用逻辑：
 @parameter: iColor:￼ 字体缩放比例倍数。
 * (1) 字体可以缩小或者放大,比例为整数后一个小数点,比如 1.1、1.8、0.5、0.9 等。 
 * (2) 不管播放内核在播放还是暂停状态,都可以调用此函数。
 * (3) 默认值为 1.0.
 @since Available in CyberPlayerController 1.0 and later.
 */
- (void) setSubtitleFontScale:(float) fFontScale;

/**
 @abstract 设置字幕在屏幕中显示时候对齐的位置。
 @discussion setSubtitleAlignMethod调用逻辑：
 @parameter: iAlignMethod 的取值如下：
 * 屏幕左下角          : iAlignMethod=1;
 * 屏幕底部中(默认位置) : iAlignMethod=2;
 * 屏幕右下角          : iAlignMethod=3;
 * 屏幕左上角          : iAlignMethod=5;
 * 屏幕顶部中          : iAlignMethod=6;
 * 屏幕右上角          : iAlignMethod=7;
 * 屏幕中部靠左        : iAlignMethod=9;
 * 屏幕正中间          : iAlignMethod=10;
 * 屏幕中部靠右        : iAlignMethod=11;
 @since Available in CyberPlayerController 1.0 and later.
 */
- (void) setSubtitleAlignMethod:(int) iAlignMethod;

/**
 @abstract 手动微调字幕的时间。
 @discussion manualSyncSubtitle调用逻辑：
 @parameter: mSec : 字幕显示时间往前(负数)往后(正数)调整的毫秒数。
 * (1) 在观看视频过程中,如果字幕显示跟视频有延时或者提前,则可以使用此方法进 调节。
 * (2) 默认值为 0。
 @since Available in CyberPlayerController 1.0 and later.
 */
- (void) manualSyncSubtitle:(int) mSec;

/**
 @abstract 改变当前视频的播放位置，单位为秒。
 @param newPos 指定新的播放位置。
 @discussion seekto:调用逻辑,

 * 当isPreparedToPlay属性值为NO时，调用seekto方法将改变initialPlaybackTime属性值。当播放器完成视频的初始化工作后（此时isPreparedToPlay属性为YES），将从seekto方法指定的位置开始播放视频。
 * 当播放视频过程中调用seekTo，将导致从指定位置开始播放。如果当前视频为网络视频，可能触发缓冲CyberPlayerStartCachingNotification通知。如果希望在UI反应缓冲进度，请监听CyberPlayerGotCachePercentNotification通知。
 * 当[accurateSeeking]([CyberPlayerController accurateSeeking])属性为YES时，将执行精确seek。否则将newPos进行取整，以秒为单位执行seek操作。
 @since Available in CyberPlayerController 1.0 and later.
 @see currentPlaybackTime
 */
- (void) seekTo: (NSTimeInterval) newPos;

/**
 @abstract depredated! 设置开发者API key。
 @param ak 开发者应用的API Key。
 @param sk 开发者应用的Secret Key的前16位。
 @discussion 开发者需要使用百度账号登录[百度开发者中心](http://developer.baidu.com/)注册成为百度开发者并创建应用，方可获取应用ID对应的API Key（即：ak）及Secret Key（即：sk）等信息。具体信息，请参考[百度开发者中心](http://developer.baidu.com/)上的“[创建应用](http://developer.baidu.com/wiki/index.php?title=docs/pcs/guide/app_create)”的相关介绍。
 使用CyberPlayerController SDK必须传入ak 及sk（只需前16位）参数。如果传入的sk长度大于16位则默认采取前16位。
 如果未传入ak/sk，或者ak/sk错误，将导致播放行为失败并打印`“Authentication fails!”`。
 @since Available in CyberPlayerController 1.0 and later.
 */

+ (void) setBAEAPIKey:(NSString*)ak SecretKey:(NSString*)sk NS_DEPRECATED_IOS(1.0, 1.0);

/**
 @abstract 设置百度开放云开发者的Access key。
 @param ak 开发者的Access Key。
 @discussion CyberPlayerController与百度开放云的账户系统绑定。使用CyberPlayerController App需要传入开发者的Access Key参数。如果未传入Access Key，或者Access Key错误，播放器将在视频画面右上方打印告警信息，并且播放行为统计功能将失效。
 开发者需要在[百度开放云](http://bce.baidu.com)注册账户并且通过实名认证，方可获取对应的Access Key。具体信息，请参考[操作指南 管理ACCESSKEY](http://bce.baidu.com/doc/BOS/GettingStarted.html#.E7.AE.A1.E7.90.86ACCESSKEY)”的相关介绍。
 @since Available in CyberPlayerController 1.3.11 and later.
 */
- (void) setAccessKey:(NSString*)ak;

/**
 @abstract 获取SDK版本号。
 @return 返回NSString类型的版本号。
 @discussion 当开发者反馈问题时，请使用该方法获得SDK版本号并随同问题一起反馈。
 @since Available in CyberPlayerController 1.0 and later.
 */
- (NSString *) getSDKVersion;

/**
 @abstract 增加传入自定义 http header 接口。
 @param httpHeadBuffer 自定义的httpHead。多个参数使用\r\n分隔，实例：@"Pragma: no-cache\r\nRetry-After: 120\r\n"
 */
- (void)setCustomHttpHeader:(NSString*)httpHeadBuffer;

/**
 @abstract 设置log打印级别。
 @param value 自定义的log打印级别。0~5,default is 0, 0:NO_LOG 1:ERROR 2:WARNNING 3:INFO 4:DEBUG 5:VERBOSE
 */
- (void)setLogLevel:(int)value;

/**
 @abstract 增加传入自定义 userAgent 接口。
 @param userAgent 自定义的userAgent。
 */
- (void)setUserAgent:(NSString*)userAgent;

/**
 @abstract 增加传入自定义 parametKey 接口。
 @param parametKey 自定义的parametKey。
 */
- (void)setParametKey:(NSString*)parametKey;

/**
 @abstract 在播放前设定外挂字幕的url或本地外挂字幕地址 ExternalSubtitleFilePath 接口。
 @param subFilePath 自定义的ExternalSubtitleFilePath。
 */
- (void)setExtSubtitleFile:(NSString*)subFilePath;

/**
 @abstract （1）在播放过程中打开 ExternalSubtitleFilePath 接口。（2）在播放过程中切换不同的外挂字幕。
 @param subFilePath 自定义的ExternalSubtitleFilePath。
 @return value:0:成功; <0:失败。 
 @其中:  -1:字体文件不存在
 @      -2:有内置字幕,外挂字幕将被忽略
 @      -3:url 或本地文件地址无效或不存在。
 @      -4:player 状态不正确
 @      -5:切换字幕时,url 或本地播放文件跟已经播放的字幕相同,无法切换。
 */
- (int)openExtSubtitleFile:(NSString*)subFilePath;

/**
 @abstract 在播放HLS多码率视频时，查询所支持的码率列表
 @discussion 当播放器完成视频格式解析，准备播放之后。
 @since Available in CyberPlayerController 1.3.14 and later.
 @warning 在播放器的状态不是CBPMoviePlaybackStatePlaying,CBPMoviePlaybackStatePaused时，将返回nil。
 @see
 */
- (NSArray*) getSupportedBitrates;

/**
 @abstract 在播放HLS多码率视频时，查询所支持的分辨率
 @discussion 当播放器完成视频格式解析，准备播放之后。
 @since Available in CyberPlayerController 1.3.14 and later.
 @warning 在播放器的状态不是CBPMoviePlaybackStatePrepared, CBPMoviePlaybackStatePlaying,CBPMoviePlaybackStatePaused时，将返回nil。
 @see
 */
- (NSArray*) getSupportedResolution;

/**
 @abstract 在播放HLS多码率视频时，返回当前码率的索引(0-based)
 @discussion 当播放器完成视频格式解析，准备播放之后。
 @since Available in CyberPlayerController 1.3.14 and later.
 @warning 在播放器的状态不是CBPMoviePlaybackStatePrepared, CBPMoviePlaybackStatePlaying,CBPMoviePlaybackStatePaused时，将返回nil。
 @see
 */
- (int) getBitrateIndex;

/**
 @abstract 在播放HLS多码率视频时，设置当前码率的索引(0-based)
 @discussion 当播放器完成视频格式解析，准备播放之后。
 @since Available in CyberPlayerController 1.3.14 and later.
 @warning 在播放器的状态不是CBPMoviePlaybackStatePrepared, CBPMoviePlaybackStatePlaying,CBPMoviePlaybackStatePaused时，将返回nil。
 @see
 */
- (void) selectBitrate:(int) index;

/**
 @abstract 得到的视频文件实际的URL地址.
 @discussion 当播放器正在播放视频时，调用此方法。
 @since Available in CyberPlayerController 1.3.5 and later.
 @warning 在播放器的状态不是CBPMoviePlaybackStatePlaying,CBPMoviePlaybackStatePaused时，将不会返回正确的url。
 @see
 */
- (NSString *) getCurrentPlayingUrl;

/**
 @abstract 视频文件的URL地址，该地址可以是本地地址或者服务器地址。使用contenString也能设置视频播放地址.
 @discussion 当播放器正在播放视频时，设置contenURL将不会导致播放新视频。如果希望播放新视频，需要调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法.
 @since Available in CyberPlayerController 1.0 and later.
 @warning CyberPlayerController当前并不支持播放百度影音资源（bdhd://开头的视频资源）.
 @see contentString
 */
@property(nonatomic, copy)      NSURL *contentURL;

/**
 @abstract 视频文件的URL地址，该地址可以是本地地址或者服务器地址。使用contenURL也能设置视频播放地址。
 @discussion 当播放器正在播放视频时，设置contenString将不会导致播放新视频。如果希望播放新视频，需要调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法。
 @since Available in CyberPlayerController 1.0 and later.
 @warning CyberPlayerController 当前版本不支持百度影音资源（bdhd://开头的视频资源）。
 @see contentURL
 */
@property(nonatomic, copy)      NSString *contentString;
/**
 @abstract 是否开启杜比音效
 @discussion 杜比音效默认关闭，首次调用[prepareToPlay]([CyberPlayerController prepareToPlay])有效，后续对属性的更改无效。如果需要重新有效更改该属性，需要重启APP。
 @since Available in CyberPlayerController 1.1 and later.
 @warning 仅支持百度内部产品线
 */
@property(nonatomic) BOOL       dolbyEnabled;
/**
 @abstract 包含视频内容的view。
 @discussion 当前版本view内只有视频帧图像，没有控制相关组件。
             相当于iOS系统播放器MPMoviePlayerController的控制方式controlStyle为MPMovieControlStyleNone的效果。
 @since Available in CyberPlayerController 1.0 and later.
 */
@property(nonatomic, readonly)  UIView *view;

/**
 @abstract 当前视频是否完成初始化（只读）。
 @discussion isPreparedToPlay值的更改逻辑：
 
 * 当调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法后，如果播放器完成该视频的初始化，则会发送CyberPlayerLoadDidPreparedNotification通知，并将isPreparedToPlay置为YES。
 * 当调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法后，如果播放器初始化失败，则发送CyberPlayerPlaybackErrorNotification，此时isPreparedToPlay值为NO。
 @since Available in CyberPlayerController 1.0 and later.
 @see prepareToPlay
 */
@property(nonatomic, readonly)  BOOL isPreparedToPlay;
/**
 @abstract 当前播放器的播放状态（只读）。
 @discussion 播放状态共5种状态，请见数据类型CBPMoviePlaybackState。

    枚举数据类型，视频播放状态。
    enum {
        CBPMoviePlaybackStateStopped,
        CBPMoviePlaybackStatePlaying,
        CBPMoviePlaybackStatePaused,
        CBPMoviePlaybackStateInterrupted,
        CBPMoviePlaybackStatePrepared 
    };
    typedef NSInteger CBPMoviePlaybackState;

 播放器状态说明：
 
 * CBPMoviePlaybackStateStopped，播放器处于停止状态。
 * CBPMoviePlaybackStatePlaying，播放器正在播放视频。
 * CBPMoviePlaybackStatePaused，播放器处于播放暂停状态，需要调用start或play重新回到播放状态。
 * CBPMoviePlaybackStateInterrupte，播放器由于内部原因中断播放。
 * CBPMoviePlaybackStatePrepared，播放器完成对视频的初始化。
 
 @discussion 播放状态变换逻辑：

 * 播放器初始化完成后处于CBPMoviePlaybackStateStopped状态，调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法，如果完成对视频文件的初始化则进入CBPMoviePlaybackStatePrepared状态，如果对视频文件的初始化失败则进入CBPMoviePlaybackStateStopped状态。
 * 当播放器处于CBPMoviePlaybackStatePrepared状态，调用[start]([CyberPlayerController start])或[play]([CyberPlayerController play])方法进入CBPMoviePlaybackStatePlaying状态；调用[stop]([CyberPlayerController stop])方法回到CBPMoviePlaybackStateStopped状态。

 @since Available in CyberPlayerController 1.0 and later.
 */
@property(nonatomic, readonly)  CBPMoviePlaybackState playbackState;
/**
 @abstract 当前显示模式。
 
    枚举数据类型，视频显示时的缩放模式。
    enum {
        CBPMovieScalingModeNone,       // 无缩放
        CBPMovieScalingModeAspectFit,  // 同比适配，某个方向会有黑边
        CBPMovieScalingModeAspectFill, // 同比填充，某个方向的显示内容可能被裁剪
        CBPMovieScalingModeAspect_5_4, // 5:4比例播放
        CBPMovieScalingModeAspect_4_3, // 4:3比例播放
        CBPMovieScalingModeAspect_16_9, // 16:9比例播放
        CBPMovieScalingModeFill         // 满屏填充，与原始视频比例不一致
    };
    typedef NSInteger CBPMovieScalingMode;

 @discussion 显示模式共5种，请见数据类型CBPMovieScalingMode。默认模式为CBPMovieScalingModeAspectFit，同比适配，某个方向会有黑边。
 @since Available in CyberPlayerController 1.0 and later.
 */
@property(nonatomic)            CBPMovieScalingMode scalingMode;
/**
 @abstract 播放视频的当前时刻，单位为秒。
 @discussion currentPlaybackTime属性更改时机：
 
 * 视频正常播放时，如果改变currentPlaybackTime的值，将导致播放行为跳转到新的currentPlaybackTime位置播放，实现效果和调用[seekTo]([CyberPlayerController seekTo:])方法一致。
 * 如果在视频未播放前设置currentPlaybackTime的值，将导致播放时刻从currentPlaybackTime位置播放，实现效果和设置[initialPlaybackTime]([CyberPlayerController initialPlaybackTime])属性一致。
 * 当[accuratePostion]([CyberPlayerController accuratePostion])属性为YES时，将获取到精确的当前播放位置。
 @warning 当播放HLS视频源并且[accuratePostion]([CyberPlayerController accuratePostion])属性为YES时获取到的视频当前位置可能出现异常。
 @since Available in CyberPlayerController 1.0 and later.
 @see seekTo:
 @see initialPlaybackTime
 */
@property(nonatomic)            NSTimeInterval currentPlaybackTime;
/**
 @abstract 视频播放启动时的播放时刻，单位为秒。
 @discussion 当视频未开始播放时（此时[isPreparedToPlay]([CyberPlayerController isPreparedToPlay])属性为NO），为了实现改变视频播放的初始时刻，三种方式都可以达到相同效果：
 
 * 设置[initialPlaybackTime]([CyberPlayerController initialPlaybackTime])属性;
 * 设置[currentPlaybackTime]([CyberPlayerController currentPlaybackTime])属性:
 * 调用[seekTo]([CyberPlayerController seekTo:])方法。
 @since Available in CyberPlayerController 1.0 and later.
 */
@property(nonatomic)            NSTimeInterval initialPlaybackTime;

/**
 @abstract 当前视频的高（只读）。
 @discussion 当调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法后，并不能立即获得videoHeight的值（默认视频高为0）。只有播放器发送CyberPlayerLoadDidPreparedNotification通知后，videoHeight值才有效，你可以监听CyberPlayerLoadDidPreparedNotification来获取videoHeight的值。这也意味着[isPreparedToPlay]([CyberPlayerController isPreparedToPlay])值为YES时，videoHeight值才有效。
 @since Available in CyberPlayerController 1.0 and later.
 @see naturalSize
 */
@property(nonatomic, readonly)  int videoHeight;
/**
 @abstract 当前视频的宽（只读）。
 @discussion 当调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法后，并不能立即获得videoWidth的值（默认视频高为0）。只有播放器发送CyberPlayerLoadDidPreparedNotification通知后，videoWidth值才有效，你可以监听CyberPlayerLoadDidPreparedNotification来获取videoWidth的值。这也意味着[isPreparedToPlay]([CyberPlayerController isPreparedToPlay])值为YES时，videoWidth值才有效。
 @since Available in CyberPlayerController 1.0 and later.
 @see naturalSize
 */
@property(nonatomic, readonly)  int videoWidth;
/**
 @abstract 当前视频的长宽（只读）。
 @discussion 当调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法后，并不能立即获得naturalSize的值（默认长宽都为0）。只有播放器发送CyberPlayerLoadDidPreparedNotification通知后，naturalSize值才有效，你可以监听CyberPlayerLoadDidPreparedNotification来获取naturalSize的值。这也意味着[isPreparedToPlay]([CyberPlayerController isPreparedToPlay])值为YES时，naturalSize值才有效。
 @since Available in CyberPlayerController 1.0 and later.
 @see videoWidth
 @see videoHeight
 */
@property(nonatomic, readonly)  CGSize naturalSize;
/**
 @abstract 视频的总时长，单位为秒。
 @discussion duraton的获取时机：
 
 * 当调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法后，并不能立即获得duration的值（默认视频时长为0）。只有播放器发送CyberPlayerLoadDidPreparedNotification通知后，duration值才有效，你可以监听CyberPlayerLoadDidPreparedNotification来获取duration的值。这也意味着[isPreparedToPlay]([CyberPlayerController isPreparedToPlay])值为YES时，duration值才有效。
 * 当播放网络视频时，视频时长duration的值可能会变化。
 * 如果播放直播视频，duration值恒定为0。
 @since Available in CyberPlayerController 1.0 and later.
 */
@property(nonatomic, readonly)  NSTimeInterval duration;
/**
 @abstract 当前可播放视频的长度（只读），单位为秒。
 @discussion 当播放网络视频时，playableDuration值标记着已经加载视频的最大时长（单位为秒），也就是说如果此刻断开网络，视频播放只能到playableDuration时刻。此变量只针对视频有效，对于音频无效。
 @since Available in CyberPlayerController 1.0 and later.
 */
@property(nonatomic, readonly)  NSTimeInterval playableDuration;
/**
 @abstract 播放视频时是否需要自动播放，默认值为YES。
 @discussion 如果shouldAutoplay值为YES，则调用[prepareToPlay]([CyberPlayerController prepareToPlay])方法后，播放器完成初始化后将自动调用[play]([CyberPlayerController play])方法播放视频。如果shouldAutoplay值为NO，则播放器完成初始化后将等待外部调用[play]([CyberPlayerController play])方法或者[start]([CyberPlayerController start])方法。
 开发者可以监听播放器发送的CyberPlayerLoadDidPreparedNotification通知。在收到该通知后进行其他操作并主动调用[play]([CyberPlayerController play])或[start]([CyberPlayerController start])方法开启播放。
 @since Available in CyberPlayerController 1.0 and later.
 */
@property(nonatomic)            BOOL shouldAutoplay;
/**
 @abstract 是否自动清除残留图像，默认值为NO。
 @discussion 当播放完成时，屏幕上将有部分图像残留，该属性为YES时，视频播放完成后将把视频图像清除并置为黑色。
 @since Available in CyberPlayerController 1.1 and later.
 */
@property(nonatomic)            BOOL shouldAutoClearRender;
/**
 @abstract 是否暂停时缓冲网络视频，默认值为YES。
 @discussion 暂停播放时默认在后台缓冲网络视频，在3G等计算流量的环境下建议关闭。
 @since Available in CyberPlayerController 1.2 and later.
 */
@property(nonatomic)            BOOL shouldPauseCaching;
/**
 @abstract 当前视频在打开时估计的播放长度（只读），单位为秒。
 @discussion 主要针对百度媒体云实时转码，infoDuration标记着该视频的完整时长（单位为秒）。
 @since Available in CyberPlayerController 1.2 and later.
 */
@property(nonatomic, readonly)  NSTimeInterval infoDuration;
/**
 @abstract 当前网络视频播放过程中的下载速度。
 @discussion 网络下载速度（单位为k bytes/秒）。
 @since Available in CyberPlayerController 1.2 and later.
 */
@property(nonatomic, readonly)  double downloadSpeed;

/**
 @abstract seek内部实现是否使用毫秒精确seek，默认值为NO.
 @discussion 播放器内部默认采用秒为单位seek。
 @since Available in CyberPlayerController 1.2 and later.
 */
@property(nonatomic)            BOOL accurateSeeking;
/**
 @abstract 视频当前播放位置获取是否使用毫秒精确获取，默认值为NO.
 @discussion 播放器内部默认采用秒为单位获取视频时长。
 @warning 当播放HLS视频源时，使用精确获取到的视频当前位置可能出现异常。
 @since Available in CyberPlayerController 1.2 and later.
 */
@property(nonatomic)            BOOL accuratePostion;
/**
 @abstract 缓存的时候，播放器会暂停一段时间。此参数定义暂停的时长，以秒为单位。默认值为1秒
 @discussion 播放直播视频场景下，带宽高的时候，建议降低缓存以降低延迟；带宽低的时候，提高缓存以提高播放流畅度。
 @since Available in CyberPlayerController 1.3.13 and later.
 */
@property(nonatomic, assign)  float cachePauseTimeInSeconds;

@end
#endif
