//
//  RZViewControllerSubclass.m
//  RZAssert
//
//  Created by Matthew Buckley on 12/1/14.
//  Copyright (c) 2014 Raizlabs. All rights reserved.
//

#import "RZViewControllerSubclass.h"

@interface RZViewControllerSubclass ()

@end

@implementation RZViewControllerSubclass

- (instancetype)init
{
    self = [super init];
    if ( self ) {
        [self assertImplementedBySubclass];
    }

    return self;
}

- (void)assertImplementedBySubclass
{
    NSLog(@"Implemented by RZViewControllerSubclass");
}

@end
