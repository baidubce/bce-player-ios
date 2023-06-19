Pod::Spec.new do |s|

  s.name         = 'BaiduBCEPlayerLSS'
  s.version      = '3.6.0'
  s.summary      = 'Baidu Cloud iOS Player SDK'
  s.homepage     = 'https://cloud.baidu.com/doc/VideoCreatingSDK/s/yldy7iu7u'
  s.license      = {
    :type => 'Proprietary',
    :text => <<-LICENSE
         Copyright (c) 2018 Baidu.com, Inc. All Rights Reserved.
         LICENSE
  }
  s.description  = <<-DESC
    Baidu Cloud iOS Player SDK supoort iOS 9.0 and later,
  DESC
  s.author   =   { 'Baidu Cloud Multimedia Team' => 'bce-multimedia@baidu.com' }
  s.source   =   { :http => 'https://sdk.bce.baidu.com/media-sdk/Baidu-Cloud-Player-iOS-LSS-3.6.0.zip',:sha1 => "b0e2f42db89ccd7b43e5a1002fe22dfb63efd9d2"}
  s.ios.deployment_target = '9.0'
  s.requires_arc = true

  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' 
  }

  s.vendored_libraries = 
  'vendor/libffmpeg.a', 
  'vendor/libssl.a', 
  'vendor/libcrypto.a'
   s.vendored_frameworks = 
   'frameworks/BDCloudMediaUtils.framework', 
   'frameworks/BDCloudMediaPlayer.framework', 
   'frameworks/BDCloudMediaDownloader.framework', 
   'frameworks/BDCloudMediaSource.framework', 
   'frameworks/BDCloudMediaSprite.framework', 
   'frameworks/BDCloudMediaAdaptive.framework', 
   'frameworks/BaiduAPMAgent.framework'
   s.frameworks = 'Foundation', 'UIKit', 'AudioToolbox', 'MobileCoreServices', 'GLKit'
   s.libraries = 'bz2', 'z', 'c++'
end
