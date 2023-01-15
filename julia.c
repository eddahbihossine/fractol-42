#include "fractol.h"


void julia (t_win winvars)
{
	winvars.params.iteration = 0.0;
	winvars.params.max_iteration = 80.0;
	double h = 0;
	double w = 0;
	double c_x =   -0.8; 
	double c_y = 0.145;
	int i ;

	while (h < max_x)
	{
		i =0;
		w = 0;
		while (w < max_y)
		{
			winvars.params.x = (w * 4 / (max_x )) - 2;
			winvars.params.y = (h * 4 / (max_y )) - 2;
			winvars.params.iteration = 0;
			while (winvars.params.x * winvars.params.x + winvars.params.y * winvars.params.y <= 4 && ++winvars.params.iteration < winvars.params.max_iteration)
			{
				winvars.params.temporary = winvars.params.x * winvars.params.x - winvars.params.y * winvars.params.y + c_x;
				winvars.params.y = 2 * winvars.params.x * winvars.params.y + c_y;
				winvars.params.x = winvars.params.temporary;
			}
			i++;
			if (!(winvars.params.iteration == winvars.params.max_iteration))
			{
				my_mlx_pixel_put(&winvars, w, h,0x00FFFF00 >> (int)&winvars.params.temporary);

			}
			else
			{
				get_color(&winvars, winvars.params.iteration, winvars.params.max_iteration, w, h);
			}
			w++;
		}
		h++;
	}
	
}
