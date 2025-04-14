#include "fractol.h"

void parse_arguments(int argc, char **argv, t_fractal *fractal)
{
    if (argc == 2 && str_equals("mandelbrot", argv[1]))
    {
        fractal->type = MANDELBROT;
        fractal->name = argv[1];
    }
    else if (argc == 4 && str_equals("julia", argv[1]))
    {
        fractal->julia_real = str_to_double(argv[2]);
        if (fractal->julia_real > 2.0 || fractal->julia_real < -2.0)
            show_error(REAL_OUT_OF_RANGE);
        
        fractal->julia_imag = str_to_double(argv[3]);
        if (fractal->julia_imag > 1.5 || fractal->julia_imag < -1.5)
            show_error(IMAGINARY_OUT_OF_RANGE);
        
        fractal->type = JULIA;
        fractal->name = argv[1];
    }
    else
    {
        show_error(INVALID_ARGUMENTS);
    }
}

double str_to_double(const char *str)
{
    double result = 0.0;
    double fraction = 1.0;
    int sign = 1;
    int i = 0;

    while (isspace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (isdigit(str[i]))
        result = result * 10.0 + (str[i++] - '0');
    if (str[i] == '.')
    {
        i++;
        while (isdigit(str[i]))
        {
            fraction *= 10.0;
            result += (str[i++] - '0') / fraction;
        }
    }

    return result * sign;
}

bool str_equals(const char *s1, const char *s2)
{
    return strcmp(s1, s2) == 0;
}
