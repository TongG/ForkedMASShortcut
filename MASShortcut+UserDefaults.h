#import "MASShortcut.h"

#pragma mark MASShortcut + MASShortcutUserDefaults
@interface MASShortcut ( MASShortcutUserDefaults )

+ ( void ) registerGlobalShortcutWithUserDefaultsKey: ( NSString* )_UserDefaultsKey
                                             handler: ( void (^)() )_Handler;

+ ( void ) unregisterGlobalShortcutWithUserDefaultsKey: ( NSString* )_UserDefaultsKey;

@end // MASShortcut + MASShortcutUserDefaults