# Baidu BCE Player iOS SDK

百度云播放器iOS SDK提供Cocoapods支持，分为2种SDK：

* BaiduBCEPlayerLSS: 针对直播场景的精减SDK
* BaiduBCEPlayerFull: 全功能的SDK

开发者可以按需选择。

## 接入

### 接入精减SDK
在Podfile的target中添加依赖:
```ruby
pod 'BaiduBCEPlayerLSS', "~> 1.0"
```

### 接入全功能SDK
* 在Podfile的target中添加依赖:
```ruby
pod 'BaiduBCEPlayerFull', "~> 1.0"
```

关于SDK的`接口文档`，请移步[百度云官网](https://cloud.baidu.com/doc/MCT/iOS-Player-SDK.html)