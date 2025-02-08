#include "colors.h"

void init_colors(void)
{
	start_color();
	use_default_colors();
	init_pair(CYAN, COLOR_CYAN, -1);
	init_pair(GREEN, COLOR_GREEN, -1);
	init_pair(YELLOW, COLOR_YELLOW, -1);
	init_pair(RED, COLOR_RED, -1);
	init_pair(WHITE, COLOR_WHITE, -1);
}

