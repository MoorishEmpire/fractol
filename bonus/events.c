#include "fractol.h"

void    setup_mlx_events(t_fractal *fractal)
{
    mlx_hook(fractal->window, 17, 0, close_window, fractal);
    mlx_hook(fractal->window, 2, 1, handle_key_press, fractal);
    mlx_mouse_hook(fractal->window, handle_mouse_click, fractal);
}

int     close_window(t_fractal *fractal)
{
    if (fractal->image)
        mlx_destroy_image(fractal->mlx, fractal->image);
    if (fractal->window)
        mlx_destroy_window(fractal->mlx, fractal->window);
    exit(EXIT_SUCCESS);
    return (0);
}

int handle_key_press(int keycode, t_fractal *fractal)
{
    double move_step;

    move_step = MOVE_STEP / fractal->zoom;

    if (keycode == ESC_KEY)
        close_window(fractal);
    else if (keycode == LEFT_KEY)
        fractal->center_x -= move_step;
    else if (keycode == RIGHT_KEY)
        fractal->center_x += move_step;
    else if (keycode == DOWN_KEY)
        fractal->center_y += move_step;
    else if (keycode == UP_KEY)
        fractal->center_y -= move_step;
    else
        return (0);

    render_fractal(fractal);
    return (0);
}

int     handle_mouse_click(int button, int x, int y, t_fractal *fractal)
{
    double  x_tmp = map_x(x, fractal);
    double  y_tmp = map_y(y, fractal);

    if (button == SCROLL_UP || button == SCROLL_DOWN)
    {
        if (button == SCROLL_UP)
            fractal->zoom *= ZOOM_FACTOR;
        else
            fractal->zoom /= ZOOM_FACTOR;
        
        fractal->center_x += x_tmp - map_x(x, fractal);
        fractal->center_y += y_tmp - map_y(y, fractal);
        render_fractal(fractal);
    }
    return (0);
}
