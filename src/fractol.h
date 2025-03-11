/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:15:32 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/11 17:05:18 by mergarci         ###   ########.fr       */
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
# define NEON_PINK 0xFF149300
# define NEON_GREEN 0x00FF00
# define NEON_BLUE 0x00FFFF00
# define NEON_YELLOW 0xBBFF0000
# define NEON_RED 0xFF000000
# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_PURPLE 0x6C3483FF
# define COLOR_END 0xABEBC6FF
# define COLOR_RED 0xFF0000FF

# define MANDELBROT 1
# define JULIA 2

# define PSYCHEDELIC 1
# define DEGRADED_BLACK 2
# define DEGRADED 3


typedef struct s_data
{
    char        *win_title;
    int         type;
    mlx_t       *mlx;
    mlx_image_t *img;
    /*double      z_re;
    double      z_im;
    double      min_im;
    double      max_im;*/
    int         max_iter;
    double      x_min;  //offsetX para Julia
    double      x_max;
    double      y_min; //offsetY para Julia
    double      y_max;
    double      c_re;
    double      c_im;
    double      zoom_factor;
    uint32_t    color;
    int         transition;
    int         step_size;
}               t_data;


//inputs.c
int	check_arg(int argc, char *argv[], t_data *data);

//hook.c
void my_scrollhook(double xdelta, double ydelta, void* param);
void my_keyhook(mlx_key_data_t keydata, void* param);
void	hook(void* param);
void	hook_mandelbrot(void* param);

//mandelbrot.c
void init_mandelbrot(t_data *data);
int print_mandelbrot(t_data	*data);
int mandelbrot(t_data *data);

//window.c
int	init_window(t_data	*data);
void closing_window(t_data *data);

//julia.c
void init_julia(t_data *data);
int julia_iter(int x, int y, t_data * data);
void print_julia(t_data	*data);
int julia(t_data	*data);

//colors.c
uint32_t get_color(int iterations, t_data	*data);

#endif