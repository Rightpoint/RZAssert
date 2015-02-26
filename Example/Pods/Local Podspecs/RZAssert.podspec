Pod::Spec.new do |s|
  s.name             = "RZAssert"
  s.version          = "1.0.1"
  s.summary          = "Useful assertion macros from the fine folks at Raizlabs."
  s.description      = <<-DESC
                       Assertion macros for a range of conditions. Use RZAssert to confirm equality, class, and much more.
                       DESC
  s.homepage         = "https://github.com/Raizlabs/RZAssert"
  s.license          = 'MIT'
  s.author           = { "Michael Gorbach" => "michael.gorbach@raizlabs.com" }
  s.source           = { :git => "https://github.com/Raizlabs/RZAssert.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/raizlabs'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes'
end

