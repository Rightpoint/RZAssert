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
        })).to.beTruthy;
    });

});

describe(@"RZASSERT_NOT_NIL works", ^{
    it(@"handles nil correctly", ^{
        RZASSERT_NOT_NIL(nonEmptyString);
    });


    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_NOT_NIL(nonEmptyString);
        })).to.beTruthy;
    });
});

describe(@"RZASSERT_ALWAYS works", ^{

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_ALWAYS;
        })).to.beTruthy;
    });

});

describe(@"RZASSERT_TRUE works", ^{

    it(@"handles nil correctly", ^{
        RZASSERT_TRUE(!nilString);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE(nilString);
        })).to.beTruthy;
    });

});

describe(@"RZASSERT_FALSE works", ^{

    it(@"handles nil correctly", ^{
        RZASSERT_FALSE(nilString);
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_FALSE(!nilString);
        })).to.beTruthy;
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

        expect(worked).to.beTruthy;
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

        expect(worked).to.beTruthy;
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

        expect(worked).to.beTruthy;
    });

    it(@"handles non-nil values correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_WITH_MESSAGE(nonEmptyString, testMessage);
        })).to.beTruthy;
    });

    it(@"handles YES correctly", ^{
        expect(testAssertionWithBlock(^{
            RZASSERT_TRUE_WITH_MESSAGE(YES, testMessage);
        })).to.beTruthy;
    });

    it(@"handles NO correctly", ^{
        BOOL worked = NO;

        @try {
            RZASSERT_TRUE_WITH_MESSAGE(NO, testMessage);
        }
        @catch (NSException *e) {
            worked = ([e.description rangeOfString:testMessage].location != NSNotFound);
        }

        expect(worked).to.beTruthy;
    });

});

SpecEnd
