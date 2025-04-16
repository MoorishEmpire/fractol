/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:21:15 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/15 12:21:19 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	parse_arguments(argc, argv, &fractal);
	initialize_fractal(&fractal);
	setup_mlx_events(&fractal);
	render_fractal(&fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
