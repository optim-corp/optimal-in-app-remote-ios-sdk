# Optimal In-App Remote SDK for iOS: Limitations

## Basic limitations

1. Screen sharing does not support alerts displayed by "UIAlertView".
2. Screen sharing does not support ActionSheet screens displayed by "UIActionSheet".
3. Alerts and ActionSheet screens displayed by UIAlertController may appear distorted in the operator tool.
4. Screen sharing does not support camera live preview.
5. Screen sharing may not support "Quick Look" preview screen.
6. UI controls other than UIButton controls cannot be remotely controlled.
7. Edit menu may be displayed as a white rectangle in the operator tool.
8. If you quickly switch the app screen horizontally and vertically, the screen may appear collapsed in the operator tool.
9. Voice call function is not available in IPv6 environment.
10. If the WindowLevel of the app screen is higher than UIWindowLevelAlert, the screen displayed by the SDK may be hidden.
11. When using the Multiple Windows function of iPad, the screen displayed by the SDK may not be displayed in the correct window.
12. When using the masking feature, the screen is not shared during screen transition and scroll animations.
    - Sharing resumes from the screen after the transition or scroll is complete.
