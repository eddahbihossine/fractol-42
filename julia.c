#include "fractol.h"


void julia (var img, t_data hello)
{
	img.iteration = 0.0;
	img.max_iteration = 150.0;
	double h = 0;
	double w = 0;
	double c_x =  -0.4; 
	double c_y = -0.59;
	int i ;

	while (h < max_x)
	{
		i =0;
		w = 0;
		while (w < max_y)
		{
			img.x = (w * 4 / max_x) - 2;
			img.y = (h * 4 / max_y) - 2;
			img.iteration = 0;
			while (img.x * img.x + img.y * img.y <= 4 && ++img.iteration < img.max_iteration)
			{
				img.temporary = img.x * img.x - img.y * img.y + c_x;
				img.y = 2 * img.x * img.y + c_y;
				img.x = img.temporary;
			}
			i++;
			if (!(img.iteration == img.max_iteration))
			{
				set_color(&hello, img.iteration, img.max_iteration, w, h);

			}
			else
			{
				my_mlx_pixel_put(&hello, w, h,(int)(&img.max_iteration)* img.max_iteration);
			}
			w++;
		}
		h++;
	}
}

