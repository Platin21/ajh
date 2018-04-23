#include "ajh_types.h"

//TODO(Armin): Add view and input stuff!
//TODO(Armin): Add metal stuff

typedef struct ajh_xxx_window ajh_xxx_window;
ajh_xxx_window* ajh_xxx_create_window(void);
void ajh_xxx_destroy_window(ajh_xxx_window* window);


void ajh_alert(ajh_chp title ,ajh_chp text);

def_struct(Span,
    ajh_size height;
    ajh_size width;
);

def_struct(Window,
    ajh_xxx_window* win;
    ajh_Span       size;
);

intern ajh_Window ajh_create_window(void)
{
    ajh_Window win  = {};
    win.win         = ajh_xxx_create_window();
    win.size.width  = 800;
    win.size.height = 600;
    return win;
}

intern void ajh_destroy_window(ajh_Window window)
{
    ajh_xxx_destroy_window(window.win);
}

def_struct(Context,
    ajh_Window win;
);

intern ajh_Context ajh_create_context()
{
    ajh_Context ctx;
    ctx.win = ajh_create_window();
    return ctx;
}

intern void ajh_destroy_context(ajh_Context ctx)
{
    ajh_destroy_window(ctx.win);
}

