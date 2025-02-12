#ifndef _FLAKES_H
# define _FLAKES_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "christ.h"
#include "posit.h"

typedef struct {
	int x, y;
} SNOWFLAKE;

typedef struct {
	SNOWFLAKE *buff;
	int total;
} SNOW;


#define FLK_P_L 2
#define FLK_TOT (FLK_P_L * LINES)
#define SNOWDRIFT 3

int flake_init(SNOW *flakes);
int flake_move(SNOW *flakes);
_Bool cover(int y, int x);

#endif

