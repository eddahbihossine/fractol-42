/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:14:30 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 22:54:20 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	scroll_up_map(t_data *data, int x, int y)
{
		data->prms.xmin = (data->prms.xmin + ((data->prms.ax * x)) * 0.2);
		data->prms.xmax = (data->prms.xmax - ((data->prms.ax * (MAX_X - x))
				* 0.2));
		data->prms.ymin = (data->prms.ymin + ((data->prms.ay * y))
			* 0.2);
		data->prms.ymax = (data->prms.ymax - ((data->prms.ay * (MAX_Y - y))
				* 0.2));
}

void	scroll_down_map(t_data *data, int x, int y)
{
		data->prms.xmin = (data->prms.xmin - ((data->prms.ax * x)) * 0.2);
		data->prms.xmax = (data->prms.xmax + ((data->prms.ax * (MAX_X - x))
				* 0.2));
		data->prms.ymin = (data->prms.ymin - ((data->prms.ay * y)) * 0.2);
		data->prms.ymax = (data->prms.ymax + ((data->prms.ay * (MAX_Y - y))
				* 0.2));
}

int	mandelbrot_zoom(int keycode, int x, int y, t_data *data)
{
	data->prms.ax = (data->prms.xmin - data->prms.xmax) / MAX_X;
	data->prms.ay = (data->prms.ymin - data->prms.ymax) / MAX_Y;
	if (keycode == 4)
	{
		scroll_up_map(data, x, y);
		choose(data);
		mlx_put_image_to_window(data->winvars.mlx, data->winvars.mlx_window,
			data->winvars.img, 0, 0);
	}
	if (keycode == 5)
	{
		scroll_down_map(data, x, y);
		choose(data);
		mlx_put_image_to_window(data->winvars.mlx, data->winvars.mlx_window,
			data->winvars.img, 0, 0);
	}
	return (0);
}

void	choose(t_data *data)
{
	mlx_clear_window(data->winvars.mlx, data->winvars.mlx_window);
	mlx_destroy_image(data->winvars.mlx, data->winvars.img);
	data->winvars.img = mlx_new_image(data->winvars.mlx, 700, 700);
	data->winvars.addr = mlx_get_data_addr(data->winvars.img,
			&data->winvars.bits_per_pixel,
			&data->winvars.line_length, &data->winvars.endian);
	if (data->prms.return_this == 1)
		julia(data);
	if (data->prms.return_this == 2)
		mandelbrot(data);
	if (data->prms.return_this == 3)
		tricorn_bonus(data);
}
