/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:49:09 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 22:16:41 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->winvars.addr + (y * data->winvars.line_length
			+ x * (data->winvars.bits_per_pixel / 8));
				*(unsigned int *)dst = color;
}

void	draw_julia(t_data *data)
{
	julia(data);
	mlx_mouse_hook(data->winvars.mlx_window, mandelbrot_zoom, data);
	mlx_key_hook(data->winvars.mlx_window, key_mask, data);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (!str1[i] ||!str2[i])
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
