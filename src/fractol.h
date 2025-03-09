/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:15:32 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/09 20:56:13 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/ft_printf.h"
# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>


# define M_PI 3.14159265358979323846
# define WIN_WIDTH 600
# define WIN_HEIGHT 500

# define ITER 70

# define COLOR_BLACK 0x000000FF
# define COLOR_RED 0xFF0000FF
# define COLOR_BLUE 0x00FF00FF
# define COLOR_GREEN 0x0000FFFF

//colors for fractal
# define NEON_PINK 0xFF149300
# define NEON_GREEN 0x00FF00
# define NEON_BLUE 0x00FFFF00
# define NEON_YELLOW 0xBBFF0000
# define NEON_RED 0xFF000000
# define COLOR_WHITE 0xFFFFFFFF

# define MANDELBROT 1
# define JULIA 2

# define PSYCHEDELIC 1
# define DEGRADED 2


typedef struct s_data
{
    char        *win_title;
    int         type;
    mlx_t       *mlx;
    mlx_image_t *img;
    /*double      min_re;
    double      max_re;
    double      min_im;
    double      max_im;*/
    int         max_iter;
    double      x_min;
    double      x_max;
    double      y_min;
    double      y_max;
    double      c_re;
    double      c_im;
    double      zoom_factor;
    uint32_t    color;
    int         transition;
}               t_data;


//inputs.c
int	check_arg(int argc, char *argv[], t_data *data);

//hook.c
void my_scrollhook(double xdelta, double ydelta, void* param);
void my_keyhook(mlx_key_data_t keydata, void* param);
void	hook(void* param);
void	hook_mandelbrot(void* param);

//mandelbrot.c
int mandelbrot(t_data *data);
int print_mandelbrot(t_data	*data);
void init_mandelbrot(t_data *data);

//window.c
int	init_window(t_data	*data);
void closing_window(t_data *data);

//julia.c
void init_julia(t_data *data);

//colors.c
uint32_t get_color(int iterations, t_data	*data);

#endif