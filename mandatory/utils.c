/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:28 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/15 17:48:49 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	calculate_color(t_fractal *fractal)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (fractal->iterations == MAX_ITERATIONS)
		return (0x000000);
	t = (double)fractal->iterations / MAX_ITERATIONS;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

void	show_error(t_error error)
{
	if (error == REAL_OUT_OF_RANGE)
		ft_printf("Real part value must be between -2.0 and 2.0");
	else if (error == IMAGINARY_OUT_OF_RANGE)
		ft_printf("Imaginary part value must be between -1.5 and 1.5");
	else
	{
		ft_printf("-----------------------------------------------\n");
		ft_printf("-                                             -\n");
		ft_printf("-    Allowed arguments are :                  -\n");
		ft_printf("-                                             -\n");
		ft_printf("-         ./fractol mandelbrot               -\n");
		ft_printf("-         ./fractol julia <real> <imaginary>  -\n");
		ft_printf("-                                             -\n");
		ft_printf("-----------------------------------------------\n");
	}
	exit(EXIT_FAILURE);
}
