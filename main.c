/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:50:06 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/17 14:12:13 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot_mouse_hook (int param , t_win window)
{
	 static double zoom = 1;
	if(param == 4)
	{
		zoom *= 1.9;
		printf("helloo\n");
	}
	else
		printf("bye\n");
	
	return(0);
}
int read_arguments(int ac, char **av)
{
	if(strncmp(av[1] ,"julia",6) == 0)
		return(1);
	if(strcmp(av[1] ,"mandelbrot") == 0)
		return(2);
	if(strcmp(av[1] ,"bonus") == 0)
		return(3);
	return(0);										
}

int main(int ac, char **av)
{
	t_win win;
	double zoom = 1;
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx,max_x,max_y,"mandelbrot");
	win.img = mlx_new_image(win.mlx,max_x,max_y);
	win.addr =mlx_get_data_addr(win.img,&win.bits_per_pixel,&win.line_length,&win.endian);
	
		if(ac == 2)
		{
		if (read_arguments(ac,av) == 1)
		
			julia(&win,zoom);
		if (read_arguments(ac,av) == 2)
			mandelbrot(&win,zoom);
			
		if (read_arguments(ac,av) == 3)
			bonus_fractal(&win,zoom);
		 }
	mlx_mouse_hook(win.mlx_win, mandelbrot_mouse_hook, &win);
	mlx_put_image_to_window(win.mlx,win.mlx_win,win.img,0,0);	
	mlx_loop(win.mlx);								
} 