/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:50:01 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/15 19:50:43 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

}			t_var;

typedef struct winvars
{
	t_var	params;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		zoom;

}				t_win;

void	my_mlx_pixel_put(t_win *data, int x, int y, int color);
double 	map(double x, double in_min, double in_max, double out_min, double out_max);
void 	mandelbrot (t_win winvars);
void 	julia (t_win winvars);
void 	get_color(t_win *hello, double iteration, double max_iteration, int x, int y);
void	params_to_rgb(double h, double s, double v, int *r, int *g, int *b);
void 	bonus_fractal (t_win winvars);


#endif 
