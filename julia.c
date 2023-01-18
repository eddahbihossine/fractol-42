#include "fractol.h"


void julia (t_win *winvars,double zoom)
{
	winvars->params.h =-1;
while (++winvars->params.h < max_x)
{
    winvars->params.w = 0;
    while (++winvars->params.w < max_y)
    {
       init_julia(winvars,zoom);
	   	winvars->params.x = (winvars->params.w* 4 / (max_y *zoom )) - 2 /zoom;
		winvars->params.y = (winvars->params.h * 4 / (max_y * zoom)) - 2 /zoom;
        while(winvars->params.x*winvars->params.x + winvars->params.y*winvars->params.y <= 4 && ++winvars->params.iteration < winvars->params.max_iteration)
        {
            winvars->params.temporary = winvars->params.x*winvars->params.x - winvars->params.y*winvars->params.y + winvars->params.cx;
            winvars->params.y = 2*winvars->params.x*winvars->params.y + winvars->params.cy;
            winvars->params.x = winvars->params.temporary;
        }
        if(winvars->params.iteration == winvars->params.max_iteration)
            my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h,0x00FF00F5);
        else
            my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h,sinhl(winvars->params.iteration));
    }
}
}
