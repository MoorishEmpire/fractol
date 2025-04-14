#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractal fractal;

    parse_arguments(argc, argv, &fractal);
    initialize_fractal(&fractal);
    setup_mlx_events(&fractal);
    render_fractal(&fractal);
    mlx_loop(fractal.mlx);
    return 0;
}
