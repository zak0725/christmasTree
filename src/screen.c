#include "screen.h"

int scrch(SCR *scr, int x, int y, char ch, int color)
{
	if (!scr) return -1;
	/* Ensure the position is valid */
	if (x >= scr -> maxx || x < 0 || y >= scr -> maxy || y < 0)
		return -1;

	int pos = y * scr -> maxx + x;
	scr -> buff[pos].icon = ch;
	if (color != NOCHANGE)
		scr -> buff[pos].color = color;

	return 0;  // Success
}

void printscr(SCR scr)
{
	int i, j, pos;
	move(0, 0);
	for (i = 0; i < scr.maxy; i++)
		for (j = 0; j < scr.maxx; j++) {
			pos = i * scr.maxx + j;
			if (!scr.buff[pos].icon) {
				addch(' ');
				continue;
			}
			addch(scr.buff[pos].icon | scr.buff[pos].color);
		}
	refresh();
}

OBJECT *scrgetch(SCR scr, int x, int y)
{
	int pos = y * scr.maxx + x;
	if (y >= scr.maxy || y < 0 || x >= scr.maxx || x < 0)
		return 0;
	return &(scr.buff[pos]);
}

