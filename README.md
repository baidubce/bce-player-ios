# Baidu BCE Player iOS SDK

百度开放云播放器iOS SDK提供Cocoapods支持，分为2种SDK：

* 针对直播场景的精减SDK：BaiduBCEPlayerLSS
* 全功能的SDK：BaiduBCEPlayerFull

开发者可以按需选择。

## 接入

### 接入精减SDK
在Podfile的target中添加依赖:
```ruby
pod 'BaiduBCEPlayerLSS',:git=>'https://github.com/baidubce/bce-player-ios.git'
```

### 接入全功能SDK
* 在Podfile的target中添加依赖:
```ruby
pod 'BaiduBCEPlayerFull',:git=>'https://github.com/baidubce/bce-player-ios.git'
```
* 在Podfile结尾加入以下内容:
```ruby
post_install do |installer|
  current_dir = Dir.pwd + "/Pods/BaiduBCEPlayerFull/lib/Full"
  Dir.chdir(current_dir) do
    `unzip -o libCyberPlayerController.a`
  end
end
```

关于SDK的`接口文档`，请移步[百度开放云官网](https://cloud.baidu.com/doc/MCT/iOS-Player-SDK.html)
