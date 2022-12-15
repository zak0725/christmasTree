#include "colors.h"

void init_colors(void)
{
	start_color();
	use_default_colors();
	init_pair(CYAN, COLOR_CYAN, COLB_DEF);
	init_pair(GREEN, COLOR_GREEN, COLB_DEF);
	init_pair(YELLOW, COLOR_YELLOW, COLB_DEF);
	init_pair(RED, COLOR_RED, COLB_DEF);
	init_pair(WHITE, COLOR_WHITE, COLB_DEF);
	init_pair(B_A_W, COLOR_BLACK, COLOR_WHITE);
}

