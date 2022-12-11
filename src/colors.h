#ifndef _COLORS_H
# define _COLORS_H

#include <ncurses.h>

#define COLB_DEF -1
#define CYAN 1
#define GREEN 2
#define YELLOW 3
#define RED 4

#define CHARCOL CYAN
#define GNDCOL GREEN 
#define BLKCOL YELLOW
#define BULBCOL CYAN
#define PRESCOL RED

void init_colors(void);

#endif

