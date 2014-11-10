# Customizing "Optimal In-App Remote SDK for iOS" apps

### Remote control feature
Remote control from the remote operators is enabled by default.

With the default setting, when the remote control is requested from the operator, a dialog is displayed and asks user whether to allow remote control. According to user's choices, following actions take place.

 - When "Allow" is selected
     - Operators are allowed to remotely control the device.
     - When the operator requests remote control access again, it is accepted automatically without dialog.
 - When "Allow(Only once)" is selected
     - Operators are allowed to remotely control the device.
     - When the operator requests remote control access again, dialog is displayed.
 - When "Deny" is selected
     - Operator is not allowed to remotely control the device.
     - When the operator requests remote control access again, dialog is displayed.

### Disabling remote control
If remote control operation from remote operators need to be disabled, set "remoteInputEnabled" property to "NO" immediately after creating "ORIASession" class instance. When the property is set to "NO", no dialog prompting for permission is displayed and no remote operation will be executed.

### Allowing remote control operation automatically without permission dialog
If remote control operation from remote operator needs to be allowed without permission dialog, set "remoteInputAcceptsAutomaticallyEnabled"  property to "YES" immediately after creating "ORIASession" class instance. When the property is set to "YES", no dialog prompting for permission is displayed and remote operation will be allowed automatically. 

### Voice call feature
Voice call with remote operators is disabled by default.

When voice call with remote operators is enabled, voice call session will start when the remote operator requests for voice call.

Icon is displayed during the voice call. Tapping icon displays a menu, which provides users with following options.

 - Option to output audio from the speakers (Hands free mode)
 − Option to mute microphone

### Enabling voice call
If voice call  with remote operator needs to be allowed , set "voiceChatEnabled" property to "YES" immediately after creating "ORIASession" class instance.

### Output audio from the speakers when no headphone is connected.
If audio needs to be output from the speakers when no headphone is connected, set  "voiceChatOverridesSpeakerWhenNoHeadphones" property to "YES" immediately after creating "ORIASession" class instance. Even when this option is set to "YES", sound will be output from headphones when the headphone is connected to the device. However, sound is output from the speakers if device user has selected option to output voice call audio from the speakers.
