/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:22 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/20 03:38:55 by moorishatlas     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fractal *fractal)
{
	int				x;
	int				y;
	int				pixel_pos;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			fractal->x = x;
			fractal->y = y;
			if (fractal->type == JULIA)
				calculate_julia_point(fractal, x, y);
			else
				calculate_fractal_point(fractal);
			pixel_pos = (y * fractal->line_size) + (x * fractal->bpp / 8);
			*(unsigned int *)(fractal->pixels + pixel_pos) = calculate_color(fractal);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0,
		0);
}

void calculate_julia_point(t_fractal *f, int x, int y)
{
    t_complex z;
    t_complex c;
    double tmp;

    z.real = f->min_real + (double)x / WIDTH * (f->max_real - f->min_real);
    z.imag = f->max_imag - (double)y / HEIGHT * (f->max_imag - f->min_imag);
    c.real = f->julia_real;
    c.imag = f->julia_imag;
    f->iterations = 0;
    while (f->iterations < MAX_ITERATIONS)
    {
        tmp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = tmp;
        if (z.real * z.real + z.imag * z.imag > 4.0)
            break;
        f->iterations++;
    }
}

void	calculate_fractal_point(t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	double		tmp;

	map_coordinates(&z, &c, fractal);
	fractal->iterations = 0;
	while (fractal->iterations < MAX_ITERATIONS)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
		if (z.real * z.real + z.imag * z.imag > 4.0)
			break ;
		fractal->iterations++;
	}
}

void	map_coordinates(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		z->real = 0;
		z->imag = 0;
		c->real = map_x(fractal->x, fractal);
		c->imag = map_y(fractal->y, fractal);
	}
}

double	map_x(int x, t_fractal *fractal)
{
	return ((x - WIDTH / 2.0) / (fractal->zoom * WIDTH)) + fractal->center_x;
}

double	map_y(int y, t_fractal *fractal)
{
	return ((y - HEIGHT / 2.0) / (fractal->zoom * HEIGHT)) + fractal->center_y;
}
