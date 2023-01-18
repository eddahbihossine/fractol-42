/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:50:06 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/18 02:23:47 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
int	key_hook(int keycode, t_win *vars)
{
	if(keycode == 53)
		printf("5465465");
	return(1);
}

int main(int ac, char **av)
{
	t_win win;
	double zoom ;
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx,max_x,max_y,"mandelbrot");
	win.img = mlx_new_image(win.mlx,max_x,max_y);
	win.addr =mlx_get_data_addr(win.img,&win.bits_per_pixel,&win.line_length,&win.endian);
	
		if (read_arguments(ac,av) == 1)
		{
			mlx_hook(win.mlx_win, 4, 0, julia_mouse_hook,&win);
			mlx_hook(win.mlx_win, 6, 0, julia_mouse_hook, &win);
		}
			
		if (read_arguments(ac,av) == 2)
		{
			mlx_key_hook(win.mlx_win,key_hook,&win);
			mlx_hook(win.mlx_win, 4, 0, mandelbrot_mouse_hook,&win);
			mlx_hook(win.mlx_win, 6, 0, mandelbrot_mouse_hook,&win);
			mlx_hook(win.mlx_win, 53, 0, mandelbrot_key_event,&win);
			// mlx_loop_hook(win.mlx,mandelbrot_key_event,&win);
		}	
		if (read_arguments(ac,av) == 3)
		{
			mlx_hook(win.mlx_win, 4, 0, bonus_mouse_hook,&win);
			mlx_hook(win.mlx_win, 6, 0, bonus_mouse_hook, &win);
		 }
		 
	mlx_put_image_to_window(win.mlx,win.mlx_win,win.img,0,0);
	mlx_loop(win.mlx);								
} 