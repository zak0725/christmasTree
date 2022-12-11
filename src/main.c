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

const char merry[20] = "Merry Chistmas";

int main(void)
{
	initscr();
	curs_set(0);

	// Variables
	int i;   // variable use for loops
	int flag = 0;
	const int length = strlen(merry);

	OBJECT *scr = malloc(LINES * COLS * sizeof(OBJECT));

	int strx = (getmaxx(stdscr) - length) / 2;

	// Colors
	init_colors();

	christTree(scr);

	for (i = 0; i < COLS; i++)
		mvaddch(LINER, i, '_' | COLOR_PAIR(GNDCOL));
	move(CHARY + 1, CHARX);  // Move the curser away
	refresh();
	
	while (1) {
		usleep(200000);
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
		attron(COLOR_PAIR(RED) | A_BOLD);
		mvaddstr(LINER, strx, merry);
		attroff(COLOR_PAIR(RED) | A_BOLD);
		refresh();
		
		mvprintw(LINES - 1, COLS - 1, "%d %d\n", LINES, COLS);
		refresh();
	}
	endwin();
	free(scr);
	return 0;
}

