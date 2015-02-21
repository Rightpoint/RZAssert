//
//  RZAssert.h
//  RZAssert
//
//  Created by Michael Gorbach on 7/25/14.
//  Copyright (c) 2014 Raizlabs. All rights reserved.
//  http://raizlabs.com/
//
//  Permission is hereby granted, free of charge, to any person obtaining
//  a copy of this software and associated documentation files (the
//  "Software"), to deal in the Software without restriction, including
//  without limitation the rights to use, copy, modify, merge, publish,
//  distribute, sublicense, and/or sell copies of the Software, and to
//  permit persons to whom the Software is furnished to do so, subject to
//  the following conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

@import Foundation;

@interface RZAssert : NSObject

+ (void)configureWithLoggingHandler:(void(^)(NSString *message))loggingHandler;

+ (void)logMessageWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1, 2);

@end

#pragma mark - Basic Assertions

// General Assertions

#define RZASSERT NSAssert


/**
 *  Raise an exception if object is not equal to nil. Return void.
 *
 *  @param object     An object instance to compare with nil.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_NIL(object) \
    do { \
        if ( (object) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Nil Assertion **** \nExpected nil, but " #object @" is not nil \nSelf: \"%@\"", self]; \
        } \
    } while(0)
#else
#define RZASSERT_NIL(object) \
    do { \
        NSAssert((object == nil), @"**** Unexpected Nil Assertion **** \nExpected nil, but " #object @" is not nil \nSelf: \"%@\"", self); \
    } while(0)
#endif


/**
 *  Raise an exception if object is equal to nil. Return void.
 *
 *  @param object     An object instance to compare with nil.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_NOT_NIL(object) \
    do { \
        if ( !(object) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Non-Nil Assertion **** \nExpected not nil, but " #object @" is nil \nSelf: \"%@\"", self]; \
        } \
    } while(0)
#else
#define RZASSERT_NOT_NIL(object) \
    do { \
        NSAssert((object), @"**** Unexpected Non-Nil Assertion **** \nExpected not nil, but " #object @" is nil \nSelf: \"%@\"", self); \
    } while(0)
#endif


/**
 *  Raise an exception. Return void.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_ALWAYS \
    do { \
        [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** \nSelf: \"%@\"", self]; \
    } while(0)
#else
#define RZASSERT_ALWAYS \
    do { \
        NSAssert(NO, @"**** Unexpected Assertion **** \nSelf: \"%@\"", self); \
    } while(0)
#endif

/**
 *  Raise an exception if object evaulates to 0. Return void.
 *
 *  @param object     An object instance to compare with 0.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_TRUE(test) \
    do { \
        if ( !(test) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** \nSelf: \"%@\"", self]; \
        } \
    } while(0)
#else
#define RZASSERT_TRUE(test) \
    do { \
        NSAssert((test), @"**** Unexpected Assertion **** \nSelf: \"%@\"", self); \
    } while(0)
#endif

/**
 *  Raise an exception if object evaluates to 1. Return void.
 *
 *  @param object     An object instance to compare with 1.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_FALSE(test) \
    do { \
        if ( (test) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** \nSelf: \"%@\"", self]; \
        } \
    } while(0)
#else
#define RZASSERT_FALSE(test) \
    do { \
        NSAssert(!(test), @"**** Unexpected Assertion **** \nSelf: \"%@\"", self); \
    } while(0)
#endif

/**
 *  Raise an exception. Return void.
 *
 *  @param message     A printf-style format string that describes the failure condition.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_WITH_MESSAGE(message, ...) \
    do { \
        [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self]; \
    } while(0)
#else
#define RZASSERT_WITH_MESSAGE(message, ...) \
    do { \
        NSAssert(NO, @"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self); \
    } while(0)
#endif

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_WITH_MESSAGE_LOG(expression, message, ...) \
    do { \
        [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** %@ \nExpression: \"%@\" \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self]; \
    } while(0)
#else
#define RZASSERT_WITH_MESSAGE_LOG(expression, message, ...) \
    do { \
        NSAssert(NO, @"**** Unexpected Assertion **** %@ \nExpression: \"%@\" \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self); \
    } while(0)
#endif

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_TRUE_WITH_MESSAGE(test, message, ...) \
    do { \
        if ( !(test) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self]; \
        } \
    } while(0)
#else
#define RZASSERT_TRUE_WITH_MESSAGE(test, message, ...) \
    do { \
        NSAssert(test, @"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self); \
    } while(0)
#endif

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_TRUE_WITH_MESSAGE_LOG(test, expression, message, ...) \
    do { \
        if ( !(test) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** %@ \nReason: \nExpression:\"%@\", \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self]; \
        } \
    } while(0)
#else
#define RZASSERT_TRUE_WITH_MESSAGE_LOG(test, expression, message, ...) \
    do { \
        NSAssert(test, @"**** Unexpected Assertion **** %@ \nReason: \nExpression:\"%@\", \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self); \
    } while(0)
#endif

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_TRUE_LOG(test, expression) \
    do { \
        if ( !(test) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Assertion **** \nExpression \"%@\" \nSelf: \"%@\"", expression, self]; \
        } \
    } while(0)
#else
#define RZASSERT_TRUE_LOG(test, expression) \
    do { \
        NSAssert(test, @"**** Unexpected Assertion **** \nExpression \"%@\" \nSelf: \"%@\"", expression, self); \
    } while(0)
#endif

# pragma mark - Higher-Level Assertions

// Equality Assertions


/**
 *  Raise an exception if x and y are not equal object pointers. Return void.
 *
 *  @param x     An object instance.
 *  @param y     An object instance.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_EQUAL_OBJECT_POINTERS(x, y) \
    do { \
        if ( (x) != (y) ) { \
            [RZAssert logMessageWithFormat:@"**** Object Pointers Unexpectedly Unequal **** \nReason: Left: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class])]; \
        } \
    } while(0)
#else
#define RZASSERT_EQUAL_OBJECT_POINTERS(x, y) \
    do { \
        NSAssert( (x) == (y), @"**** Object Pointers Unexpectedly Unequal **** \nReason: Left: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class])); \
    } while(0)
#endif


/**
 *  Alias for RZASSERT_EQUAL_OBJECT_POINTERS.
 *
 */

