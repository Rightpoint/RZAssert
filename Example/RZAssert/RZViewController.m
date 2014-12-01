//
//  RZViewController.m
//  RZAssert
//
//  Created by mattThousand on 11/24/2014.
//  Copyright (c) 2014 mattThousand. All rights reserved.
//

#import "RZViewController.h"
#import "RZViewControllerSubclass.h"
#import <RZAssert.h>

@interface RZViewController ()

@end

@implementation RZViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    [self assertTrue];

    [self assertFalse];

    [self assertNil];

    [self assertNotNil:[[NSObject alloc] init]];

    RZViewControllerSubclass *rzViewControllerSubclass = [[RZViewControllerSubclass alloc] init];

    if ( rzViewControllerSubclass ) {
        NSLog(@"Calling assertImplementedBySubclass on an instance of RZViewController raises an exception.");
    }
}

- (void)assertTrue
{
    RZASSERT_TRUE(YES);
}

- (void)assertFalse
{
    RZASSERT_FALSE(NO);
}

- (void)assertNil
{
    RZASSERT_NIL(nil);
}

- (void)assertNotNil:(NSObject *)obj
{
    RZASSERT_NOT_NIL(obj);
}

- (void)assertNonEmptyString:(NSString *)nonEmptyString
{
    RZASSERT_NONEMPTY_STRING(nonEmptyString);
}

- (void)assertImplementedBySubclass
{
    RZASSERT_SUBCLASSES_MUST_OVERRIDE
}

@end
