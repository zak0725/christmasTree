#ifndef _SCREEN_H
# define _SCREEN_H

#include <ncurses.h>

#include "object.h"
#include "colors.h"

int scrch(SCR *scr, int x, int y, char ch, int color);
OBJECT *scrgetch(SCR scr, int x, int y);
void printscr(SCR scr);

#endif

