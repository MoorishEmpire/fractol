/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:22 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/15 12:21:24 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void render_fractal(t_fractal *fractal)
{
    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            fractal->x = x;
            fractal->y = y;
            calculate_fractal_point(fractal);
            
            int pixel_pos = (y * fractal->line_size) + (x * fractal->bpp / 8);
            unsigned int color = calculate_color(fractal);
            *(unsigned int *)(fractal->pixels + pixel_pos) = color;
        }
    }
    mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
}

void calculate_fractal_point(t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    double tmp;

    map_coordinates(&z, &c, fractal);
    fractal->iterations = 0;
    
    while (fractal->iterations < MAX_ITERATIONS)
    {
        tmp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = tmp;
        
        if (z.real * z.real + z.imag * z.imag > 4.0)
            break;
            
        fractal->iterations++;
    }
}

void map_coordinates(t_complex *z, t_complex *c, t_fractal *fractal)
{
    if (fractal->type == MANDELBROT)
    {
        z->real = 0;
        z->imag = 0;
        c->real = map_x(fractal->x, fractal);
        c->imag = map_y(fractal->y, fractal);
    }
    else
    {
        z->real = map_x(fractal->x, fractal);
        z->imag = map_y(fractal->y, fractal);
        c->real = fractal->julia_real;
        c->imag = fractal->julia_imag;
    }
}

double map_x(int x, t_fractal *fractal)
{
    return (x - WIDTH / 2.0) / (fractal->zoom * WIDTH);
}

double map_y(int y, t_fractal *fractal)
{
    return (y - HEIGHT / 2.0) / (fractal->zoom * HEIGHT);
}