#define RZASSERT_EQUAL RZASSERT_EQUAL_OBJECT_POINTERS


/**
 *  Raise an exception if x and y are not equal. Return void.
 *
 *  @param x     An object instance.
 *  @param y     An object instance.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_EQUAL_OBJECTS(x, y) \
    do { \
        if ( !( (!(x) && !(y)) || [(x) isEqual:(y)] ) ) { \
            [RZAssert logMessageWithFormat:@"**** Objects Unexpectedly Unequal **** \nLeft: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class])]; \
        } \
    } while(0)
#else
#define RZASSERT_EQUAL_OBJECTS(x, y) \
    do { \
        NSAssert( (!(x) && !(y)) || [(x) isEqual:(y)] , @"**** Objects Unexpectedly Unequal **** \nLeft: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class])); \
    } while(0)
#endif

// String Assertions


/**
 *  Raise an exception if x and y are not equal object pointers. Return void.
 *
 *  @param x     An NSString instance.
 *  @param y     An NSString instance.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_EQUAL_STRINGS(x, y) \
    do { \
        if ( !( (!(x) && !(y)) || [(x) isEqualToString:(y)] ) ) { \
            [RZAssert logMessageWithFormat:@"**** Strings Unexpectedly Unequal **** \nLeft: \"%@\"\nRight: \"%@\"", x, y]; \
        } \
    } while(0)
#else
#define RZASSERT_EQUAL_STRINGS(x, y) \
    do { \
        NSAssert( (!(x) && !(y)) || [(x) isEqualToString:(y)] , @"**** Strings Unexpectedly Unequal **** \nLeft: \"%@\"\nRight: \"%@\"", x, y); \
    } while(0)
#endif

/**
 *  Raise an exception if string is @"". Return void.
 *
 *  @param string An NSString instance.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_NONEMPTY_STRING(string) \
    do { \
        if ( !( (string) != nil && [(string) isKindOfClass:[NSString class]] && [(string) length] > 0 ) ) { \
            [RZAssert logMessageWithFormat:@"**** Unexpected Nil, Wrong Class, or Empty String **** \nReason: Expected non-empty string but got: \"%@\" \nSelf: \"%@\"", string, self]; \
        } \
    } while(0)
#else
#define RZASSERT_NONEMPTY_STRING(string) \
    do { \
        NSAssert((string) != nil && [(string) isKindOfClass:[NSString class]] && [(string) length] > 0, @"**** Unexpected Nil, Wrong Class, or Empty String **** \nReason: Expected non-empty string but got: \"%@\" \nSelf: \"%@\"", string, self); \
    } while(0)
#endif

// Type Checks


/**
 *  Raise an exception if object is not an instance of testClass. Return void.
 *
 *  @param object        An object instance.
 *  @param testClass     A class.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_KINDOF(object, testClass) \
    do { \
        if ( ![(object) isKindOfClass:testClass] ) { \
            [RZAssert logMessageWithFormat:@"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class])]; \
        } \
    } while(0)
#else
#define RZASSERT_KINDOF(object, testClass) \
    do { \
        NSAssert([(object) isKindOfClass:testClass], @"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class])); \
    } while(0)
#endif

/**
 *  Raise an exception if object is not an instance of testClass. Return void.
 *
 *  @param object        An object instance.
 *  @param testClass     A class.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZCASSERT_KINDOF(object, testClass) \
    do { \
        if ( ![(object) isKindOfClass:testClass] ) { \
            [RZAssert logMessageWithFormat:@"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class])]; \
        } \
    } while(0)
#else
#define RZCASSERT_KINDOF(object, testClass) \
    do { \
        NSCAssert([(object) isKindOfClass:testClass], @"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class])); \
    } while(0)
#endif

/**
 *  Raise an exception if object is not an instance of testClass, or is not nil. 
 *  Return void.
 *
 *  @param x     An object instance.
 *  @param y     A class.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_KINDOF_OR_NIL(object, testClass) \
    do { \
        if ( !([(object) isKindOfClass:testClass] || (object) == nil) ) { \
            [RZAssert logMessageWithFormat:@"**** Object of Unexpected Class and Not Nil **** \nReason: Expected class: \"%@\" or nil but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class])]; \
        } \
    } while(0)
#else
#define RZASSERT_KINDOF_OR_NIL(object, testClass) \
    do { \
        NSAssert([(object) isKindOfClass:testClass] || (object) == nil, @"**** Object of Unexpected Class and Not Nil **** \nReason: Expected class: \"%@\" or nil but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class])); \
    } while(0)
#endif

/**
 *  Raise an exception if object's class does not conform to protocol. Return void.
 *
 *  @param object        An object instance.
 *  @param testClass     ????????????.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_CONFORMS_PROTOCOL(object, protocol) \
    do { \
        if ( ![(object) conformsToProtocol:protocol] ) { \
            [RZAssert logMessageWithFormat:@"**** Object Unexpectedly Doesn't Conform to Protocol **** \nReason: Expected object: \"%@\" of class \"%@\" to conform to protocol \"%@\", but it does not.", object, NSStringFromClass([object class]), NSStringFromProtocol(protocol)]; \
        } \
    } while(0)
#else
#define RZASSERT_CONFORMS_PROTOCOL(object, protocol) \
    do { \
        NSAssert([(object) conformsToProtocol:protocol], @"**** Object Unexpectedly Doesn't Conform to Protocol **** \nReason: Expected object: \"%@\" of class \"%@\" to conform to protocol \"%@\", but it does not.", object, NSStringFromClass([object class]), NSStringFromProtocol(protocol)); \
    } while(0)
#endif

/**
 *  Raise an exception if object is not a subclass of testClass, or is not nil. 
 *  Return void.
 *
 *  @param subclass        A class.
 *  @param parentClass     A class.
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_CLASS_SUBCLASS_OF_CLASS(subclass, parentClass) \
    do { \
        if ( ![(subclass) isSubclassOfClass:(parentClass)] ) { \
            [RZAssert logMessageWithFormat:@"**** Bad Subclass Relationship **** \nReason: Expected class: \"%@\" to be a subclass of class: \"%@\", but it is not.", subclass, parentClass]; \
        } \
    } while(0)
#else
#define RZASSERT_CLASS_SUBCLASS_OF_CLASS(subclass, parentClass) \
    do { \
        NSAssert([(subclass) isSubclassOfClass:(parentClass)], @"**** Bad Subclass Relationship **** \nReason: Expected class: \"%@\" to be a subclass of class: \"%@\", but it is not.", subclass, parentClass); \
    } while(0)
#endif

// Overrides


/**
 *  Raise an exception. Return void. 
 *
 * Place RZASSERT_SUBCLASSES_MUST_OVERRIDE in a superclass method that would
 * otherwise be left empty
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_SUBCLASSES_MUST_OVERRIDE \
    do { \
        [RZAssert logMessageWithFormat:@"**** Subclass Responsibility Assertion **** \nReason: Subclasses of %@ MUST override this method: %@\n", NSStringFromClass([self class]), NSStringFromSelector(_cmd)]; \
    } while(0)
#else
#define RZASSERT_SUBCLASSES_MUST_OVERRIDE \
    do { \
        NSAssert(NO, @"**** Subclass Responsibility Assertion **** \nReason: Subclasses of %@ MUST override this method: %@\n", NSStringFromClass([self class]), NSStringFromSelector(_cmd)); \
    } while(0)
#endif

// Should-never-get-here

/**
 *  Raise an exception. Return void. 
 *
 */

