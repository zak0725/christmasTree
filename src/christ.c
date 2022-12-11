#include "christ.h"

void christTree(OBJECT *scr)
{
	int x = COLS / 2 - 1;
	int y = (LINES - LINER - 10) / 2;
	int seg = 2, lseg = y + 1;
	int space = 0, i;
	int num, bulb = 0, pres = 0;
	int color = COLOR_PAIR(GREEN);
	char ch = ' ';

	mvaddch(y, x, '*' | A_BLINK | A_BOLD | COLOR_PAIR(YELLOW));
	addch('*' | A_BLINK | A_BOLD | COLOR_PAIR(YELLOW));
	refresh();
	for (y = y + 1; y < LINER; y++, x--, space += 2) {
		srand(time(NULL));
		if (y - lseg == seg - 1 && seg) {
			ch = '_';
			mvaddch(y, x, '0' | A_BOLD | COLOR_PAIR(BULBCOL) | A_BLINK);

			for (i = 0; i < space; i++) {
				num = rand() % 3;
				
				if (!num && !bulb) { // Generate a bulb
					ch = '0';
					bulb = 1;
					color = COLOR_PAIR(YELLOW) | A_BOLD;
				} else if (num == 2 && bulb && !pres) { // Generate a present
					ch = '+';
					pres = 1;
					color = COLOR_PAIR(RED) | A_BOLD;
					pres = 1;
				}

				addch(ch | color);
				ch = '_';
				color = COLOR_PAIR(GREEN);
				refresh();
			}

			addch('0' | COLOR_PAIR(BULBCOL) | A_BOLD | A_BLINK);
			refresh();
			seg++;
			lseg = y + 1;
			x += 2;
			space -= 4;
			bulb = 0;
			pres = 0;
			continue;
		}
		mvaddch(y, x, '/' | A_BOLD | COLOR_PAIR(GREEN));

		for (i = 1; i <= space; i++) {
			num = rand() % 3;
			if (!num && !bulb) {
				ch = '0';
				mvaddch(y, x + i, ch | COLOR_PAIR(YELLOW) | A_BLINK | A_BOLD);
				refresh();
				bulb = 1;
			} if (num == 2 && bulb) {
				ch = '+';
				mvaddch(y, x + i, ch | COLOR_PAIR(RED) | A_BOLD);
				bulb = 0;
				pres = 1;
				break;
			}
		}

		mvaddch(y, x + 1 + space, '\\' | COLOR_PAIR(GREEN));
		refresh();
	}
}

