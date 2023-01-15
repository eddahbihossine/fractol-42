/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:49:50 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/15 19:28:10 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void bonus_fractal (t_win winvars)
{
	winvars.params.iteration =0.0;
	winvars.params.max_iteration =80.0;		
	double h = 0;
	double w= 0;
	int i =0;
	while(h < max_x)
	{
		w=0;
		while(w < max_y)
		{
			winvars.params.x =0;
			winvars.params.y=0;
			double x0;
			double y0;
			// x0=(w*4/max_x/zoom)-2/zoom;
			// y0=(h*4/max_y/zoom)-2/zoom;
			x0 =map(w,0,max_x,-2,2);
			y0 =map(h,0,max_y,-2,2);
			winvars.params.iteration = 0;
		while(winvars.params.x*winvars.params.x + winvars.params.y*winvars.params.y <= 4 && ++winvars.params.iteration < winvars.params.max_iteration)
		{
			winvars.params.temporary =pow(winvars.params.x,2) - pow(winvars.params.y,2) +x0;
			winvars.params.y = -2*winvars.params.x*winvars.params.y + y0;
			winvars.params.x =winvars.params.temporary;
			// params.iteration++;
		}
			i++;
		if(winvars.params.iteration == winvars.params.max_iteration){
			my_mlx_pixel_put(&winvars,w,h,winvars.params.iteration/ i);
		}
		else
			my_mlx_pixel_put(&winvars,w,h,winvars.params.iteration *winvars.params.max_iteration * (int)&i);
		w++;
		}
		h++;
	}
}