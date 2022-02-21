Pod::Spec.new do |s|
  s.name         = "GoldenMapSDK"
  s.version      = "22.02.21"
  s.summary      = "GoldenMapSDK for iOS"
  s.homepage     = "https://github.com/GoldenMap/GoldenMapSDK"
  s.author       = { "BeiJing GuangYiHengXin Technology Co. Ltd" => "michael@guangyihengxin.com" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.source       = { :git => "https://github.com/GoldenMap/GoldenMapSDK.git", :tag => s.version.to_s }
  s.source_files  = 'GoldenMapSDK/Headers/*.{h}'
  s.preserve_paths = 'GoldenMapSDK/libGoldenMap.a'
  s.vendored_libraries = 'AprilSDK/libGoldenMap.a'
  s.requires_arc = true
  s.xcconfig = { 'LIBRARY_SEARCH_PATHS' => '$(PODS_ROOT)/GoldenMapSDK' }
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2022 BeiJing GuangYiHengXin Technology Co. Ltd All rights reserved.
      LICENSE
  }
end
