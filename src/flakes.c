#include "flakes.h"

int *snowdrift;

int flake_init(SNOW *flakes)
{
	int i, j;
	if (!flakes) return -1;
	srand(time(NULL));
	for (j = -1, i = 0; i < flakes -> total; i++, j--) {
		flakes -> buff[i].y = j;
		flakes -> buff[i].x = rand() % COLS;
		i++;
		flakes -> buff[i].y = j;
		flakes -> buff[i].x = rand() % COLS;
	}
	snowdrift = (int *) calloc(COLS, sizeof(int));
	
	if (snowdrift == NULL) {
		fprintf(stderr, "malloc: failed to allocate memory!\n");
		abort();
	}

	return 0;
}

int flake_move(SNOW *flakes)
{
	int i;

	for (i = 0; i < flakes -> total; i++) {
		if (!flakes -> buff[i].cover && flakes -> buff[i].y >= 0)
			// Clear the flakes
			mvaddch(flakes -> buff[i].y, flakes -> buff[i].x, ' ');

		// Move the flakes down
		flakes -> buff[i].y++;
		if (flakes -> buff[i].y >= LINER) {
			/* Increase the counter and check if we have enough show flakes to make a snowdrift */
			snowdrift[flakes -> buff[i].x]++;
			if (snowdrift[flakes -> buff[i].x] == SNOWDRIFT) {
				/* if so, print the snowdrift and reset the counter */
				mvaddch(LINER, flakes -> buff[i].x, '*');
				snowdrift[flakes -> buff[i].x] = 0;
			}

			/* Reset the positions, and `cover`*/
			/* and goto the next flake         */
			flakes -> buff[i].y = -1;
			flakes -> buff[i].x = rand() % COLS;
			flakes -> buff[i].cover = 0;

			continue;
		}

		flakes -> buff[i].cover = cover(flakes -> buff[i].y, flakes -> buff[i].x);  // Update `cover`
		if (!flakes -> buff[i].cover)
			// Print the flakes
			mvaddch(flakes -> buff[i].y, flakes -> buff[i].x, '*');
	}
	refresh();
	return 0;
}

_Bool cover(int y, int x)
{
	int start, end, tmp = 0;
	if (y >= TREE_START) {  // Get the start and the end of the tree on this line
		start = find_sol(y - TREE_START, &tmp);
		end = STAR_B - start + STAR_A;
	}
	else return 0; // If the flake hasn't reached the start of the tree,
	               // it won't cover anything
	//if (x != start && x != end && !tmp)
	//	return 0;
	if (x < start || x > end)
		return 0;
	return 1;
}

