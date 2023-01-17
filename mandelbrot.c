/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:50:09 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/17 13:42:43 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_win *winvars , double zoom)
{
	winvars->params.h =0;
	winvars->params.w =0;
	while (winvars->params.h < max_x)
	{
		winvars->params.w = 0;
		while (winvars->params.w< max_y)
		{
			init_all(winvars,zoom);
		while(winvars->params.x*winvars->params.x + winvars->params.y*winvars->params.y <= 4 && ++winvars->params.iteration < winvars->params.max_iteration)
		{
			winvars->params.temporary =pow(winvars->params.x,2) - pow(winvars->params.y,2) + winvars->params.cx;
			winvars->params.y = 2*winvars->params.x * winvars->params.y + winvars->params.cy;
			winvars->params.x =winvars->params.temporary;
		}
		if(winvars->params.iteration == winvars->params.max_iteration)
			my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h,(int)&winvars->params.iteration) ;
		else
			my_mlx_pixel_put(winvars,winvars->params.w,winvars->params.h,0x02FFFF00);
		winvars->params.w++;
		}
		winvars->params.h++;
	}	
}
