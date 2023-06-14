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
#include "flakes.h"

const char merry[20] = "Merry Christmas";

int main(void)
{
	initscr();
	curs_set(0);

	// Variables
	int i;   // variable use for loops
	int flag = 0;
	const int length = strlen(merry);

	SNOW snow;
	snow.total = FLK_TOT;
	snow.buff = (SNOWFLAKE *) malloc(FLK_TOT * sizeof(SNOWFLAKE));

	int strx = (COLS - length) / 2;

	// Colors
	init_colors();
	// Snowflakes
	flake_init(&snow);

	christTree();

	for (i = 0; i < COLS; i++)
		mvaddch(LINER, i, '_' | COLOR_PAIR(GNDCOL));
	refresh();
	
	srand(time(NULL));
	timeout(200);
	while (getch() != 'q') {
		if (!flag && strx > 0) {
			strx--;
			mvaddch(LINER, strx + length, '_' | COLOR_PAIR(GREEN));
		}
		else if (!flag && strx == 0) {
			flag = 1;
			mvaddch(LINER, 0, '_' | COLOR_PAIR(GREEN));
			strx++;
		} else if (flag && COLS - strx > length) {
			mvaddch(LINER, strx, '_' | COLOR_PAIR(GREEN));
			strx++;
		}
		else if (flag && COLS - strx == length) {
			flag = 0;
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

