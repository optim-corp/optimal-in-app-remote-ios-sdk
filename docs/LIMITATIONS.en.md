# Optimal In-App Remote SDK for iOS: Limitations

## Basic limitations

1.  Screen sharing does not support alerts displayed by "UIAlertView".
2.  Screen sharing does not support ActionSheet screens displayed by "UIActionSheet".
3.  Screen sharing does not support camera live preview.
4.  Screen sharing may not support "Quick Look" preview screen.
5.  Supported UI control is limited to "UIButton" control.
6.  UI controls other than UIButton controls cannot be remotely controlled.
7.  Edit menu may be displayed as a white rectangle in the operator tool.
8.  floating icon may be hidden when continuously tapping the floating icon during support.
9.  if you quickly switch the app screen horizontally and vertically, the screen may appear collapsed in the operator tool
10. voice call function is not available in IPv6 environment
11. if the WindowLevel of the app screen is higher than UIWindowLevelAlert, the screen displayed by the SDK may be hidden.
12. When using the Multiple Windows function of iPad, the screen displayed by the SDK may not be displayed in the correct window.
13. when the app is turned sideways on the iPad, the screen displayed by the SDK and the orientation of the red pen and pointing finger may not match.
14. When the app is oriented horizontally on an iPhone with iOS13, the screen may appear collapsed in the operator tool.
