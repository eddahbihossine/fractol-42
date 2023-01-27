/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:44:14 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 22:16:23 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_color(t_data *data)
{
	double	ratio;
	int		color;

	if (data->prms.color == 0)
		color = 0x00955251;
	if (data->prms.color == 1)
		color = 0x00009B77;
	if (data->prms.color == 2)
		color = 0x0000A170;
	if (data->prms.color == 3)
		color = 0x00FFA500;
	ft_color2(data, &color);
	ratio = (double)(data->prms.itr) / (double)data->prms.max_itr ;
	return (ratio * color);
}

int	ft_color2(t_data *data, int *color)
{
	if (data->prms.color == 4)
		*color = 0x009A8B4F;
	if (data->prms.color == 5)
		*color = 0x00944743;
	if (data->prms.color == 6)
		*color = 0x00e3e3e3;
	if (data->prms.color == 7)
		*color = 0x0063A75A;
	return (EXIT_SUCCESS);
}
