/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:01 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/20 04:33:08 by moorishatlas     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_mlx_events(t_fractal *fractal)
{
	mlx_hook(fractal->window, 17, 0, close_window, fractal);
	mlx_hook(fractal->window, 2, 1, handle_key_press, fractal);
	mlx_mouse_hook(fractal->window, handle_mouse_click, fractal);
}

int	close_window(t_fractal *fractal)
{
	if (fractal->image)
		mlx_destroy_image(fractal->mlx, fractal->image);
	if (fractal->window)
		mlx_destroy_window(fractal->mlx, fractal->window);
	exit(EXIT_SUCCESS);
	return (0);
}

int	handle_key_press(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
		close_window(fractal);
	return (0);
}

static void	center_zoom(t_fractal *f, double zoom_factor)
{
	double	center_real;
	double	center_imag;

	center_real = (f->max_real + f->min_real) / 2.0;
	center_imag = (f->max_imag + f->min_imag) / 2.0;
	f->min_real = center_real + (f->min_real - center_real) / zoom_factor;
	f->max_real = center_real + (f->max_real - center_real) / zoom_factor;
	f->min_imag = center_imag + (f->min_imag - center_imag) / zoom_factor;
	f->max_imag = center_imag + (f->max_imag - center_imag) / zoom_factor;
	render_fractal(f);
}

int	handle_mouse_click(int button, int x, int y, t_fractal *f)
{
	double	zoom_factor;

	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		zoom_factor = ZOOM_FACTOR;
	else if (button == SCROLL_DOWN)
		zoom_factor = 1.0 / ZOOM_FACTOR;
	else
		return (0);
	if (f->type == JULIA)
		center_zoom(f, zoom_factor);
	else
		f->zoom *= zoom_factor;
	render_fractal(f);
	return (0);
}
