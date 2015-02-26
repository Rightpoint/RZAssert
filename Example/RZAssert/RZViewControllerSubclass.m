//
//  RZViewControllerSubclass.m
//  RZAssert
//
//  Created by Matthew Buckley on 12/1/14.
//  Copyright (c) 2014 Raizlabs. All rights reserved.
//

#import "RZViewControllerSubclass.h"

@implementation RZViewControllerSubclass

- (instancetype)init
{
    self = [super init];
    if ( self ) {
        [self methodThatSubclassesMustOverride];
    }

    return self;
}

- (void)methodThatSubclassesMustOverride
{
    // If you delete this method, the base class will assert it gets to this line.
}

@end
