RZAssert
============

[![Build Status](https://travis-ci.org/Raizlabs/RZAssert.svg)](https://travis-ci.org/Raizlabs/RZAssert)

RZAssert adds ease of implementation and clarity of intent to your assertions. RZAssert defines macros which—like comments—express intent, but they never go out of date because they are checked by the compiler. `RZ_ASSERT_TRUE`, `RZ_ASSERT_FALSE`, `RZASSERT_NOT_NIL`, and `RZASSERT_NONEMPTY_STRING` all do exactly what you think they do, and they pass helpful messages along to `NSAssert`.

RZAssert also includes more exciting assertions that come in handy in a variety of contexts. Some examples:

1. You define a method on a class, but you want that method to ONLY be called by subclasses. Use `RZASSERT_SUBCLASSES_MUST_OVERRIDE` to throw an exception if the method is called from the base class directly:

    ```objc
    @implementation RZSuperclass

    - (void)aMethodThatShouldBeCalledFromSubclassesOnly
    {
        RZASSERT_SUBCLASSES_MUST_OVERRIDE;
    }

    @end
    ```

1. You define a switch statement with a case that should never occur. Use `RZASSERT_SHOULD_NEVER_GET_HERE` to throw an exception if your program passes the undesired case to the switch statement:

    ```objc
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
                }
                case INVAwesomeModeIsAwesome: {
                    [self doAwesomeStuff];
                    break;
                }
            }
    }

    @end
     ```

1. You define a method which takes an object as one of its arguments, and you want to confirm that the object conforms to a specific protocol. Use `RZASSERT_CONFORMS_PROTOCOL` to throw an exception if the program passes a nonconformant instance to the method:

    ```objc
    - (void)configureWithDictionary:(RZMyViewController *)myViewController
    {
        RZASSERT_CONFORMS_PROTOCOL(myViewController, @protocol(RZMyDelegate));
    }
    ```

## Custom Logging

It is generally recommend that you disable assertions in your production builds. However, this means that code paths that would have thrown a useful assertion in testing are silently run on your users’ devices, potentially resulting in unknown crashes. It can be frustrating to receive crash logs that are missing a crucial piece of information that an assertion would have provided.

RZAssert fixes this by providing a facility to run custom logging code in production where you would have hit an assertion in testing. Run this code once, somewhere like in `-application:didFinishLaunchingWithOptions:`:

```objc
[RZAssert configureWithLoggingHandler:^(NSString *message) {
   [MyCoolLoggingHandler logMessage:@"Hit assertion: %@", message];
}];
```

Once you have configured a logging handler block, if the code is compiled with assertions disabled, all your calls to the RZAssert macros will automatically log to your own logging handler instead. This is great to use with a breadcrumb system, so you can get clues about what happened that may have led to a later crash.

### Warning About `NS_BLOCK_ASSERTIONS`
You may have some code like this:

```objc
#if !defined(NS_BLOCK_ASSERTIONS)
    MyClass *foo = self.bar.baz; // This is unused if the next is gone
    RZASSERT_NOT_NIL(foo); // This line is gone when assertions are disabled
#endif
```

This is to avoid the compiler complaining that `foo` is unused when you compile with assertions disabled. However, if you want your RZAssert calls to be turned into logs in release builds, don’t wrap any assertions in checks for `NS_BLOCK_ASSERTIONS`, because you always want them to run. Save `NS_BLOCK_ASSERTIONS` checks for expensive tests that you really only want to run at debug time.

## Usage

To run the example project, type `pod try RZAssert` and then run the example project. There are two different behaviors of assertions:

1. Throw an exception (and therefore crash) on assert.
1. Log the assertion with the logger of your choice, and don’t crash.

To see both of these behaviors, go into the example project's build settings, and try changing **Enable Foundation Assertions** to `YES` or `NO` for **Debug** builds. Then, run the example app and click any of the buttons. With assertions enabled, the app will crash. With assertions disabled, you will see a message logged to the console.

## Installation

RZAssert is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod RZAssert
```

## Author

Michael Gorbach, michael.gorbach@raizlabs.com

## License

See the LICENSE file for more info.
