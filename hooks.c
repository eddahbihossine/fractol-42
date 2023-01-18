#include "fractol.h"

int mandelbrot_mouse_hook (int keycode ,int x, int y, t_win *window)
{
	static double zoom = 1;
	if(keycode == 4)
	{
		zoom *= 1.7;
		mlx_clear_window(window->mlx,window->mlx_win);
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		mandelbrot(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
	if(keycode == 5 )
	{
		zoom *= 0.7;
		mlx_clear_window(window->mlx,window->mlx_win);
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		mandelbrot(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
	return(0);
}
int julia_mouse_hook (int keycode ,int x, int y, t_win *window)
{
	static double zoom = 1;
	if(keycode == 4)
	{
		zoom *= 1.7;
		
		mlx_clear_window(window->mlx,window->mlx_win);
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		julia(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
	if(keycode == 5)
	{
		zoom *= 0.7;
		
		mlx_clear_window(window->mlx,window->mlx_win);
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		julia(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
	return(0);
}

int bonus_mouse_hook (int keycode ,int x, int y, t_win *window)
{
	static double zoom = 1;
	if(keycode == 4)
	{
		zoom *= 1.5;
		mlx_clear_window(window->mlx,window->mlx_win);
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		bonus_fractal(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
	if(keycode == 5)
	{
		zoom *= 0.5;
		mlx_clear_window(window->mlx,window->mlx_win);
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		bonus_fractal(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
	return(0);
}
int	ft_close(t_win *window)
{
	mlx_destroy_image(window->mlx,window->img);
	mlx_destroy_window(window->mlx,window->mlx_win);
	exit(1);
	return (1);
}
int mandelbrot_key_event(int params,int x, int y, t_win *window)
{
	static double zoom = 0;
	if(params == 2)
	{
		zoom *= 1.5;
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		mandelbrot(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
		if(params == 3)
	{
		zoom *= 0.7;
		
		mlx_destroy_image(window->mlx,window->img);
		window->img = mlx_new_image(window->mlx,max_x,max_y);
		window->addr =mlx_get_data_addr(window->img,&window->bits_per_pixel,&window->line_length,&window->endian);
		mandelbrot(window,zoom);
		mlx_put_image_to_window(window->mlx,window->mlx_win,window->img,0,0);
	}
	return(0);
}