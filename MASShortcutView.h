@class MASShortcut;

typedef enum
    { MASShortcutViewAppearanceDefault = 0      // Height = 19 px
    , MASShortcutViewAppearanceTexturedRect     // Height = 25 px
    , MASShortcutViewAppearanceRounded          // Height = 43 px
    } MASShortcutViewAppearance;

#pragma mark MASShortcutView class
@interface MASShortcutView : NSView
    {
@private
    NSButtonCell*   _shortcutCell;
    NSInteger       _shortcutToolTipTag;
    NSInteger       _hintToolTipTag;
    NSTrackingArea* _hintArea;
    
    BOOL            _enabled;
    BOOL            _hinting;
    MASShortcut*    _shortcutValue;

    /* Just a placeholder, for example: while the key combination is "⌃⌘W",
     * the shortcut placeholder is "⌃⌘" */
    NSString*       _shortcutPlaceholder;

    BOOL            _recording;

    MASShortcutViewAppearance _appearance;

    void ( ^_shortcutValueChange )( MASShortcutView* _Sender );
    }

@property ( nonatomic, strong ) MASShortcut *shortcutValue;
@property ( nonatomic, getter = isRecording ) BOOL recording;
@property ( nonatomic, getter = isEnabled ) BOOL enabled;
@property ( nonatomic ) MASShortcutViewAppearance appearance;

@property ( nonatomic, copy ) void ( ^shortcutValueChange )( MASShortcutView* sender );

@end // MASShortcutView class