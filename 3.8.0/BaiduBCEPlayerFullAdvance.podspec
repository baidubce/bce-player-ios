Pod::Spec.new do |s|

  s.name         = 'BaiduBCEPlayerFullAdvance'
  s.version      = '3.8.0'
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
  s.source   =   { :http => 'https://bce.bdstatic.com/p3m/common-service/uploads/PlayeriOSFULLAdv-3.8.0_5b5cada.zip',:sha1 => "aa61958cdad2b44d320bb934eb1ab5f8c369810c"}
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
  'vendor/libwanosdecoder.a',
  'vendor/libGRF.a',
  'vendor/libdav1d.a'
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
   'frameworks/BaiduAPMAgent.framework',
   'frameworks/ProjectionEngine.framework',
   'frameworks/BDCloudVirtualLiveKit.framework'
   s.frameworks = 'Foundation', 'UIKit', 'AudioToolbox', 'MobileCoreServices', 'GLKit', 'CoreVideo', 'OpenGLES'
  s.libraries = 'bz2', 'z', 'c++'
end
