#include "fractol.h"
void mandelbrot (var img,t_data hello)
{
	img.iteration =0.0;
	img.max_iteration =80.0;		
	double h = 0;
	double w= 0;
	int i = 1;
	while(h < 500)
	{
		w=0;
		while(w < 500)
		{
			img.x =0;
			img.y=0;
			double x0;
			double y0;
			x0=(w*4/500)-2;
			y0=(h*4/500)-2;
			// x0 =map(w,0,500,-2,2);
			// y0 =map(h,0,500,-2,2);
			img.iteration = 0;
		while(img.x*img.x + img.y*img.y <= 4 && img.iteration < img.max_iteration)
		{
			img.temporary =pow(img.x,2) - pow(img.y,2) +x0;
			img.y = 2*img.x*img.y + y0;
			img.x =img.temporary;
			img.iteration++;
			i++;
		}
		if(img.iteration == img.max_iteration){
			my_mlx_pixel_put(&hello,w,h, 0x00FFFFFFf + img.iteration + 8*i );
		}
		else
			my_mlx_pixel_put(&hello,w,h,0xFFF58FF + img.iteration>> 128);
		w++;
		}
		h++;
	}
}
