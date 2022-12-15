#ifndef _COLORS_H
# define _COLORS_H

#include <ncurses.h>

#define COLB_DEF -1
#define NOCHANGE -2
#define CYAN 1
#define GREEN 2
#define YELLOW 3
#define RED 4
#define WHITE 5
#define B_A_W 6

#define CHARCOL CYAN
#define GNDCOL GREEN 
#define BLKCOL YELLOW
#define BULBCOL CYAN
#define PRESCOL RED

#define COLR(color) COLOR_PAIR(color)

void init_colors(void);

#endif

