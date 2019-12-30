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

/**
 A screenshot-protected replacement for UILabel.

 If this view fails to load, `status` will be set to `SSKProtectedViewStatusFailed` and `error` will be non-nil.

 In rare cases the view may neither load, nor fail to load, and the `status` will remain `SSKProtectedViewStatusUnknown`. You may wish to incorporate a timeout to detect when the `status` does not change.
 */
IB_DESIGNABLE
@interface SSKProtectedLabel : UIView <UIContentSizeCategoryAdjusting>

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;
/// :nodoc:
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

- (instancetype)initWithText:(NSString *)text;
- (instancetype)initWithAttributedText:(NSAttributedString *)attributedText NS_DESIGNATED_INITIALIZER;

/// The underlying string.
@property (copy, nonatomic) IBInspectable NSString *text;

/// The underlying attributed string.
@property (copy, nonatomic) NSAttributedString *attributedText;

/**
 Indicates whether the label should automatically update its font when the device’s [UIContentSizeCategory](https://developer.apple.com/documentation/uikit/uicontentsizecategory) is changed.
 For this property to take effect, the font must be vended using [+[UIFont preferredFontForTextStyle:]](https://developer.apple.com/documentation/uikit/uifont/1619030-preferredfontfortextstyle) or [+[UIFont preferredFontForTextStyle:compatibleWithTraitCollection:]](https://developer.apple.com/documentation/uikit/uifont/1771762-preferredfontfortextstyle) with a valid and documented [UIFontTextStyle](https://developer.apple.com/documentation/uikit/uifonttextstyle).

 A font vended using [-[UIFontMetrics scaledFontForFont:]](https://developer.apple.com/documentation/uikit/uifontmetrics/2877385-scaledfontforfont) or one of its variants is not currently supported.
 */
@property (nonatomic) BOOL adjustsFontForContentSizeCategory;

/**
 The text storage object holding the text displayed in this label. Note that [NSTextStorage](https://developer.apple.com/documentation/uikit/nstextstorage) is a subclass of [NSMutableAttributedString](https://developer.apple.com/documentation/foundation/nsmutableattributedstring).

 Be sure to invoke `invalidateProtectedView` after changing any properties to notify the receiver to perform a layout pass.
 */
@property (strong, readonly, nonatomic) NSTextStorage *textStorage;

/**
 The layout manager that lays out text for the receiver’s text container.

 Be sure to invoke `invalidateProtectedView` after changing any properties to notify the receiver to perform a layout pass.
 */
@property (strong, readonly, nonatomic) NSLayoutManager *layoutManager;

/**
 The text container object defining the area in which text is displayed in this label.

 Be sure to invoke `invalidateProtectedView` after changing any properties to notify the receiver to perform a layout pass.
 */
@property (strong, readonly, nonatomic) NSTextContainer *textContainer;

/// Invoke this method after changing any properties on `textStorage`, `layoutManager`, or `textContainer` to notify the receiver to perform a layout pass.
- (void)invalidateProtectedView;

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
