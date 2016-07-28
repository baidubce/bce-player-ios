Pod::Spec.new do |s|

  s.name         = 'BaiduBCEPlayerFull'
  s.version      = '1.6.0'
  s.summary      = 'Baidu BCE iOS Player SDK'
  s.homepage     = 'https://bce.baidu.com/doc/MCT/iOS-Player-SDK.html'
  s.license      = {
    :type => 'Proprietary',
    :text => <<-LICENSE
         Copyright (c) 2016 Baidu.com, Inc. All Rights Reserved.
         LICENSE
  }
  s.description  = <<-DESC
    Baidu BCE iOS Player SDK supoort iOS 7.0 and later,
  DESC
  s.author   =   { 'bailu' => 'bailu07@baidu.com' }
  s.source   =   { :git => 'https://github.com/baidubce/bce-player-ios.git',:tag=>s.version.to_s}
  s.ios.deployment_target = '7.0'
  s.requires_arc = true
  s.source_files = 'include/*.h'
  s.vendored_libraries = 'lib/Full/libCyberPlayerController.a', 'lib/Full/libCyberDownloader.a'
  s.frameworks = 'Foundation', 'UIKit', 'AudioToolbox', 'MobileCoreServices'
  s.dependency 'OpenSSL', '~> 1.0'
  s.libraries = 'bz2', 'z'
end
