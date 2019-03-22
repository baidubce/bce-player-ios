Pod::Spec.new do |s|

  s.name         = 'BaiduBCEPlayerLSS'
  s.version      = '2.2.6'
  s.summary      = 'Baidu Cloud iOS Player SDK'
  s.homepage     = 'https://cloud.baidu.com/doc/MCT/iOS-Player-SDK.html'
  s.license      = {
    :type => 'Proprietary',
    :text => <<-LICENSE
         Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved.
         LICENSE
  }
  s.description  = <<-DESC
    Baidu Cloud iOS Player SDK supoort iOS 7.0 and later,
  DESC
  s.author   =   { 'Baidu Cloud Multimedia Team' => 'bce-multimedia@baidu.com' }
  s.source   =   { :http => 'http://sdk.bce.baidu.com/media-sdk/Baidu-Cloud-Player-iOS-LSS-2.2.6.zip',:sha1 => "c35ee72952f260796267f30a650262640c8bc0de"}
  s.ios.deployment_target = '7.0'
  s.requires_arc = true

  s.prepare_command = <<-CMD
    rm vendor/libssl.a
    rm vendor/libcrypto.a
  CMD

  s.vendored_libraries = 'vendor/libffmpeg.a'
  s.vendored_frameworks = 'frameworks/BDCloudMediaUtils.framework', 'frameworks/BDCloudMediaPlayer.framework', 'frameworks/BDCloudMediaDownloader.framework'
  s.frameworks = 'Foundation', 'UIKit', 'AudioToolbox', 'MobileCoreServices'
  s.dependency 'openssl-ios-bitcode', '~> 1.0.210'
  s.libraries = 'bz2', 'z', 'c++'
end
