#include "christ.h"
#include <signal.h>

void christTree(void)
{
	int seg = 2, lseg = TREE_START + 1;
	int space = 0;

	mvaddch(TREE_START, STAR_A, '*' | A_BOLD | COLOR_PAIR(YELLOW));
	addch('*' | A_BOLD | COLR(YELLOW));
	for (int y = TREE_START + 1, x = STAR_A; y < LINER; y++, x--, space += 2) {
		if (y - lseg == seg - 1 && seg) {
			mvaddch(y, x, '0' | A_BOLD | A_BLINK | COLR(BULBCOL));

			for (int i = 1; i <= space; i++)
				addch('_' | COLR(GREEN));

			int bulbx = rand() % space + 1;
			int presx;
			do {
				presx = rand() % space + 1;
			} while (presx == bulbx);
			mvaddch(y, x + bulbx, '0' | A_BOLD | A_BLINK | COLR(YELLOW));
			mvaddch(y, x + presx, '+' | A_BOLD | COLR(RED));

			mvaddch(y, x + 1 + space, '0' | COLR(BULBCOL) | A_BOLD | A_BLINK);
			seg++;
			lseg = y + 1;
			x += 2;
			space -= 4;
			continue;
		}
		mvaddch(y, x, '/' | A_BOLD | COLR(GREEN));

		int bulbx = rand() % space + 1;
		int presx;
		do {
			presx = rand() % space + 1;
		} while (presx == bulbx);
		mvaddch(y, x + bulbx, '0' | A_BOLD | A_BLINK | COLR(YELLOW));
		mvaddch(y, x + presx, '+' | A_BOLD | COLR(RED));

		mvaddch(y, x + 1 + space, '\\' | COLR(GREEN));
	}
	refresh();
}

int find_sol(int line, int *stat)
{
	int i, cnt = 2, seg = TREE_START + cnt, start = STAR_A;

	*stat = 0;

	if (line < 0) return -1;

	if (line == 0) {
		*stat = 0;
		return STAR_A;
	}

	for (i = 1; i < line; i++, start--) {
		if (i + 1 == seg)
			*stat = 1;
		if (i == seg) {
			cnt++;
			seg += cnt;
			start += 2;
		}
	}
	
	return start;
}

