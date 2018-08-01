PROJ_PATH="Example/RZAssert.xcodeproj"
WORKSPACE_PATH="Example/RZAssert.xcworkspace"
TEST_SCHEME="RZAssertTests"

#
# Helpers
#

# run the provided command twice, with ENABLE_NS_ASSERTIONS set to NO and then to YES
def run_xcodebuild_with_and_without_assertions(command)
  assertion_string = " ENABLE_NS_ASSERTIONS=%s"
  
  # run WITHOUT assertions
  sh(command.concat(assertion_string % ["NO"])) rescue nil
  no_assertion_exit = $?.exitstatus
  
  # run WITH assertions
  sh(command.concat(assertion_string % ["YES"])) rescue nil
  assertion_exit = $?.exitstatus
  
  # fail if either command failed
  exit_status = [no_assertion_exit, assertion_exit].max # 0 if both succeeded, else the exit status of one or both
  return exit_status
end

#
# Install
#

namespace :install do
  
  task :tools do
    # don't care if this fails on travis
    sh("brew update") rescue nil
  end
  
end

task :install do
  Rake::Task['install:tools'].invoke
end

#
# Test
#

task :test do
  test_command = "xcodebuild -workspace '#{WORKSPACE_PATH}' -scheme '#{TEST_SCHEME}' -sdk iphonesimulator -destination 'name=iPhone 6' build test"
  exit_status = run_xcodebuild_with_and_without_assertions(test_command)
  exit exit_status
end

#
# Analyze
#

task :analyze do
  analyze_command = "xcodebuild -workspace '#{WORKSPACE_PATH}' -scheme '#{TEST_SCHEME}' -sdk iphonesimulator analyze"
  exit_status = run_xcodebuild_with_and_without_assertions(analyze_command)
  exit exit_status
end

#
# Clean
#

namespace :clean do
  
  task :example do
    sh("xcodebuild -project '#{PROJ_PATH}' -scheme '#{TEST_SCHEME}' -sdk iphonesimulator clean") rescue nil
  end
    
end

task :clean do
  Rake::Task['clean:example'].invoke
end

#
# Utils
#

task :usage do
  puts "Usage:"
  puts "  rake install       -- install all dependencies"
  puts "  rake install:tools -- install build tool dependencies"
  puts "  rake test          -- run unit tests"
  puts "  rake clean         -- clean everything"
  puts "  rake clean:example -- clean the example project build artifacts"
  puts "  rake usage         -- print this message"
end

#
# Default
#

task :default => 'usage'

#
# Private
#

private

def sync_project(path, flags)
  sh("synx #{flags} '#{path}'")
end