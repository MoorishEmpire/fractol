/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:20:54 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/19 21:43:38 by moorishatlas     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	parse_arguments(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && str_equals("mandelbrot", argv[1]))
	{
		fractal->type = MANDELBROT;
		fractal->name = argv[1];
	}
	else if (argc == 4 && str_equals("julia", argv[1]))
	{
		fractal->julia_real = str_to_double(argv[2]);
		if (fractal->julia_real > 2.0 || fractal->julia_real < -2.0)
			show_error(REAL_OUT_OF_RANGE);
		fractal->julia_imag = str_to_double(argv[3]);
		if (fractal->julia_imag > 1.5 || fractal->julia_imag < -1.5)
			show_error(IMAGINARY_OUT_OF_RANGE);
		fractal->type = JULIA;
		fractal->name = argv[1];
	}
	else if (argc == 2 && str_equals("burningship", argv[1]))
	{
		fractal->type = BURNINGSHIP;
		fractal->name = argv[1];
	}
	else
	{
		show_error(INVALID_ARGUMENTS);
	}
}
double	str_to_double(const char *str)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;

	result = 0.0;
	fraction = 1.0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			fraction *= 10.0;
			result += (str[i++] - '0') / fraction;
		}
	}
	return ((result * sign));
}

bool	str_equals(const char *s1, const char *s2)
{
	int	len;

	if (ft_strlen(s1) >= ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	return ((ft_strncmp(s1, s2, len) == 0));
}
