/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:17:16 by ael-most          #+#    #+#             */
/*   Updated: 2025/04/15 15:01:12 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft_mandatory/ft_printf/ft_printf.h"
# include "../libft_mandatory/libft.h"
# include "../minilibx_opengl/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITERATIONS 60

# define DEFAULT_ZOOM 0.25
# define ZOOM_FACTOR 1.2
# define MOVE_STEP 0.1

# define ESC_KEY 53
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define UP_KEY 126
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef enum e_fractal_type
{
	MANDELBROT,
	JULIA
}					t_fractal_type;

typedef enum e_error
{
	INVALID_ARGUMENTS,
	REAL_OUT_OF_RANGE,
	IMAGINARY_OUT_OF_RANGE,
	MLX_INIT_FAILURE
}					t_error;

typedef struct s_complex
{
	double			real;
	double			imag;
}					t_complex;

typedef struct s_fractal
{
	t_fractal_type	type;
	char			*name;
	double			julia_real;
	double			julia_imag;
	double			max_real;
	double			min_real;
	double			max_imag;
	double			min_imag;
	double			zoom;
	double			center_x;
	double			center_y;
	int				x;
	int				y;
	int				iterations;
	void			*mlx;
	void			*window;
	void			*image;
	char			*pixels;
	int				bpp;
	int				line_size;
	int				endian;
}					t_fractal;

void				parse_arguments(int argc, char **argv, t_fractal *fractal);
void				initialize_fractal(t_fractal *fractal);
void				render_fractal(t_fractal *fractal);
double				ft_atof(const char *str);
bool				str_equals(const char *s1, const char *s2);
void				calculate_fractal_point(t_fractal *fractal);
void				map_coordinates(t_complex *z, t_complex *c,
						t_fractal *fractal);
double				map_x(int x, t_fractal *fractal);
double				map_y(int y, t_fractal *fractal);
unsigned int		calculate_color(t_fractal *fractal);
void				setup_mlx_events(t_fractal *fractal);
int					close_window(t_fractal *fractal);
int					handle_key_press(int keycode, t_fractal *fractal);
int					handle_mouse_click(int button, int x, int y,
						t_fractal *fractal);
int					handle_mouse_move(int x, int y, t_fractal *fractal);
void				show_error(t_error error);

#endif
