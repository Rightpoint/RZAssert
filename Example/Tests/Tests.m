//
//  RZAssertTests.m
//  RZAssertTests
//
//  Created by mattThousand on 11/24/2014.
//  Copyright (c) 2014 mattThousand. All rights reserved.
//

#import "RZAssert.h"

SpecBegin(InitialSpecs)

static NSString* const nilString = nil;
static NSString* const emptyString = @"";
static NSString* const nonEmptyString = @"non-empty string";

describe(@"RZASSERT_NIL works", ^{
    RZASSERT_NIL(nilString);

    BOOL worked = NO;
    @try {
        RZASSERT_NIL(nonEmptyString);
    }
    @catch (NSException *e) {
        worked = YES;
    }
    @finally {
        expect(worked).to.beTruthy;
    }
});

SpecEnd
