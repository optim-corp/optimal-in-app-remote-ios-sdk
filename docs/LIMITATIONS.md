# Optimal In-App Remote SDK for iOS: Limitations

## Basic limitations

1. Screen sharing does not support alerts displayed by "UIAlertView".
2. Screen sharing does not support ActionSheet screens displayed by "UIActionSheet".
3. Screen sharing does not support camera live preview.
4. Screen sharing may not support "Quick Look" preview screen.
5. Supported UI control is limited to "UIButton" control.
6. UI controls other than UIButton controls cannot be remotely controlled.
7. Edit menu may be displayed as a white rectangle in the operator tool.
8. if you quickly switch the app screen horizontally and vertically, the screen may appear collapsed in the operator tool
9. voice call function is not available in IPv6 environment
10. if the WindowLevel of the app screen is higher than UIWindowLevelAlert, the screen displayed by the SDK may be hidden.
11. When using the Multiple Windows function of iPad, the screen displayed by the SDK may not be displayed in the correct window.

