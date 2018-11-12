#include "brush.h"
#include <math.h>
#include <stdio.h>

static void swap(int* n, int* m);

/* Bresenham's line algorithm 
 * https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 */
int HB_Line(void* userdata, int x1, int y1, int x2, int y2)
{
	int steep = abs(y2 - y1) > abs(x2 - x1);
	if(steep)
	{
		swap(&x1, &y1);
		swap(&x2, &y2);
	}
	if(x1 > x2)
	{
		swap(&x1, &x2);
		swap(&y1, &y2);
	}
	
	int delta_x = x2 - x1;
	int delta_y = abs(y2 - y1);
	int error = delta_x >> 1;
	int y_step = y1 < y2 ? 1 : -1;
	int y = y1;
	for(int x = x1; x <= x2; x++)
	{
		if(steep)
		{
			HB_GlobalState.putPixel(userdata, y, x);
		}
		else
		{
			HB_GlobalState.putPixel(userdata, x, y);
		}
		error -= delta_y;
		if(error < 0)
		{
			y += y_step;
			error += delta_x;
		}
	}
}


/* Midpoint circle algorithm 
 * https://en.wikipedia.org/wiki/Midpoint_circle_algorithm 
 */
int HB_Circle(void* userdata, int x, int y, int r)
{
	int vx = r - 1;
	int vy = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (r << 1);
	
	while(vx >= vy)
	{
		HB_GlobalState.putPixel(userdata, x + vx, y + vy);
		HB_GlobalState.putPixel(userdata, x + vy, y + vx);
		HB_GlobalState.putPixel(userdata, x - vy, y + vx);
		HB_GlobalState.putPixel(userdata, x - vx, y + vy);
		HB_GlobalState.putPixel(userdata, x - vx, y - vy);
		HB_GlobalState.putPixel(userdata, x - vy, y - vx);
		HB_GlobalState.putPixel(userdata, x + vy, y - vx);
		HB_GlobalState.putPixel(userdata, x + vx, y - vy);
		if(err <= 0)
		{
			vy++;
			err += dy;
			dy += 2;
		}
		else
		{
			vx--;
			dx += 2;
			err += dx - (r << 1);
		}
	}
}

/* Midpoint circle algorithm 
 * https://en.wikipedia.org/wiki/Midpoint_circle_algorithm 
 */
int HB_FillCircle(void* userdata, int x, int y, int r)
{
	int vx = r - 1;
	int vy = 0;
	int dx = 1;
	int dy = 1;
	int err = dx - (r << 1);
	
	while(vx >= vy)
	{

		HB_Line(userdata, x, y, x + vx, y + vy);
		HB_Line(userdata, x, y, x + vy, y + vx);
		HB_Line(userdata, x, y, x - vy, y + vx);
		HB_Line(userdata, x, y, x - vx, y + vy);
		HB_Line(userdata, x, y, x - vx, y - vy);
		HB_Line(userdata, x, y, x - vy, y - vx);
		HB_Line(userdata, x, y, x + vy, y - vx);
		HB_Line(userdata, x, y, x + vx, y - vy);
		
		if(err <= 0)
		{
			vy++;
			err += dy;
			dy += 2;
		}
		else
		{
			vx--;
			dx += 2;
			err += dx - (r << 1);
		}
	}
}

/* STATIC FUNCTIONS */
static void swap(int* n, int* m)
{
	*n ^= *m;
	*m ^= *n;
	*n ^= *m;
}