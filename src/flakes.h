#ifndef _FLAKES_H
# define _FLAKES_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "object.h"
#include "screen.h"
#include "posit.h"

#define FLK_P_L 2
#define FLK_TOT (FLK_P_L * LINES)

int flake_init(SCR scr, SNOW *flakes);
int flake_move(SCR *scr, GND *gnd, SNOW *flakes);

#endif

