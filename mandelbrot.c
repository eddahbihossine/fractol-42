#include "fractol.h"
void mandelbrot (var img,t_data hello)
{
	img.iteration =0.0;
	img.max_iteration =80.0;		
	double h = 0;
	double w= 0;
	static int i = 1;
	while(h < max_x)
	{
		w=0;
		while(w < max_y)
		{
			img.x =0;
			img.y=0;
			double x0;
			double y0;
			x0=(w*4/max_x)-2;
			y0=(h*4/max_y)-2;
			// x0 =map(w,0,500,-2,2);
			// y0 =map(h,0,500,-2,2);
			img.iteration = 0;
		while(img.x*img.x + img.y*img.y <= 4 && ++img.iteration < img.max_iteration)
		{
			img.temporary =pow(img.x,2) - pow(img.y,2) +x0;
			img.y = 2*img.x*img.y + y0;
			img.x =img.temporary;
			// img.iteration++;
		}
			i++;
		if(img.iteration == img.max_iteration){
			my_mlx_pixel_put(&hello,w,h,img.iteration/ i);
		}
		else
			my_mlx_pixel_put(&hello,w,h,img.iteration *img.max_iteration /9*i);
		w++;
		}
		h++;
	}
}
