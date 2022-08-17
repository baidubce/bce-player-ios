Pod::Spec.new do |s|

  s.name         = 'BaiduBCEPlayerFull'
  s.version      = '2.3.7'
  s.summary      = 'Baidu Cloud iOS Player SDK'
  s.homepage     = 'https://cloud.baidu.com/doc/MCT/s/qjwvz50w7/'
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
  s.source   =   { :http => 'http://sdk.bce.baidu.com/media-sdk/Baidu-Cloud-Player-iOS-Full-2.3.7.zip',:sha1 => "7a492955fd303dd3790f65e663473cc1d08825b2"}
  s.ios.deployment_target = '9.0'
  s.requires_arc = true

  s.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  s.user_target_xcconfig = { 
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' 
  }

  s.vendored_libraries = 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/vendor/libffmpeg.a', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/vendor/libssl.a', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/vendor/libcrypto.a'
  s.vendored_frameworks = 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BDCloudMediaUtils.framework', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BDCloudMediaPlayer.framework', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BDCloudMediaDownloader.framework', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BDCloudMediaSource.framework', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BDCloudMediaSprite.framework', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BDCloudMediaAdaptive.framework', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BDCloudVRRender.framework', 
   'Baidu-Cloud-Player-iOS-Full-2.3.7/frameworks/BaiduAPMAgent.framework'
  s.frameworks = 'Foundation', 'UIKit', 'AudioToolbox', 'MobileCoreServices', 'GLKit'
  s.libraries = 'bz2', 'z', 'c++'
end
