#include "christ.h"

void christTree(SCR *scr)
{
	int x = COLS / 2 - 1;
	int y = TREE_START;
	int seg = 2, lseg = y + 1;
	int space = 0, i;
	int num, bulb = 0, pres = 0;
	int color = COLR(GREEN);
	char ch = 0;

	scrch(scr, x, y, '*', A_BOLD | COLR(YELLOW));
	scrch(scr, x + 1, y, '*', A_BOLD | COLR(YELLOW));
	refresh();
	for (y = y + 1; y < LINER; y++, x--, space += 2) {
		if (y - lseg == seg - 1 && seg) {
			ch = '_';
			scrch(scr, x, y, '0', A_BOLD | A_BLINK | COLR(BULBCOL));

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

				scrch(scr, x + i, y, ch, color);
				color = COLR(GREEN);
				refresh();
			}

			scrch(scr, x + 1 + space, y, '0', COLR(BULBCOL) | A_BOLD | A_BLINK);
			refresh();
			seg++;
			lseg = y + 1;
			x += 2;
			space -= 4;
			bulb = 0;
			pres = 0;
			continue;
		}
		scrch(scr, x, y, '/', A_BOLD | COLR(GREEN));

		for (i = 1; i <= space; i++) {
			num = rand() % 3;
			if (!num && !bulb) {
				ch = '0';
				scrch(scr, x + i, y, ch, COLR(YELLOW) | A_BLINK | A_BOLD);
				refresh();
				bulb = 1;
			} if (num == 2 && bulb) {
				ch = '+';
				scrch(scr, x + i, y, ch, COLR(RED) | A_BOLD);
				bulb = 0;
				pres = 1;
				break;
			}
		}

		scrch(scr, x + 1 + space, y, '\\', COLR(GREEN));
		refresh();
	}
}

