/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:50:06 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/16 00:53:03 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
int j(int parm){
	printf("%d\n",parm);
	return 0;
}
// int excution()
// {
// 	if (zoomin)
// 		zoom *= 1.1
// 	else	
// 		zomm *= 0.9
// 	if argv[1] == mandelbrot
// 		mandelbrot
	
// 	return (0);
// }
// int read_arg(int *ac ,char	**av)
// {
// 	if(read_arguments(*ac,av) == 1)
// 		return();
// }
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
	win.mlx = mlx_init();
	win.mlx_win = mlx_new_window(win.mlx,max_x,max_y,"mandelbrot");
	win.img = mlx_new_image(win.mlx,max_x,max_y);
	win.addr =mlx_get_data_addr(win.img,&win.bits_per_pixel,&win.line_length,&win.endian);
	
		if(ac == 2)
		{
		if (read_arguments(ac,av) == 1)
			julia(win);
		if (read_arguments(ac,av) == 2)
			mandelbrot(win);
		if (read_arguments(ac,av) == 3)
			bonus_fractal(win);
		}
	mlx_put_image_to_window(win.mlx,win.mlx_win,win.img,0,0);
	mlx_loop(win.mlx);
								
	
}

