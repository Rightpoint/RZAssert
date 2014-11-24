//
//  RZAssert.h
//  RZAssert
//
//  Created by Michael Gorbach on 7/25/14.
//  Copyright (c) 2014 Raizlabs. All rights reserved.
//

#pragma mark - Basic Assertions

// General

#define RZASSERT NSAssert

// Inspired By https://github.com/amattn/AMNGlobalUtilities/blob/master/GlobalUtilities.h

#define RZASSERT_NIL(object) \
    NSAssert((object == nil), @"**** Unexpected Nil Assertion **** \nExpected nil, but " #object @" is not nil \nSelf: \"%@\"", self)

#define RZASSERT_NOT_NIL(object) \
    NSAssert((object != nil), @"**** Unexpected Non-Nil Assertion **** \nExpected not nil, but " #object @" is nil \nSelf: \"%@\"", self)

#define RZASSERT_ALWAYS \
    NSAssert(FALSE, @"**** Unexpected Assertion **** \nSelf: \"%@\"", self)

#define RZASSERT_TRUE(test) \
    NSAssert(test, @"**** Unexpected Assertion **** \nSelf: \"%@\"", self)

#define RZASSERT_FALSE(test) \
    NSAssert(!test, @"**** Unexpected Assertion **** \nSelf: \"%@\"", self)

#define RZASSERT_WITH_MESSAGE(message, ...) \
    NSAssert(FALSE, @"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self)

#define RZASSERT_WITH_MESSAGE_LOG(expression, message, ...) \
    NSAssert(FALSE, @"**** Unexpected Assertion **** %@ \nExpression: \"%@\" \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self)

#define RZASSERT_TRUE_WITH_MESSAGE(test, message, ...) \
    NSAssert(test, @"**** Unexpected Assertion **** %@ \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], self)

#define RZASSERT_TRUE_WITH_MESSAGE_LOG(test, expression, message, ...) \
    NSAssert(test, @"**** Unexpected Assertion **** %@ \nReason: %@: \nExpression:\"%@\", \nSelf: \"%@\"", [NSString stringWithFormat:message, ##__VA_ARGS__], expression, self)

#define RZASSERT_TRUE_LOG(test, expression) \
    NSAssert(test, @"**** Unexpected Assertion **** \nExpression \"%@\" \nSelf: \"%@\"", expression, self);

# pragma mark - Higher-Level Assertions

// Equality

#define RZASSERT_EQUAL_OBJECT_POINTERS(x, y) \
    NSAssert(x == y, @"**** Object Pointers Unexpectedly Unequal **** \nReason: Left: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class]))
#define RZASSERT_EQUAL RZASSERT_EQUAL_OBJECT_POINTERS

#define RZASSERT_EQUAL_OBJECTS(x, y) \
    NSAssert((!x && !y) || [x isEqual:y], @"**** Objects Unexpectedly Unequal **** \nLeft: \"%@\" of class \"%@\", Right: \"%@\" of class \"%@\"", x, NSStringFromClass([x class]), y, NSStringFromClass([y class]))

#define RZASSERT_EQUAL_STRINGS(x, y) \
    NSAssert((!x && !y) || [x isEqualToString:y], @"**** Strings Unexpectedly Unequal **** \nLeft: \"%@\"\nRight: \"%@\"", x, y)

// Strings

#define RZASSERT_NONEMPTY_STRING(string) \
    NSAssert(string != nil && [string isKindOfClass:[NSString class]] && [string length] > 0, @"**** Unexpected Nil, Wrong Class, or Empty String **** \nReason: Expected non-empty string but got: \"%@\" \nSelf: \"%@\"", string, self)

// Type Checks

#define RZASSERT_KINDOF(object, testClass) \
    NSAssert([object isKindOfClass:testClass], @"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class]))

#define RZCASSERT_KINDOF(object, testClass) \
NSCAssert([object isKindOfClass:testClass], @"**** Object of Unexpected Class **** \nReason: Expected class: \"%@\" but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class]))

#define RZASSERT_KINDOF_OR_NIL(object, testClass) \
    NSAssert([object isKindOfClass:testClass] || object == nil, @"**** Object of Unexpected Class and Not Nil **** \nReason: Expected class: \"%@\" or nil but got: \"%@\" of class \"%@\"", NSStringFromClass(testClass), object, NSStringFromClass([object class]))

#define RZASSERT_CONFORMS_PROTOCOL(object, protocol) \
    NSAssert([object conformsToProtocol:protocol], @"**** Object Unexpectedly Doesn't Conform to Protocol **** \nReason: Expected object: \"%@\" of class \"%@\" to conform to protocol \"%@\", but it does not.", object, NSStringFromClass([object class]), NSStringFromProtocol(protocol))

#define RZASSERT_CLASS_SUBCLASS_OF_CLASS(subclass, parentClass) \
    NSAssert([subclass isSubclassOfClass:parentClass], @"**** Bad Subclass Relationship **** \nReason: Expected class: \"%@\" to be a subclass of class: \"%@\", but it is not.", subclass, parentClass)

// Overrides

#define RZASSERT_SUBCLASSES_MUST_OVERRIDE \
    NSAssert(FALSE, @"**** Subclass Responsibility Assertion **** \nReason: Subclasses of %@ MUST override this method: %@\n", NSStringFromClass([self class]), NSStringFromSelector(_cmd));

// Should Never Get Here

#define RZASSERT_SHOULD_NEVER_GET_HERE \
    NSAssert(FALSE, @"**** Assertion: Should Never Get Here **** \nSelf: \"%@\"", self)

# pragma mark - Block Assertions

// Inspired by http://www.takingnotes.co/blog/2011/09/27/making-nsassert-play-nice-with-blocks/
// NS_BLOCK_ASSERTIONS is defined only in the Release config. It refers to blocking assertsion from
// being added to released code, rather than assertions relating to Objective-C blocks.
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
