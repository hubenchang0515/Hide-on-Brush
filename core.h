#ifndef HIDE_ON_BRUSH_CORE_H
#define HIDE_ON_BRUSH_CORE_H

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>

typedef int (*HB_PixelFunction)(void* userdata, int x, int y);
typedef int (*HB_ColorFunction)(void* userdata, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

typedef struct HB_State
{
	HB_PixelFunction putPixel;
	HB_ColorFunction setColor;
	int8_t red; 
	int8_t green; 
	int8_t blue; 
	int8_t alpha;
}HB_State;

 HB_State HB_GlobalState;

int HB_SetPixelFunction(HB_PixelFunction pixel);
int HB_SetColorFunction(HB_ColorFunction color);
int HB_SetColor(void* userdata, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
int HB_PutPixel(void* userdata, int x, int y);

#ifdef __cplusplus
	}
#endif

#endif