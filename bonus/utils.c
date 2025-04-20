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
	if (fractal->type == BURNINGSHIP)
	{
		r = (int)(255 * pow(t, 0.3));
		g = (int)(140 * pow(t, 0.7));
		b = (int)(30 * pow(t, 2.0));
	}
	else
	{
		r = (int)(9 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	return ((r << 16) | (g << 8) | b);
}

void    show_error(t_error error)
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
        ft_printf("-         ./fractol burningship               -\n");
        ft_printf("-                                             -\n");
        ft_printf("-----------------------------------------------\n");
    }
    exit(EXIT_FAILURE);
}
