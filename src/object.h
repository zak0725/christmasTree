#ifndef _OBJECT_H
# define _OBJECT_H

typedef struct {
	char icon;
	int x, y;
	int color;
} OBJECT;

typedef struct {
	OBJECT *buff;
	int maxx, maxy;
} SCR;

typedef struct {
	int x, y;
} SNOWFLAKE;

typedef struct {
	SNOWFLAKE *buff;
	int total;
} SNOW;

typedef int GND;

/*typedef struct {
	int ct;
} GND;*/

#endif

