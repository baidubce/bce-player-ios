Pod::Spec.new do |s|

  s.name         = 'BaiduBCEPlayerLSSAdvance'
  s.version      = '3.0.0'
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
  s.source   =   { :http => 'https://sdk.bce.baidu.com/media-sdk/Baidu-Cloud-Player-iOS-LSS-Advance-3.0.0.zip',:sha1 => "ba19436b8bc045b90f9e89a797fc8b0c3043befb"}
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
  'vendor/libcrypto.a',
  'vendor/libauthcheck.a',
  'vendor/libwanosdecoder.a'
   s.vendored_frameworks = 
   'frameworks/BDCloudMediaUtils.framework', 
   'frameworks/BDCloudMediaPlayer.framework', 
   'frameworks/BDCloudMediaDownloader.framework', 
   'frameworks/BDCloudMediaSource.framework', 
   'frameworks/BDCloudMediaSprite.framework', 
   'frameworks/BDCloudMediaAdaptive.framework', 
   'frameworks/BDCloudVRRender.framework', 
   'frameworks/BDCloudHdrKit.framework', 
   'frameworks/BaiduRtcPlayerGeneral.framework', 
   'frameworks/BaiduAPMAgent.framework'
   s.frameworks = 'Foundation', 'UIKit', 'AudioToolbox', 'MobileCoreServices', 'GLKit', 'CoreVideo', 'OpenGLES'
   s.libraries = 'bz2', 'z', 'c++'
end
