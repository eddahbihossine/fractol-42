#if !defined(FRACTOL_H)
#define FRACTOL_H

#include<math.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mlx.h"
#define max_x 700
#define max_y 700


typedef struct	s_var{
	double x;
	double y;
	double windowxmax;
	double windowymax;
	int iteration;
	int max_iteration;
	double temporary;
	double tmp;

}			var;
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double map(double x, double in_min, double in_max, double out_min, double out_max);
void mandelbrot (var img,t_data hello);
void julia (var img,t_data hello);
void set_color(t_data *hello, double iteration, double max_iteration, int x, int y);
void hsv_to_rgb(double h, double s, double v, int *r, int *g, int *b);



#endif 
