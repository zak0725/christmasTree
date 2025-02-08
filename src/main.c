// main.c
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>

// Local headers
#include "colors.h"  // Defined color pair numbers
#include "christ.h"  // Show up the Christmas Tree!!!
#include "posit.h"   // Defined positions needed
#include "flakes.h"

const char merry[20] = "Merry Christmas";

SNOW snow;

int main(void)
{
	initscr();
	curs_set(0);

	// Variables
	int dir = 0; // The direction of `merry`
	const int length = strlen(merry);

	snow.total = FLK_TOT;
	snow.buff = (SNOWFLAKE *) malloc(FLK_TOT * sizeof(SNOWFLAKE));

	int strx = (COLS - length) / 2;

	// Colors
	init_colors();
	// Snowflakes
	flake_init(&snow);

	christTree();

	for (int i = 0; i < COLS; i++)
		mvaddch(LINER, i, '_' | COLOR_PAIR(GNDCOL));
	refresh();
	
	srand(time(NULL));
	timeout(200);
	while (getch() != 'q') {
		if (!dir && strx > 0) {
			strx--;
			mvaddch(LINER, strx + length, '_' | COLOR_PAIR(GREEN));
		} else if (!dir && strx == 0) {
			dir = 1;
			mvaddch(LINER, 0, '_' | COLOR_PAIR(GREEN));
			strx++;
		} else if (dir && COLS - strx > length) {
			mvaddch(LINER, strx, '_' | COLOR_PAIR(GREEN));
			strx++;
		} else if (dir && COLS - strx == length) {
			dir = 0;
			strx--;
			mvaddch(LINER, strx + length, '_' | COLOR_PAIR(GREEN));
		}
		flake_move(&snow);

		attron(COLOR_PAIR(RED) | A_BOLD);
		mvaddstr(LINER, strx, merry);
		refresh();
		attroff(COLOR_PAIR(RED) | A_BOLD);
	}
	endwin();
	return 0;
}

