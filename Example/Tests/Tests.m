//
//  RZAssertTests.m
//  RZAssertTests
//
//  Created by Raizlabs on 11/24/2014.
//  Copyright (c) 2014 Raizlabs. All rights reserved.
//

#import "RZAssert.h"

static NSString* const kNilString = nil;
static NSString* const kEmptyString = @"";
static NSString* const kNonEmptyString = @"non-empty string";
static NSString* const kTestMessage = @"test message";

typedef void (^AssertionBlock)(void);

static BOOL testAssertionWithBlock(AssertionBlock block)
{
    NSCAssert(block != nil, @"assertion block must not be nil");

    BOOL worked = NO;
    @try {
        block();
    }
    @catch (NSException *e) {
        worked = YES;
    }

    return worked;
}


SpecBegin(RZAssert)

describe(@"RZASSERT_NIL works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NIL(kNilString);
        })).to.beFalsy();
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NIL(kNonEmptyString);
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_NOT_NIL works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NOT_NIL(nil);
        })).to.beTruthy();
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NOT_NIL(kNonEmptyString);
        })).to.beFalsy();
    });
});

describe(@"RZASSERT_ALWAYS works", ^{

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_ALWAYS;
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_TRUE works", ^{

    it(@"handles non-nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE(!kNilString);
        })).to.beFalsy();
    });

    it(@"handles nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE(kNilString);
        })).to.beTruthy();
    });

    it(@"handles NO correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE(NO);
        })).to.beTruthy();
    });

    it(@"handles YES correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE(YES);
        })).to.beFalsy();
    });

});

describe(@"RZASSERT_FALSE works", ^{

    it(@"handles nil correctly", ^{
        RZASSERT_FALSE(kNilString);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_FALSE(!kNilString);
        })).to.beTruthy();
    });

    it(@"handles NO correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_FALSE(NO);
        })).to.beFalsy();
    });

    it(@"handles YES correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_FALSE(YES);
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_WITH_MESSAGE works", ^{

    it(@"prints message on assert", ^{

        BOOL worked = NO;
        @try {
            RZASSERT_WITH_MESSAGE(kNonEmptyString);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:kNonEmptyString].location != NSNotFound);
        }

        expect(worked).to.beTruthy();
    });

});

describe(@"RZASSERT_WITH_MESSAGE_LOG works", ^{

    it(@"prints a message on assert", ^{
        BOOL worked = NO;
        @try {
            RZASSERT_WITH_MESSAGE_LOG(kTestMessage, kNonEmptyString);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:kNonEmptyString].location != NSNotFound);
        }
        expect(worked).to.beTruthy();
    });

});

describe(@"RZASSERT_TRUE_WITH_MESSAGE works", ^{

    it(@"handles nil correctly", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_WITH_MESSAGE(kNilString, kTestMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:kTestMessage].location != NSNotFound);
        }

        expect(worked).to.beTruthy();
    });

    it(@"handles YES correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_WITH_MESSAGE(YES, kTestMessage);
        })).to.beFalsy();
    });

    it(@"handles NO correctly", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_WITH_MESSAGE(NO, kTestMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:kTestMessage].location != NSNotFound);
        }

        expect(worked).to.beTruthy();
    });

});

describe(@"RZASSERT_TRUE_WITH_MESSAGE_LOG works", ^{

    it(@"handles nil correctly", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_WITH_MESSAGE_LOG(nil, kNonEmptyString, kTestMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:kTestMessage].location != NSNotFound);
        }

        expect(worked).to.beTruthy();
    });

    it(@"handles NO correctly", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_WITH_MESSAGE_LOG(NO, kNonEmptyString, kTestMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:kTestMessage].location != NSNotFound);
        }

        expect(worked).to.beTruthy();
    });

    it(@"handles YES correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_WITH_MESSAGE_LOG(YES, kNonEmptyString, kTestMessage);
        })).to.beFalsy();
    });

});

describe(@"RZASSERT_TRUE_LOG works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_LOG(kNilString, kNonEmptyString);
        }));
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_LOG(kNonEmptyString, kTestMessage);
        })).to.beFalsy();
    });

    it(@"logs a message", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_LOG(NO, kTestMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:kTestMessage].location != NSNotFound);
        }

        expect(worked).to.beTruthy();
    });

});

