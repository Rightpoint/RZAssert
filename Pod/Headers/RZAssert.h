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

#pragma mark - Basic Assertions

// General Assertions

#define RZASSERT NSAssert


/**
 *  Raise an exception if object is not equal to nil. Return void.
 *
 *  @param object     An object instance to compare with nil.
 */

#define RZASSERT_NIL(object) \
    NSAssert((object == nil), @"**** Unexpected Nil Assertion **** \nExpected nil, but " #object @" is not nil \nSelf: \"%@\"", self)


/**
 *  Raise an exception if object is equal to nil. Return void.
 *
 *  @param object     An object instance to compare with nil.
 */

#define RZASSERT_NOT_NIL(object) \
    NSAssert((object != nil), @"**** Unexpected Non-Nil Assertion **** \nExpected not nil, but " #object @" is nil \nSelf: \"%@\"", self)


/**
 *  Raise an exception. Return void.
 */

#define RZASSERT_ALWAYS \
    NSAssert(FALSE, @"**** Unexpected Assertion **** \nSelf: \"%@\"", self)


/**
 *  Raise an exception if object evaulates to 0. Return void.
 *
 *  @param object     An object instance to compare with 0.
 */

#define RZASSERT_TRUE(test) \
    NSAssert(test, @"**** Unexpected Assertion **** \nSelf: \"%@\"", self)


/**
 *  Raise an exception if object evaluates to 1. Return void.
 *
 *  @param object     An object instance to compare with 1.
 */

#define RZASSERT_FALSE(test) \
    NSAssert(!test, @"**** Unexpected Assertion **** \nSelf: \"%@\"", self)


/**
 *  Raise an exception. Return void.
 *
 *  @param message     A printf-style format string that describes the failure condition.
 */

#define RZASSERT_WITH_MESSAGE(message, ...) \
    NSAssert(FALSE, @"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self)

#define RZASSERT_WITH_MESSAGE_LOG(expression, message, ...) \
    NSAssert(FALSE, @"**** Unexpected Assertion **** %@ \nExpression: \"%@\" \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self)

#define RZASSERT_TRUE_WITH_MESSAGE(test, message, ...) \
    NSAssert(test, @"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self)

#define RZASSERT_TRUE_WITH_MESSAGE_LOG(test, expression, message, ...) \
    NSAssert(test, @"**** Unexpected Assertion **** %@ \nReason: \nExpression:\"%@\", \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self)

#define RZASSERT_TRUE_LOG(test, expression) \
    NSAssert(test, @"**** Unexpected Assertion **** \nExpression \"%@\" \nSelf: \"%@\"", expression, self);

# pragma mark - Higher-Level Assertions


// Equality Assertions


/**
 *  Raise an exception if x and y are not equal object pointers. Return void.
 *
 *  @param x     An object instance.
 *  @param y     An object instance.
 */

#define RZASSERT_EQUAL_OBJECT_POINTERS(x, y) \
    NSAssert(x == y, @"**** Object Pointers Unexpectedly Unequal **** \nReason: Left: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class]))


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

#define RZASSERT_EQUAL_OBJECTS(x, y) \
    NSAssert((!x && !y) || [x isEqual:y], @"**** Objects Unexpectedly Unequal **** \nLeft: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class]))


// String Assertions


/**
 *  Raise an exception if x and y are not equal object pointers. Return void.
 *
 *  @param x     An NSString instance.
 *  @param y     An NSString instance.
 */

#define RZASSERT_EQUAL_STRINGS(x, y) \
    NSAssert((!x && !y) || [x isEqualToString:y], @"**** Strings Unexpectedly Unequal **** \nLeft: \"%@\"\nRight: \"%@\"", x, y)

/**
 *  Raise an exception if string is @"". Return void.
 *
 *  @param string An NSString instance.
 */

#define RZASSERT_NONEMPTY_STRING(string) \
    NSAssert(string != nil && [string isKindOfClass:[NSString class]] && [string length] > 0, @"**** Unexpected Nil, Wrong Class, or Empty String **** \nReason: Expected non-empty string but got: \"%@\" \nSelf: \"%@\"", string, self)


// Type Checks


/**
 *  Raise an exception if object is not an instance of testClass. Return void.
 *
 *  @param object        An object instance.
 *  @param testClass     A class.
 */

#define RZASSERT_KINDOF(object, testClass) \
    NSAssert([object isKindOfClass:testClass], @"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class]))


/**
 *  Raise an exception if object is not an instance of testClass. Return void.
 *
 *  @param object        An object instance.
 *  @param testClass     A class.
 */

#define RZCASSERT_KINDOF(object, testClass) \
NSCAssert([object isKindOfClass:testClass], @"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class]))


/**
 *  Raise an exception if object is not an instance of testClass, or is not nil. 
 *  Return void.
 *
 *  @param x     An object instance.
 *  @param y     A class.
 */

#define RZASSERT_KINDOF_OR_NIL(object, testClass) \
    NSAssert([object isKindOfClass:testClass] || object == nil, @"**** Object of Unexpected Class and Not Nil **** \nReason: Expected class: \"%@\" or nil but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class]))


/**
 *  Raise an exception if object's class does not conform to protocol. Return void.
 *
 *  @param object        An object instance.
 *  @param testClass     ????????????.
 */

#define RZASSERT_CONFORMS_PROTOCOL(object, protocol) \
    NSAssert([object conformsToProtocol:protocol], @"**** Object Unexpectedly Doesn't Conform to Protocol **** \nReason: Expected object: \"%@\" of class \"%@\" to conform to protocol \"%@\", but it does not.", object, NSStringFromClass([object class]), NSStringFromProtocol(protocol))


/**
 *  Raise an exception if object is not a subclass of testClass, or is not nil. 
 *  Return void.
 *
 *  @param subclass        A class.
 *  @param parentClass     A class.
 */

#define RZASSERT_CLASS_SUBCLASS_OF_CLASS(subclass, parentClass) \
    NSAssert([subclass isSubclassOfClass:parentClass], @"**** Bad Subclass Relationship **** \nReason: Expected class: \"%@\" to be a subclass of class: \"%@\", but it is not.", subclass, parentClass)


// Overrides


/**
 *  Raise an exception. Return void. 
 *
 * Place RZASSERT_SUBCLASSES_MUST_OVERRIDE in a superclass method that would
 * otherwise be left empty
 */

#define RZASSERT_SUBCLASSES_MUST_OVERRIDE \
    NSAssert(FALSE, @"**** Subclass Responsibility Assertion **** \nReason: Subclasses of %@ MUST override this method: %@\n", NSStringFromClass([self class]), NSStringFromSelector(_cmd));



// Should-never-get-here

/**
 *  Raise an exception. Return void. 
 *
 */

#define RZASSERT_SHOULD_NEVER_GET_HERE \
    NSAssert(FALSE, @"**** Assertion: Should Never Get Here **** \nSelf: \"%@\"", self)


#pragma mark - Block Assertions

/**
 *  NS_BLOCK_ASSERTIONS is defined only in the Release config. It refers to blocking
 *  assertion from being added to released code, rather than assertions relating to 
 *  Objective-C blocks.
 *
 */

#if !defined(NS_BLOCK_ASSERTIONS)

#define RZASSERT_BLOCK(condition, desc, ...) \
do {\
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
