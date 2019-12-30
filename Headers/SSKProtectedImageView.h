//
//  Copyright © 2018 Confide. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE SCREENSHIELDKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPROUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

@import UIKit;
#import "SSKProtectedViewStatus.h"

NS_ASSUME_NONNULL_BEGIN

/// The preferred image dimension multiple (in pixels, not points) that is preferred by `SSKProtectedImageView`. Using an image with dimensions not evenly divisible by this value may result in a slightly blurrier view.
UIKIT_EXTERN const CGFloat SSKProtectedImageViewSizeMultiplePixels API_DEPRECATED("No longer needed on iOS 12.2 and up", ios(10.0, 12.2));

/// The maximum supported image width or height (in pixels, not points) that is supported by `SSKProtectedImageView`.
// Providing an image with a width or height greater than this value may result in an error.
// Caller can use this constant to proactively ensure images are of appropriate size.
// If a larger image is needed, consider splitting it up into multiple images and stack them next to each other to work around this limitation.
UIKIT_EXTERN const CGFloat SSKProtectedImageViewMaxDimensionInPixels API_DEPRECATED("No longer needed on iOS 12.2 and up", ios(10.0, 12.2));

/**
 The maximum supported image area (width × height in pixels, not points) that is supported by `SSKProtectedImageView`.

 This limitation primarily applies to older 32-bit devices. The only such devices that also support ScreenShieldKit’s minimum deployment target of iOS 10 are iPhone 5, iPhone 5c, and iPad (4th generation), which were released in 2012-2013.

 For all 64-bit devices (released starting in 2013), such as iPhone 5s, iPad Air, and iPod touch (6th generation) or later, this constant will be equal to `SSKProtectedImageViewMaxDimensionInPixels` × `SSKProtectedImageViewMaxDimensionInPixels`.
 */
// Providing an image with an area greater than this value may result in an error.
// Caller can use this constant to proactively ensure images are of appropriate size.
// If a larger image is needed, consider splitting it up into multiple images and stack them next to each other to work around this limitation.
UIKIT_EXTERN const CGFloat SSKProtectedImageViewMaxAreaInPixels API_DEPRECATED("No longer needed on iOS 12.2 and up", ios(10.0, 12.2));

typedef NS_ENUM(NSInteger, SSKProtectedImageViewResizeMode) {
    SSKProtectedImageViewResizeModeScaleToFill,
    SSKProtectedImageViewResizeModeScaleAspectFit,
    SSKProtectedImageViewResizeModeScaleAspectFill,
};

/**
 A screenshot-protected replacement for UIImageView.

 If this view fails to load, `status` will be set to `SSKProtectedViewStatusFailed` and `error` will be non-nil.

 In rare cases the view may neither load, nor fail to load, and the `status` will remain `SSKProtectedViewStatusUnknown`. You may wish to incorporate a timeout to detect when the `status` does not change.
 */
IB_DESIGNABLE
@interface SSKProtectedImageView : UIView

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
/// :nodoc:
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithImage:(nullable UIImage *)image NS_DESIGNATED_INITIALIZER;

/// The image displayed in the protected image view.
@property (strong, nonatomic, nullable) IBInspectable UIImage *image;

@property (assign, nonatomic) SSKProtectedImageViewResizeMode resizeMode;

/**
 True if ScreenShieldKit detects that the screen is being captured (e.g. recorded, AirPlayed, mirrored, etc.)

 Even though ScreenShieldKit always protects against screenshots, this property does not change when a screenshot is taken. Use [UIApplicationUserDidTakeScreenshotNotification](https://developer.apple.com/documentation/uikit/uiapplicationuserdidtakescreenshotnotification) to detect when a screenshot is taken.
 */
@property (readonly, nonatomic, getter=isCaptured) BOOL captured;

/**
 A view that is not normally visible to the user, but is visible in a screenshot or while the screen is being captured. Any subviews that you add to the screen capture view will be displayed in a screenshot or screen capture.

 ScreenShieldKit will automatically show and hide the screen capture view as appropriate, so do not add it to your own view hierarchy or modify its `hidden` property.
 */
@property (strong, readonly, nonatomic) UIView *screenCaptureView;

@property (readonly, nonatomic) SSKProtectedViewStatus status;
@property (strong, readonly, nonatomic, nullable) NSError *error;

@end

NS_ASSUME_NONNULL_END
