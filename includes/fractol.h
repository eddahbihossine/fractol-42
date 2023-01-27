/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:28:34 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 23:55:13 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# define MAX_X 700.00
# define MAX_Y 700.00

typedef struct mainvars{
	double	x;
	double	y;
	double	h;
	double	w;
	double	cx;
	double	cy;
	int		itr;
	int		max_itr;
	double	xtmp;
	double	ax;
	double	ay;
	int		return_this;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	int		color;
	double	r;
	double	i;
}				t_var;
typedef struct winvars{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}				t_win;

typedef struct allvars
{
	t_var	prms;
	t_win	winvars;
}				t_data;

void	mandelbrot(t_data *winvars);
void	tricorn_bonus(t_data *data);
void	init_all(t_data *data );
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mandelbrot_zoom(int keycode, int x, int y, t_data *data);
int		key_event(int keycode, t_data *data);
int		key_event2(int keycode, t_data *data);
void	check_args(int argc, char	**argv, t_data *win);
void	choose(t_data *data);
int		mouse_event(int x, int y, t_data *data);
void	julia(t_data *data);
void	init_julia(t_data *data );
void	ft_check(t_data *data);
int		read_arguments(int ac, char **av, t_data *data);
int		key_event3(int keycode, t_data *data);
int		ft_color(t_data *data);
int		ft_color2(t_data *data, int *color);
void	parse_julia(t_data *data, int argc, char **argv);
int		key_mask(int keycode, t_data *data);
void	check_julia(t_data *data);
void	draw_julia(t_data *data);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
// int		destroy_this(int keycode, t_data *data);
#endif // FRACTOL_H
