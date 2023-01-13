#include "fractol.h"
int	main(int ac , char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data img;
	int i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx,max_x,max_y, "Hello world!");
	img.img = mlx_new_image(mlx, max_x,max_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	var	win;
	julia(win,img);

mlx_put_image_to_window(mlx,mlx_win,img.img,0,0);
mlx_loop(mlx);
}