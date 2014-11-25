//
//  RZAssertTests.m
//  RZAssertTests
//
//  Created by mattThousand on 11/24/2014.
//  Copyright (c) 2014 mattThousand. All rights reserved.
//

#import "RZAssert.h"

static NSString* const nilString = nil;
static NSString* const emptyString = @"";
static NSString* const nonEmptyString = @"non-empty string";
static NSString* const testMessage = @"test message";

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

SpecBegin(InitialSpecs)

describe(@"RZASSERT_NIL works", ^{

    it(@"handles nil correctly", ^{
        RZASSERT_NIL(nilString);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NIL(nonEmptyString);
        })).to.equal(YES);
    });

});

describe(@"RZASSERT_NOT_NIL works", ^{

    it(@"handles nil correctly", ^{
        RZASSERT_NOT_NIL(nonEmptyString);
    });


    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NOT_NIL(nonEmptyString);
        })).to.equal(NO);
    });
});

describe(@"RZASSERT_ALWAYS works", ^{

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_ALWAYS;
        })).to.equal(YES);
    });

});

describe(@"RZASSERT_TRUE works", ^{

    it(@"handles non-nil correctly", ^{
        RZASSERT_TRUE(!nilString);
    });

    it(@"handles nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE(nilString);
        })).to.equal(YES);
    });

});

describe(@"RZASSERT_FALSE works", ^{

    it(@"handles nil correctly", ^{
        RZASSERT_FALSE(nilString);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_FALSE(!nilString);
        })).to.equal(YES);
    });
});

describe(@"RZASSERT_WITH_MESSAGE works", ^{

    it(@"prints message on assert", ^{
        BOOL worked = NO;
        @try {
            RZASSERT_WITH_MESSAGE(nonEmptyString);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:nonEmptyString].location != NSNotFound);
        }

        expect(worked).to.equal(YES);
    });

});

describe(@"RZASSERT_WITH_MESSAGE_LOG works", ^{

    it(@"prints a message on assert", ^{
        BOOL worked = NO;
        @try {
            RZASSERT_WITH_MESSAGE_LOG(testMessage, nonEmptyString);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:nonEmptyString].location != NSNotFound);
        }

        expect(worked).to.equal(YES);
    });
});

describe(@"RZASSERT_TRUE_WITH_MESSAGE works", ^{

    it(@"handles nil correctly", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_WITH_MESSAGE(nilString, testMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:testMessage].location != NSNotFound);
        }

        expect(worked).to.equal(YES);
    });

    it(@"handles YES correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_WITH_MESSAGE(YES, testMessage);
        })).to.equal(NO);
    });

    it(@"handles NO correctly", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_WITH_MESSAGE(NO, testMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:testMessage].location != NSNotFound);
        }

        expect(worked).to.equal(YES);
    });

});

describe(@"RZASSERT_TRUE_WITH_MESSAGE_LOG works", ^{

    it(@"handles nil correctly", ^{

    });

});

describe(@"RZASSERT_TRUE_LOG works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_LOG(nilString, nonEmptyString);
        }));
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_LOG(nonEmptyString, testMessage);
        })).to.equal(NO);
    });

    it(@"logs a message", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_LOG(NO, testMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:testMessage].location != NSNotFound);
        }

        expect(worked).to.equal(YES);
    });

});

describe(@"RZASSERT_EQUAL_OBJECT_POINTERS worked", ^{

    it(@"handles nil correcty", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECT_POINTERS(nilString, nilString);
        })).to.equal(NO);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECT_POINTERS(testMessage, nonEmptyString);
        })).to.equal(YES);
    });

});

describe(@"RZASSERT_EQUAL_OBJECTS", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECTS(nilString, nilString);
        })).to.equal(NO);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_OBJECTS(nonEmptyString, nonEmptyString);
        })).to.equal(NO);
    });

});

describe(@"RZASSERT_EQUAL_STRINGS", ^{

//    it(@"handles nil correcty", ^{
//        expect(testAssertionWithBlock(^{
//            RZASSERT_EQUAL_STRINGS(nilString, nilString);
//        })).to.equal(YES);
//    });

    it(@"handles equal strings correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_STRINGS(nonEmptyString, nonEmptyString);
        })).to.equal(NO);
    });

    it(@"handles nonequal strings correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_EQUAL_STRINGS(nonEmptyString, testMessage);
        })).to.equal(YES);
    });

});

describe(@"RZASSERT_NONEMPTY_STRING works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NONEMPTY_STRING(nilString);
        })).to.equal(YES);
    });

    it(@"handles nonempty string correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NONEMPTY_STRING(nonEmptyString);
        })).to.equal(NO);
    });

});

describe(@"RZASSERT_KINDOF works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF(nilString, [NSObject class]);
        })).to.equal(YES);
    });

    it(@"handles non-nil value correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF(nonEmptyString, [NSString class]);
        })).to.equal(NO);
    });

});

describe(@"RZCASSERT_KINDOF_OR_NIL works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZCASSERT_KINDOF(nilString, [NSObject class]);
        })).to.equal(YES);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZCASSERT_KINDOF(nonEmptyString, [NSString class]);
        }));
    });

});

describe(@"RZASSERT_KINDOF_OR_NIL works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF_OR_NIL(nilString, [NSObject class]);
        })).to.equal(NO);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF_OR_NIL(nonEmptyString, [NSString class]);
        })).to.equal(NO);
    });

    it(@"handles non-matching class correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_KINDOF_OR_NIL(nonEmptyString, [NSNumber class]);
        })).to.equal(YES);
    });

});

describe(@"RZASSERT_CONFORMS_PROTOCOL works", ^{

    it(@"throws exception for non-conformant objects", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CONFORMS_PROTOCOL(nilString, @protocol(NSObject));
        })).to.equal(YES);
    });

    it(@"does not throw exception for protocol-conformant objects", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CONFORMS_PROTOCOL(nonEmptyString, @protocol(NSObject));
        })).to.equal(NO);
    });

});

describe(@"RZASSERT_CLASS_SUBCLASS_OF_CLASS works", ^{

    it(@"handles nil correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CLASS_SUBCLASS_OF_CLASS([nilString class], [NSObject class]);
        })).to.equal(YES);
    });

    it(@"throws an exception non-subclasses", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CLASS_SUBCLASS_OF_CLASS([nonEmptyString class], [NSNumber class]);
        })).to.equal(YES);
    });

    it(@"does not throw an exception for subclasses", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_CLASS_SUBCLASS_OF_CLASS([nonEmptyString class], [NSString class]);
        })).to.equal(NO);
    });

});

describe(@"RZASSERT_SUBCLASSES_MUST_OVERRIDE works", ^{

    it(@"always throws an exception", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_SUBCLASSES_MUST_OVERRIDE;
        })).to.equal(YES);
    });

});

describe(@"RZASSERT_SHOULD_NEVER_GET_HERE works", ^{

    it(@"always throws an exception", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_SHOULD_NEVER_GET_HERE;
        })).to.equal(YES);
    });

});

SpecEnd
