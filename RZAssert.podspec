Pod::Spec.new do |s|
  s.name             = "RZAssert"
  s.version          = "0.1.0"
  s.summary          = "A short description of RZAssert."
  s.description      = <<-DESC
                       An optional longer description of RZAssert

                       * Markdown format.
                       * Don't worry about the indent, we strip it!
                       DESC
  s.homepage         = "https://github.com/Raizlabs/RZAssert"
  s.license          = 'MIT'
  s.author           = { "Michael Gorbach" => "michael.gorbach@raizlabs.com" }
  s.source           = { :git => "https://github.com/Raizlabs/RZAssert.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/raizlabs'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes'
  s.resource_bundles = {
    'RZAssert' => ['Pod/Assets/*.png']
  }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end

