#include <SDL2/SDL.h>
#include "brush.h"

int plot(void* renderer, int x, int y)
{
	SDL_RenderDrawPoint(renderer, x, y);
}

int setColor(void* renderer, uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}


int main(int argc,char* argv[])
{
    /* 初始化并创建窗口 */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = NULL;
    win = SDL_CreateWindow("SDL2",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                            640,400,SDL_WINDOW_RESIZABLE);
     
    /* 创建Renderer */
    SDL_Renderer* render = NULL;
    render = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
    /* 清空Render */
    SDL_RenderClear(render);
    
	/*************************************************************/
	HB_SetPixelFunction(plot);
	HB_SetColorFunction(setColor);
	HB_SetColor((void*)render, 255,0,0,0);
	HB_Line((void*)render, 300,000,300,400);
	HB_FillCircle(render, 100, 100, 50);
	/*************************************************************/
	
    /* 显示Render */
    SDL_RenderPresent(render);
 
    /* 等待退出 */
    SDL_Event e;
    while(1)
    {
        SDL_PollEvent(&e); 
        if(e.type == SDL_QUIT)
        {
            break;
        }
    }
    /* 销毁renderer */
    SDL_DestroyRenderer(render);
    /* 销毁窗口 */
    SDL_DestroyWindow(win);
    /* 关闭SDL子系统 */
    SDL_Quit();
     
    return 0;
}