/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:49:50 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/18 02:08:49 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void	bonus_fractal(t_win *winvars,double zoom)
{
	winvars->params.h =0;
	winvars->params.w =0;
	while (winvars->params.h < max_x)
	{
		winvars->params.w = 0;
		while (winvars->params.w< max_y)
		{
			init_all(winvars,zoom);
		while(winvars->params.x * winvars->params.x + winvars->params.y*winvars->params.y < 4 && ++winvars->params.iteration < winvars->params.max_iteration)
		{
			winvars->params.temporary =winvars->params.x*winvars->params.x  - winvars->params.y*winvars->params.y  + winvars->params.cx;
			winvars->params.y = -2*winvars->params.x * winvars->params.y + winvars->params.cy;
			winvars->params.x = winvars->params.temporary;
			winvars->params.y = winvars->params.y;
		}
		if(winvars->params.iteration == winvars->params.max_iteration)
			my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h, 0x00ff);
		else
			my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h,sinh(winvars->params.iteration >> 32));
		winvars->params.w++;
		}
		winvars->params.h++;
	}	
}