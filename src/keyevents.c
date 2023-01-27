/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevents.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:46:33 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 23:31:31 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_event3(int keycode, t_data *data);

int	key_event(int keycode, t_data *data)
{
	double	ax;

	ax = (data->prms.xmin - data->prms.xmax) / MAX_X;
	if (keycode == 53)
	{
		mlx_destroy_image(data->winvars.mlx, data->winvars.img);
		mlx_destroy_window(data->winvars.mlx, data->winvars.mlx_window);
		exit(1);
	}
	if (keycode == 124 || keycode == 123)
	{
		if (keycode == 123)
			ax *= -1;
		data->prms.xmin += ax / 0.09;
		data->prms.xmax += ax / 0.09;
		choose(data);
		mlx_put_image_to_window(data->winvars.mlx, data->winvars.mlx_window,
			data->winvars.img, 0, 0);
	}
	key_event2(keycode, data);
	key_event3(keycode, data);
	return (EXIT_SUCCESS);
}

int	key_event2(int keycode, t_data *data)
{
	double	ay;

	ay = (data->prms.ymin - data->prms.ymax) / MAX_Y;
	if (keycode == 125 || keycode == 126)
	{
		if (keycode == 125)
			ay *= -1;
		data->prms.ymin += ay / 0.09;
		data->prms.ymax += ay / 0.09;
		choose(data);
		mlx_put_image_to_window(data->winvars.mlx, data->winvars.mlx_window,
			data->winvars.img, 0, 0);
	}
	return (1);
}

int	key_event3(int keycode, t_data *data)
{
	if (keycode == 4)
	{
		data->prms.color += 1;
		if (data->prms.color == 7)
		{
			data->prms.color = 1;
		}
		choose(data);
		mlx_put_image_to_window(data->winvars.mlx, data->winvars.mlx_window,
			data->winvars.img, 0, 0);
	}
	return (EXIT_SUCCESS);
}

int	key_mask(int keycode, t_data *data)
{
	if (keycode == 0)
		data->prms.cx += 0.1;
	if (keycode == 2)
		data->prms.cx -= 0.1;
	if (keycode == 13)
		data->prms.cy += 0.1;
	if (keycode == 1)
		data->prms.cy -= 0.1;
	julia(data);
	key_event(keycode, data);
	return (0);
}
