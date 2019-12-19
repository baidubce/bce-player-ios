# Baidu Cloud Player iOS SDK

百度云播放器iOS SDK提供Cocoapods支持，分为2种SDK：

* BaiduBCEPlayerLSS: 针对直播场景的精减SDK
* BaiduBCEPlayerFull: 全功能的SDK

开发者可以按需选择。

## 接入

### 接入精减SDK
在Podfile的target中添加依赖:
```ruby
pod 'BaiduBCEPlayerLSS', '~> 2.3.4'
```

### 接入全功能SDK
* 在Podfile的target中添加依赖:
```ruby
pod 'BaiduBCEPlayerFull', "~> 2.3.4"
```

关于SDK的`接口文档`，请移步[百度云官网](https://cloud.baidu.com/doc/Downloadcenter/player.html#.E6.92.AD.E6.94.BE.E5.99.A8iOS.20SDK)

## 备注：

* pod 版本支持百度云播放器所有功能，对SDK包体积有要求且有部分功能不使用，请参考百度云官网去掉对应的依赖。
* openssl失败解决：
    * 下载失败：
        * 更新cocoapods-downloader到1.2.0版本。
            * sudo gem uninstall cocoapods-downloader
            * sudo gem install cocoapods-downloader -v 1.2.0
            * rm -rf /tmp/openssl
    * 编译失败：
        * 从[苹果官网](https://developer.apple.com/download/more/)下载安装：Command_Line_Tools_macOS_10.14_for_Xcode_10.1