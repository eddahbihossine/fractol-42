/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heddahbi <heddahbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:57:46 by heddahbi          #+#    #+#             */
/*   Updated: 2023/01/25 22:16:38 by heddahbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	is_space(char c);
static int	handle_sign(char **str);
double		floathandler(char *str);
int			is_double(char *str);
void		draw_julia(t_data *data);

int	is_double(char *str)
{
	while (str && is_space(*str))
	str++;
	while (str && (*str == '-' || *str == '+'))
	str++;
	while (str && isdigit(*str))
	str++;
	if (str && *str == '.')
	str++;
	else
		return (0);
	while (str && isdigit(*str))
	str++;
	if (str && *str != 0)
		return (0);
	return (1);
}

double	floathandler(char *str)
{
	double	res;
	int		dec;
	int		sign;

	res = 0;
	dec = 1;
	while (str && is_space(*str))
	str++;
	sign = handle_sign(&str);
	while (str && *str >= '0' && *str <= '9')
	{
	res = res * 10 + (*str - '0');
	str++;
	}
	if (str && *str == '.')
	str++;
	while (str && *str >= '0' && *str <= '9')
	{
	res = res * 10 + (*str++ - '0');
	dec *= 10;
	}
	return ((res * sign) / dec);
}

static int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

static int	handle_sign(char **str)
{
	int	sign;

	sign = 1;
	while (str && (**str == '-' || **str == '+' || is_space(**str)))
	{
		if (**str == '-')
		sign *= -1;
	(*str)++;
	}
	return (sign);
}

void	parse_julia(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (strcmp(argv[i], "-cx") == 0)
		{
			data->prms.cx = floathandler(argv[++i]);
		}
		else if (strcmp(argv[i], "-cy") == 0)
		{
			data->prms.cy = floathandler(argv[++i]);
		}
		i++;
	}
	draw_julia(data);
}
