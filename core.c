#include "core.h"

int HB_SetColor(void* userdata, uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	HB_GlobalState.red = red;
	HB_GlobalState.green = green;
	HB_GlobalState.alpha = alpha;
	HB_GlobalState.setColor(userdata, red, green, blue, alpha);
	
	return 0;
}
int HB_PutPixel(void* userdata, int x, int y)
{
	HB_GlobalState.putPixel(userdata, x, y);
	
	return 0;
}


int HB_SetPixelFunction(HB_PixelFunction pixel)
{
	HB_GlobalState.putPixel = pixel;
}


int HB_SetColorFunction(HB_ColorFunction color)
{
	HB_GlobalState.setColor = color;
}