#if defined(NS_BLOCK_ASSERTIONS)
#define RZASSERT_SHOULD_NEVER_GET_HERE \
    do { \
        [RZAssert logMessageWithFormat:@"**** Assertion: Should Never Get Here **** \nSelf: \"%@\"", self]; \
    } while(0)
#else
#define RZASSERT_SHOULD_NEVER_GET_HERE \
    do { \
        NSAssert(NO, @"**** Assertion: Should Never Get Here **** \nSelf: \"%@\"", self); \
    } while(0)
#endif

#pragma mark - Block Assertions

/**
 *  NS_BLOCK_ASSERTIONS is defined only in the Release config. It refers to blocking
 *  assertion from being added to released code, rather than assertions relating to 
 *  Objective-C blocks.
 *
 */

#if !defined(NS_BLOCK_ASSERTIONS)

#define RZASSERT_BLOCK(condition, desc, ...) \
do { \
if ( !(condition) ) { \
    [[NSAssertionHandler currentHandler] handleFailureInFunction:NSStringFromSelector(_cmd) \
                                                            file:[NSString stringWithUTF8String:__FILE__] \
                                                      lineNumber:__LINE__ \
                                                     description:(desc), ##__VA_ARGS__]; \
    }\
} while(0);

#else // NS_BLOCK_ASSERTIONS defined

#define RZASSERT_BLOCK(condition, desc, ...)

#endif
