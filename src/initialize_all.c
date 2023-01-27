/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:32:36 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 22:21:14 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_all(t_data *data)
{
	data->prms.x = 0;
	data->prms.y = 0;
	data->prms.itr = 0;
	data->prms.r = data->prms.xmin + (data->prms.w
			* (data->prms.xmax - data->prms.xmin) / MAX_X);
	data->prms.i = data->prms.ymax - (data->prms.h
			* (data->prms.ymax - data->prms.ymin) / MAX_Y);
}

void	init_julia(t_data *data )
{
	data->prms.x = 0;
	data->prms.y = 0;
	data->prms.itr = 0.0;
	data->prms.max_itr = 70.0;
}

void	check_julia(t_data *data)
{
	data->prms.xmin = -2;
	data->prms.xmax = 2;
	data->prms.ymin = -2;
	data->prms.ymax = 2;
	data->prms.max_itr = 60;
	data->prms.color = 0;
}
