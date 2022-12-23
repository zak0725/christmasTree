#include "flakes.h"

int flake_init(SCR scr, SNOW *flakes)
{
	int i, j;
	if (!flakes) return -1;
	srand(time(NULL));
	for (j = -1, i = 0; i < flakes -> total; i++, j--) {
		flakes -> buff[i].y = j;
		flakes -> buff[i].x = rand() % scr.maxx;
	}
	return 0;
}

int flake_move(SCR *scr, GND *gnd, SNOW *flakes)
{
	int i;
	OBJECT *ptr = NULL;
	if (!scr) return -1;

	for (i = 0; i < flakes -> total; i++) {
		ptr = scrgetch(*scr, flakes -> buff[i].x, flakes -> buff[i].y);
		if (flakes -> buff[i].y >= 0 && (ptr -> icon == '*' && ptr -> color == COLR(WHITE)))
			scrch(scr, flakes -> buff[i].x, flakes -> buff[i].y, 0, NOCHANGE); // Clear the previous flake

		if (flakes -> buff[i].y < LINER - 1)
			flakes -> buff[i].y++; // Move the flake down, if it hasn't reached the bottem
		else {
			gnd[flakes -> buff[i].x]++;
			if (gnd[flakes -> buff[i].x] == 4) { // if there is 4 flakes on this place, add a snow drift
				gnd[flakes -> buff[i].x] = 0;
				scrch(scr, flakes -> buff[i].x, LINER, '*', COLR(WHITE));
			}
			flakes -> buff[i].y = -1;
			flakes -> buff[i].x = rand() % scr -> maxx;
			continue;
		}
		ptr = scrgetch(*scr, flakes -> buff[i].x, flakes -> buff[i].y);
		if (flakes -> buff[i].y >= 0)
			if (!(ptr -> icon) || flakes -> buff[i].y == LINER)
				scrch(scr, flakes -> buff[i].x, flakes -> buff[i].y, '*', COLR(WHITE)); // Print the new flake
	}
	return 0;
}

