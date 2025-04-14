#include "fractol.h"

void initialize_fractal(t_fractal *fractal)
{
    fractal->mlx = mlx_init();
    if (!fractal->mlx)
        close_window(fractal);
    
    fractal->window = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->name);
    if (!fractal->window)
        close_window(fractal);
    
    fractal->image = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
    if (!fractal->image)
        close_window(fractal);
    
    fractal->pixels = mlx_get_data_addr(fractal->image, &fractal->bpp, 
                                      &fractal->line_size, &fractal->endian);
    if (!fractal->pixels)
        close_window(fractal);
    
    fractal->max_real = 2.0;
    fractal->min_real = -2.0;
    fractal->max_imag = 1.5;
    fractal->min_imag = -1.5;
    fractal->zoom = DEFAULT_ZOOM;
}
