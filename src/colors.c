#include "colors.h"

void init_colors(void)
{
	start_color();
	use_default_colors();
	init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
	init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
	init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
	init_pair(RED, COLOR_RED, COLOR_BLACK);
	init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
}

