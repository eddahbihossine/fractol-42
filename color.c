// crreate a color function for julia 
#include "fractol.h"

#define BLUE_GOLD 45
int	ft_color2(t_win *data, int *color);

int	ft_color(t_win 	*data)
{
	double	ratio;
	int		color;

	if (data->color == 0)
		color = 0x00955251;
	if (data->color == 1)
		color = 0x00009B77;
	if (data->color == 2)
		color = 0x0000A170;
	if (data->color == 3)
		color = 0x00FFA500;
	ft_color2(data, &color);
	ratio = (double)(data->params.iteration) / (double)data->params.max_iteration ;
	return (ratio * color);
}

int	ft_color2(t_win *data, int *color)
{
	if (data->color == 4)
		*color = 0x009A8B4F;
	if (data->color == 5)
		*color = 0x00944743;
	if (data->color == 6)
		*color = 0x00B9E8EA;
	if (data->color == 7)
		*color = 0x0063A75A;
	if (data->color == 8)
	{
		*color = BLUE_GOLD;
		data->color = 0;
	}
	return (0);
}