describe(@"RZASSERT_EQUAL_OBJECT_POINTERS worked", ^{

    it(@"handles nil correcty", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECT_POINTERS(kNilString, kNilString);
        })).to.beFalsy();
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECT_POINTERS(kTestMessage, kNonEmptyString);
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_EQUAL_OBJECTS", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECTS(kNilString, kNilString);
        })).to.beFalsy();
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECTS(kNonEmptyString, kNonEmptyString);
        })).to.beFalsy();
    });

    it(@"handles non-pointer-equal objects correctly", ^{
        expect(testAssertionWithBlock(^{
            NSString *oneString = @"one";
            NSString *twoString = @"on";
            twoString = [twoString stringByAppendingString:@"e"];

            expect(testAssertionWithBlock(^{
                RZASSERT_EQUAL_OBJECTS(oneString, twoString);
            })).to.beFalsy();
        }));
    });

});

describe(@"RZASSERT_EQUAL_STRINGS", ^{

    it(@"handles equal strings correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_STRINGS(kNonEmptyString, kNonEmptyString);
        })).to.beFalsy();
    });

    it(@"handles nonequal strings correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_STRINGS(kNonEmptyString, kTestMessage);
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_NONEMPTY_STRING works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NONEMPTY_STRING(kNilString);
        })).to.beTruthy();
    });

    it(@"handles nonempty string correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NONEMPTY_STRING(kNonEmptyString);
        })).to.beFalsy();
    });

});

describe(@"RZASSERT_KINDOF works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF(kNilString, [NSObject class]);
        })).to.beTruthy();
    });

    it(@"handles non-nil value correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF(kNonEmptyString, [NSString class]);
        })).to.beFalsy();
    });

    it(@"handles non-matching class correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF(kNonEmptyString, [NSNumber class]);
        })).to.beTruthy();
    });

});

describe(@"RZCASSERT_KINDOF works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZCASSERT_KINDOF(kNilString, [NSObject class]);
        })).to.beTruthy();
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZCASSERT_KINDOF(kNonEmptyString, [NSString class]);
        }));
    });

});

describe(@"RZASSERT_KINDOF_OR_NIL works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF_OR_NIL(kNilString, [NSObject class]);
        })).to.beFalsy();
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF_OR_NIL(kNonEmptyString, [NSString class]);
        })).to.beFalsy();
    });

    it(@"handles non-matching class correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF_OR_NIL(kNonEmptyString, [NSNumber class]);
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_CONFORMS_PROTOCOL works", ^{

    it(@"handles nil objects correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CONFORMS_PROTOCOL(kNilString, @protocol(NSObject));
        })).to.beTruthy();
    });

    it(@"handles non-conformant objects correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CONFORMS_PROTOCOL(kNonEmptyString, @protocol(NSXMLParserDelegate));
        })).to.beTruthy();
    });

    it(@"handles conformant objects correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CONFORMS_PROTOCOL(kNonEmptyString, @protocol(NSObject));
        })).to.beFalsy();
    });

});

describe(@"RZASSERT_CLASS_SUBCLASS_OF_CLASS works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CLASS_SUBCLASS_OF_CLASS([kNilString class], [NSObject class]);
        })).to.beTruthy();
    });

    it(@"handles non-subclasses correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CLASS_SUBCLASS_OF_CLASS([kNonEmptyString class], [NSNumber class]);
        })).to.beTruthy();
    });

    it(@"handles same classes correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CLASS_SUBCLASS_OF_CLASS([kNonEmptyString class], [NSString class]);
        })).to.beFalsy();
    });

    it(@"handles non-subclasses correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CLASS_SUBCLASS_OF_CLASS([kNonEmptyString class], [NSArray class]);
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_SUBCLASSES_MUST_OVERRIDE works", ^{

    it(@"always throws an exception", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_SUBCLASSES_MUST_OVERRIDE;
        })).to.beTruthy();
    });

});

describe(@"RZASSERT_SHOULD_NEVER_GET_HERE works", ^{

    it(@"always throws an exception", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_SHOULD_NEVER_GET_HERE(@"I said so :oP");
        })).to.beTruthy();
    });

});

SpecEnd
