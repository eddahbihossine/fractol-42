/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:45:56 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 23:56:24 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	read_arguments(int ac, char **av, t_data *data)
{
	if (ac <= 1)
		return (4);
	if (!(ft_strncmp(av[1], "julia", 6)))
	{
		data->prms.return_this = 1;
		return (1);
	}
	if (!(ft_strncmp(av[1], "mandelbrot", 11)))
	{
		data->prms.return_this = 2;
		return (2);
	}
	if (!(ft_strncmp(av[1], "tricorn", 8)))
	{
		data->prms.return_this = 3;
		return (3);
	}
	else
		return (4);
	return (EXIT_SUCCESS);
}

int	read_this(int ac)
{
	if (ac <= 1)
		return (1);
	return (0);
}

void	execute_all( int ac, char **av, t_data *data)
{
	if (read_arguments(ac, av, data) == 1)
	{
		parse_julia(data, ac, av);
	}
	if (read_arguments(ac, av, data) == 2)
	{
		mandelbrot(data);
		mlx_key_hook(data->winvars.mlx_window, key_event, data);
		mlx_mouse_hook(data->winvars.mlx_window, mandelbrot_zoom, data);
	}
	if (read_arguments(ac, av, data) == 3)
	{
		tricorn_bonus(data);
		mlx_key_hook(data->winvars.mlx_window, key_event, data);
		mlx_mouse_hook(data->winvars.mlx_window, mandelbrot_zoom, data);
	}
	if (read_arguments(ac, av, data) == 4 || read_this(ac))
	{
		write(1, "**HINT:\n", 9);
		write(1, "./frac-ol mandelbrot\n", 22);
		write(1, "./frac-ol julia\n", 16);
		write(1, "./frac-ol tricorn\n", 18);
		exit(1);
	}
}

int	main(int ac, char *av[])
{
	t_data	*win;

	win = malloc(sizeof(t_data));
	win->winvars.mlx = mlx_init();
	win->winvars.mlx_window = mlx_new_window(win->winvars.mlx, 700, 700,
			"fractol");
	win->winvars.img = mlx_new_image(win->winvars.mlx, 700, 700);
	win->winvars.addr = mlx_get_data_addr(win->winvars.img,
			&win->winvars.bits_per_pixel,
			&win->winvars.line_length, &win->winvars.endian);
	execute_all(ac, av, win);
	mlx_put_image_to_window(win->winvars.mlx, win->winvars.mlx_window,
		win->winvars.img, 0, 0);
	mlx_loop(win->winvars.mlx);
	free(win);
	return (0);
}
