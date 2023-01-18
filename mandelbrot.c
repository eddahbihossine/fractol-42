/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:50:09 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/17 22:34:02 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_win *winvars , double zoom)
{
	winvars->params.h = -1;
	while (++winvars->params.h < max_x)
	{
		winvars->params.w = -1;
		while (++winvars->params.w < max_y)
		{
			init_all(winvars,zoom);	
		while(winvars->params.x * winvars->params.x + winvars->params.y*winvars->params.y < 4 && winvars->params.iteration < winvars->params.max_iteration)
		{
			winvars->params.temporary = winvars->params.x *winvars->params.x - winvars->params.y *winvars->params.y  + winvars->params.cx;
			winvars->params.y = 2*(winvars->params.x * winvars->params.y) + winvars->params.cy;
			winvars->params.x = winvars->params.temporary;
			winvars->params.iteration++;
		}
		if(winvars->params.iteration == winvars->params.max_iteration)
			my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h, 0x01FF2ff00 >> 12);
		else
			my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h,0x00215FF00 >= 255);
		}
	}
}
