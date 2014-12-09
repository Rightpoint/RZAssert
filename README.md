RZAssert
============

[![Build Status](https://travis-ci.org/Raizlabs/RZAssert.svg)](https://travis-ci.org/Raizlabs/RZAssert)

`RZAssert` adds ease of implementation and clarity of intent to your assertions. RZAssert defines macros which - like comments - express intent, but never go out of date. `RZ_ASSERT_TRUE`, `RZ_ASSERT_FALSE`, `RZASSERT_NOT_NIL`, and `RZASSERT_NONEMPTY_STRING` all do exactly what you think they do.

`RZAssert` includes more exciting assertions that come in handy in a variety of contexts. For example:

You define a method on a class, but you want that method to ONLY be called by subclasses. Use `RZASSERT_SUBCLASSES_MUST_OVERRIDE` to throw an exception if the method is called from the class itself:

	@implementation RZSuperclass
	
	- (void)aMethodThatShouldBeCalledFromSubclassesOnly
	{
		RZASSERT_SUBCLASSES_MUST_OVERRIDE;
	}

	@end

You define a switch statement with a case that should never occur. Use `RZASSERT_SHOULD_NEVER_GET_HERE` to throw an exception if your program passes the undesired case to the switch statement:

	typedef NS_ENUM(NSInteger, RZAwesomeMode) {
		INVAwesomeModeNotSet = 0,
		INVAwesomeModeIsAwesome
	};

	@implementation RZMyClass

	- (void)configureThingsForAwesomeMode:(RZAwesomeMode)awesomeMode
	{
		switch ( awesomeMode ) {
			case INVAwesomeModeNotSet: {
				RZASSERT_SHOULD_NEVER_GET_HERE;
				break;
	  		case INVAwesomeModeIsAwesome: {
				[self doAwesomeStuff];
				break;
			}
		}
	}

	@end

You define a method which takes a class instance as one of its arguments, and you want to confirm that the instance conforms to a specific protocol. You use `RZASSERT_CONFORMS_PROTOCOL` to throw an exception if the program passes a nonconformant instance to the method:

	- (void)configureThingsForDictionary:(RZAwesomeViewController *)awesomeViewController
	{
		RZASSERT_CONFORMS_PROTOCOL(awesomeViewController, @protocol(RZAwesomeDelegate));
	}

## Usage

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Installation

RZAssert is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

    pod RZAssert, '~> 0.1'

## Author

Michael Gorbach, michael.gorbach@raizlabs.com

## License

See the LICENSE file for more info.
