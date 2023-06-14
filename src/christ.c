#include "christ.h"
#include <signal.h>

void christTree(void)
{
	int x = STAR_A;
	int y = TREE_START;
	int seg = 2, lseg = y + 1;
	int space = 0, i;
	int num, bulb = 0, pres = 0;
	int color = COLR(GREEN);
	char ch = 0;

	mvaddch(y, x, '*' | A_BOLD | COLOR_PAIR(YELLOW));
	addch('*' | A_BOLD | COLR(YELLOW));
	for (y = y + 1; y < LINER; y++, x--, space += 2) {
		if (y - lseg == seg - 1 && seg) {
			ch = '_';
			mvaddch(y, x, '0' | A_BOLD | A_BLINK | COLR(BULBCOL));

			for (i = 1; i <= space; i++) {
				ch = '_';
				num = rand() % 3;
				
				if (!num && !bulb) { // Generate a bulb
					ch = '0';
					bulb = 1;
					color = COLR(YELLOW) | A_BOLD | A_BLINK;
				} else if (num == 2 && bulb && !pres) { // Generate a present
					ch = '+';
					pres = 1;
					color = COLR(RED) | A_BOLD;
					pres = 1;
				}

				addch(ch | color);
				color = COLR(GREEN);
			}

			mvaddch(y, x + 1 + space, '0' | COLR(BULBCOL) | A_BOLD | A_BLINK);
			seg++;
			lseg = y + 1;
			x += 2;
			space -= 4;
			bulb = 0;
			pres = 0;
			continue;
		}
		mvaddch(y, x, '/' | A_BOLD | COLR(GREEN));

		for (i = 1; i <= space; i++) {
			num = rand() % 3;
			if (!num && !bulb) {
				ch = '0';
				mvaddch(y, x + i, ch | COLR(YELLOW) | A_BLINK | A_BOLD);
				bulb = 1;
			} if (num == 2 && bulb) {
				ch = '+';
				mvaddch(y, x + i, ch | COLR(RED) | A_BOLD);
				bulb = 0;
				pres = 1;
				break;
			}
		}

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

