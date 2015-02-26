//
//  RZAppDelegate.m
//  RZAssert
//
//  Created by Raizlabs on 11/24/2014.
//  Copyright (c) 2014 Raizlabs. All rights reserved.
//

#import "RZAppDelegate.h"
#import <RZAssert/RZAssert.h>

@implementation RZAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [RZAssert configureWithLoggingHandler:^(NSString *message) {
        NSLog(@"simulating remote logging event: \n%@", message);
    }];

    return YES;
}

@end
