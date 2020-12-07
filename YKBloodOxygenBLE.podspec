#
# Be sure to run `pod lib lint YKBloodOxygenBLE.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'YKBloodOxygenBLE'
  s.version          = '0.1.1'
  s.summary          = '血氧仪蓝牙数据传输'

  s.homepage         = 'https://github.com/chenjiangchuan/YKBloodOxygenBLE'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'chenjiangchuan' => 'jiangchuanc@gmail.com' }
  s.source           = { :git => 'https://github.com/chenjiangchuan/YKBloodOxygenBLE.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'
  s.source_files = 'YKBloodOxygenBLE/Classes/*'
  s.public_header_files = 'YKBloodOxygenBLE/Classes/*.h'
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.vendored_frameworks = "YKBloodOxygenBLE/Classes/YKBLE.framework"
end
