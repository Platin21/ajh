#include "ajh_context.h"
#import <AppKit/AppKit.h>
#import <Metal/Metal.h>
#import <MetalKit/MetalKit.h>

typedef struct ajh_xxx_window
{
    NSWindow* window;
} ajh_xxx_window;

ajh_xxx_window* ajh_xxx_create_window()
{
    ajh_xxx_window* win = malloc(sizeof(ajh_xxx_window));
    win->window = [[NSWindow alloc] init];
    return win;
}

void ajh_xxx_destroy_window(ajh_xxx_window* window)
{
    [window->window dealloc];
    free(window);
}

void ajh_alert(ajh_chp title,ajh_chp text)
{
    //TODO(Armin): Use Region alloc or temp alloc
    NSAlert*  alert   = [[NSAlert  alloc] init];
    NSString* xtext   = [[NSString alloc] initWithUTF8String: text  ];
    NSString* xtitle  = [[NSString alloc] initWithUTF8String: title ];
    NSString* btnName = [[NSString alloc] initWithUTF8String: "Ok" ];  //INFO(Armin): You can't use @"" this allocates a string wich gets never deallocated
    NSImage* caution  = [[NSWorkspace sharedWorkspace]iconForFileType:NSFileTypeForHFSTypeCode(kAlertCautionIcon)];
    [ alert setInformativeText: xtext ];
    [ alert setAlertStyle: NSAlertStyleWarning ];
    [ alert setMessageText: xtitle ];
    [ alert addButtonWithTitle: btnName ];
    [ alert setIcon: caution ];
    [ alert.window orderWindow: NSWindowAbove relativeTo: 0 ];
    [ alert.window makeKeyWindow ];
    if([ alert runModal ] == NSModalResponseStop )
    {
        [ xtext   dealloc ];
        [ xtitle  dealloc ];
        [ btnName dealloc ];
        [ NSApplication.sharedApplication stopModal];
        [ alert dealloc ];
    }
}

// create mtk::view in Objc

// create mtk::view_controller

