// main.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

// Local headers
#include "colors.h"  // Defined color pair numbers
#include "christ.h"  // Show up the Christmas Tree!!!
#include "posit.h"   // Defined positions needed
#include "object.h" // Defined types
#include "screen.h" // Screen functions, scrch etc.
#include "flakes.h"

const char merry[20] = "Merry Chistmas";

int main(void)
{
	initscr();
#ifndef DEBUG
	curs_set(0);
#endif

	// Variables
	int i;   // variable use for loops
	int flag = 0;
	const int length = strlen(merry);

	SCR scr;

	scr.maxx = COLS;
	scr.maxy = LINES;
	scr.buff = (OBJECT *) calloc(LINES, COLS * sizeof(OBJECT));

	SNOW snow;
	snow.total = FLK_TOT;
	snow.buff = (SNOWFLAKE *) malloc(FLK_TOT * sizeof(SNOWFLAKE *));

	GND *ground = (GND *) calloc(COLS, sizeof(GND));

	int strx = (getmaxx(stdscr) - length) / 2;

	// Colors
	init_colors();
	// Snowflakes
	flake_init(scr, &snow);

	christTree(&scr);

	for (i = 0; i < COLS; i++)
		scrch(&scr, i, LINER, '_', COLOR_PAIR(GNDCOL));
	
	srand(time(NULL));
	while (1) {
		usleep(200000);
		if (!flag && strx > 0) {
			strx--;
			scrch(&scr, strx + length, LINER, '_', COLOR_PAIR(GREEN));
		}
		else if (!flag && strx == 0) {
			flag = 1;
			scrch(&scr, 0, LINER, '_', COLOR_PAIR(GREEN));
			strx++;
		} else if (flag && COLS - strx > length) {
			scrch(&scr, strx, LINER, '_', COLOR_PAIR(GREEN));
			strx++;
		}
		else if (flag && COLS - strx == length) {
			flag = 0;
			strx--;
			scrch(&scr, strx + length, LINER, '_', COLOR_PAIR(GREEN));
		}
		flake_move(&scr, ground, &snow);

		printscr(scr);
		attron(COLOR_PAIR(RED) | A_BOLD);
		mvaddstr(LINER, strx, merry);
		attroff(COLOR_PAIR(RED) | A_BOLD);
		refresh();
	}
	endwin();
	free(scr.buff);
	return 0;
}

