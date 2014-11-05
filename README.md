# What's MASShortcut?

Some time ago Cocoa developers used a brilliant framework [ShortcutRecorder](http://wafflesoftware.net/shortcut/) for managing keyboard shortcuts in application preferences. However, it became incompatible with a new plugin architecture of Xcode 4. All code is compatible with Xcode 4.3 (and later), Mac OS X 10.7 (and later) and the sandboxed environment.


# Why MASShortcut?

The project MASShortcut introduces modern API and user interface for recording, storing and using global keyboard shortcuts.

> There is a lot of menu bar apps which display a panel with user interface when you click the menu bar icon. To make our life easier, these apps usually provide a global keyboard shortcut to access that panel without using your mouse.

> Other apps just run in background and wait while you press a hotkey to perform some action. Evernote, Fantastical, Clocks, LittleSnapper, Things… all of these use global shortcuts to do their work. But how to implement this feature in you own Mac app?

> Unfortunately, there is no official Cocoa API like NSGlobalShortcut. Instead, you have to deal with old low-level Carbon APIs to listen for global hotkeys, look [here](http://cocoasamurai.blogspot.jp/2009/03/global-keyboard-shortcuts-with-carbon.html) and [here](http://cocoatutorial.grapewave.com/2010/01/adding-a-hotkey-listener/) to find more details.

> In addition, we would need a control like NSGlobalShortcutView to enter and display keyboard shortcuts with special characters for Command, Option and Shift, something like [this](https://stackoverflow.com/questions/8201338/how-to-implement-shortcut-key-input-in-mac-cocoa-app/8204355#8204355).

> From the links I just posted, you may find that adding support for global keyboard shortcuts is a non-trivial task. You have to dive into the component architecture, copy many sources or framework into your project, and finally add many lines of code into your app.


# Usage

I hope, it is really easy:
```objective-c
// Drop a custom view into XIB and set its class to MASShortcutView
@property ( nonatomic, weak ) IBOutlet MASShortcutView* shortcutView;
	
// Think up a preference key to store a global shortcut between launches
NSString* const kPreferenceGlobalShortcut = @"GlobalShortcut";

// Assign the preference key and the shortcut view will take care of persistence
self.shortcutView.associatedUserDefaultsKey = kPreferenceGlobalShortcut;

// Execute your block of code automatically when user triggers a shortcut from preferences
[ MASShortcut registerGlobalShortcutWithUserDefaultsKey: kPreferenceGlobalShortcut 
                                                handler:
    ^{
     /* Let me know if you find a better or more convenient API. */
    } ];
```

To set an example, I made a demo project: [MASShortcutDemo](https://github.com/shpakovski/MASShortcutDemo). Enjoy!

# Non-ARC Version

This repo does not use ARC.

# Copyright

MASShortcut is licensed under the BSD license.
