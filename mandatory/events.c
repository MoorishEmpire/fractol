/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:01 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/15 17:53:06 by ael-most         ###   ########.fr       */
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

int	handle_mouse_click(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
		fractal->zoom *= ZOOM_FACTOR;
	else if (button == SCROLL_DOWN)
		fractal->zoom /= ZOOM_FACTOR;
	render_fractal(fractal);
	return (0);
}
