#if !defined(FRACTOL_H)
#define FRACTOL_H

#include<math.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

typedef struct	s_var{
	double x;
	double y;
	double windowxmax;
	double windowymax;
	int iteration;
	int max_iteration;
	double temporary;

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



#endif 
