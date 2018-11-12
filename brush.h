#ifndef HIDE_ON_BRUSH_H
#define HIDE_ON_BRUSH_H

#ifdef __cplusplus
	extern "C" {
#endif

#include "core.h"

int HB_Line(void* userdata, int x1, int y1, int x2, int y2);
int HB_Circle(void* userdata, int x, int y, int r);
int HB_FillCircle(void* userdata, int x, int y, int r);


#ifdef __cplusplus
	}
#endif

#endif