// crreate a color function for julia 
#include "fractol.h"
void params_to_rgb(double h, double s, double v, int *r, int *g, int *b)
{
    int i;
    double f, p, q, t;
    h /= 60;
    i = (int)h;
    f = h - i;
    p = v * (1 - s);
    q = v * (1 - s * f);
    t = v * (1 - s * (1 - f));
    while (i == 0)
    {
        *r = v * 255;
        *g = t * 255;
        *b = p * 255;
        break;
    }
    while (i == 1)
    {
        *r = q * 255;
        *g = v * 255;
        *b = p * 255;
        break;
    }
    while (i == 2)
    {
        *r = p * 255;
        *g = v * 255;
        *b = t * 255;
        break;
    }
    while (i == 3)
    {
        *r = p * 255;
        *g = q * 255;
        *b = v * 255;
        break;
    }
    while (i == 4)
    {
        *r = t * 255;
        *g = p * 255;
        *b = v * 255;
        break;
    }
    while (i == 5)
    {
        *r = v * 255;
        *g = p * 255;
        *b = q * 255;
        break;
    }
}
void get_color(t_win *hello, double iteration, double max_iteration, int x, int y)
{
    double color = iteration / max_iteration;
    int r, g, b;
    params_to_rgb(color, 2, 2, &r, &g, &b);
    my_mlx_pixel_put(hello, x, y, (r << 32) | (g << 8)* b );
}

