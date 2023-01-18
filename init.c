#include "fractol.h"

void init_all(t_win *winvars,double zoom)
{
	winvars->params.x = 0;
	winvars->params.y = 0;
	winvars->params.iteration = 0;
	winvars->params.max_iteration = 30;	
	winvars->params.cx = (winvars->params.w* 4 / (max_x * zoom)) - 2 /zoom;
	winvars->params.cy = (winvars->params.h* 4 / (max_y *zoom )) - 2 /zoom;
}
void init_julia(t_win *winvars ,double zoom)
{
	winvars->params.iteration = 0.0;
	winvars->params.max_iteration = 100.0;
	winvars->params.cx = -0.8 ;
	winvars->params.cy = 0.145;
}