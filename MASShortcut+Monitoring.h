#import "MASShortcut.h"

#pragma mark MASShortcut + MASShorcutMonitoring
@interface MASShortcut ( MASShorcutMonitoring )

+ ( id ) addGlobalHotkeyMonitorWithShortcut: ( MASShortcut* )_Shortcut
                                    handler: ( void (^)() )_Handler;

+ ( void ) removeGlobalHotkeyMonitor: ( id )_Monitor;

@end // MASShortcut + MASShorcutMonitoring
