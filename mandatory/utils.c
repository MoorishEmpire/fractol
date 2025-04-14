#include "fractol.h"

unsigned int calculate_color(t_fractal *fractal)
{
    if (fractal->iterations == MAX_ITERATIONS)
        return 0x000000;

    int r = (fractal->iterations * 5) % 256;
    int g = (fractal->iterations * 10) % 256;
    int b = (fractal->iterations * 15) % 256;

    return (r << 16) | (g << 8) | b;
}

void show_error(t_error error)
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
