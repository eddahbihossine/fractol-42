#include "fractol.h"


void julia (t_win *winvars,double zoom)
{
double h ;
double w;
while (h < max_x)
{
    w = 0;
    while (w < max_y)
    {
       init_julia(winvars,zoom);
	   	winvars->params.x = (w * 4 / (max_x)) - 2;
		winvars->params.y = (h * 4 / (max_y)) - 2;
        while(winvars->params.x*winvars->params.x + winvars->params.y*winvars->params.y <= 4 && ++winvars->params.iteration < winvars->params.max_iteration)
        {
            winvars->params.temporary = pow(winvars->params.x,2) - pow(winvars->params.y,2) + winvars->params.cx;
            winvars->params.y = 2*winvars->params.x*winvars->params.y + winvars->params.cy;
            winvars->params.x = winvars->params.temporary;
        }
        if(winvars->params.iteration == winvars->params.max_iteration)
            my_mlx_pixel_put(winvars,w,h,0x02000000);
        else
            my_mlx_pixel_put(winvars,w,h,0x02FFFF00);
        w++;
    }
    h++;
}
}
