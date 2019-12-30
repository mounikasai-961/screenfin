//
//  Copyright © 2018 Confide. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE SCREENSHIELDKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPROUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

@import UIKit;
#import "SSKProtectedImageView.h"
#import "SSKProtectedLabel.h"
#import "SSKProtectedViewStatus.h"

// ScreenShieldKit only supports iOS 10.0 and up. If you need to use it in an app with a lower deployment target,
// you may manually remove this error, but be sure to only make use of ScreenShieldKit on iOS 10.0+ with runtime checks.
#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_10_0
#error ScreenShieldKit supports iOS 10.0 and up.
#endif

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
UIKIT_EXTERN NSString * const SSKErrorDomain;

/// This is the entry point for configuring global settings that apply to the entire framework.
@interface ScreenShieldKit : NSObject

/// Activate ScreenShieldKit with your license key. Contact us at sdk@screenshieldkit.com to get a license key.
/// A license key is not required for the evaluation edition of ScreenShieldKit.
+ (void)setLicenseKey:(NSString *)licenseKey;

@end

NS_ASSUME_NONNULL_END
