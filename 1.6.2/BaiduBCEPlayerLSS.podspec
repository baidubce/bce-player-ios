Pod::Spec.new do |s|

  s.name         = 'BaiduBCEPlayerLSS'
  s.version      = '1.6.2'
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
  s.source   =   { :http => 'http://sdk.bce.baidu.com/media-sdk/Baidu-T5Player-SDK-iOS-LSS-1.6.2.zip?responseContentDisposition=attachment',:sha1 => "bed51ca2a412534c54b9a99dba6986ce47c817a6"}
  s.ios.deployment_target = '7.0'
  s.requires_arc = true
  s.source_files = 'include/*.h'

  s.prepare_command = <<-CMD
    VERSION="1.6.2"
    BASEPATH="${PWD}"
    SDKPATH="Baidu-T5Player-SDK-iOS-${VERSION}"

    rm -rf "${BASEPATH}/include"
    rm -rf "${BASEPATH}/lib"
    mkdir -p "${BASEPATH}/include"
    mkdir -p "${BASEPATH}/lib"

    # copy headers
    cp ${SDKPATH}/include/CyberDownloader/*.h "${BASEPATH}/include/"
    cp ${SDKPATH}/include/CyberPlayer/*.h "${BASEPATH}/include/"

    # copy libs
    cp "${SDKPATH}/lib/libCyberDownloader.a" "${BASEPATH}/lib/"
    cp "${SDKPATH}/lib/libCyberPlayerController.a" "${BASEPATH}/lib/"

  CMD

  s.vendored_libraries = 'lib/libCyberPlayerController.a', 'lib/libCyberDownloader.a'
  s.frameworks = 'Foundation', 'UIKit', 'AudioToolbox', 'MobileCoreServices'
  s.dependency 'OpenSSL', '~> 1.0'
  s.libraries = 'bz2', 'z'
end