/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:03:48 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 23:32:37 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static	void	ft_draw(t_data *data)
{
	if (data->prms.itr == data->prms.max_itr)
		my_mlx_pixel_put(data, data->prms.w, data->prms.h,
			0x00F5eb80 + (0x00e2e5c3d3 * data->prms.itr));
	else
		my_mlx_pixel_put(data, data->prms.w, data->prms.h,
			ft_color(data) + (0x00e3e3e3a3 * data->prms.itr));
}

static	double	power(double a)
{
	return (a * a);
}

static	int	check_prms(t_data *data)
{
	if (data->prms.x * data->prms.x + data->prms.y * data->prms.y <= 4)
		return (1);
	return (0);
}

void	tricorn_bonus(t_data *data)
{
	static int	check = 0;

	data->prms.h = -1;
	while (++data->prms.h < MAX_X)
	{
		data->prms.w = -1;
		while (++data->prms.w < MAX_Y)
		{
			if (!check)
				ft_check(data);
				check++;
			init_all(data);
			while (check_prms(data) && ++data->prms.itr < data->prms.max_itr)
			{
				data->prms.xtmp = power(data->prms.x)
					- power(data->prms.y) + data->prms.r;
				data->prms.y = -2 * data->prms.x * data->prms.y
					- data->prms.i ;
			data->prms.x = data->prms.xtmp;
			}
			ft_draw(data);
		}
	}
}
