/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:15:32 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/03 21:00:04 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/ft_printf.h"
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct s_data
{
    mlx_t       *mlx;
    mlx_image_t *img;
    double      min_re;
    double      max_re;
    double      min_im;
    double      max_im;
    int         max_iter;
    double      x_min;
    double      x_max;
    double      y_min;
    double      y_max;
    double      c_re;
    double      c_im;
    double      zoom_factor;
    uint32_t    color;
}               t_data;

# define WIN_WIDTH 700
# define WIN_HEIGHT 500

# define COLOR_BLACK 0x000000FF
# define COLOR_PSYCHEDELIC 0x0F0000FF
# define COLOR3 0X0487AF00
# define COLOR4 0X00FF00FF
# define COLOR5
# define COLOR6

//colors for fractal
# define NEON_PINK 0xFF149300
# define NEON_GREEN 0x00FF00
# define NEON_BLUE 0x00FFFF00
# define NEON_YELLOW 0xBBFF00
# define NEON_RED 0xAA0000
# define BLACK 0x000000
# define WHITE 0xFFFFFF

//inputs.c
int	check_arg(int argc, char *argv[]);

//hook.c
void my_scrollhook(double xdelta, double ydelta, void* param);
void my_keyhook(mlx_key_data_t keydata, void* param);
void	hook(void* param);
void	hook_mandelbrot(void* param);
//mandelbrot.c
int mandelbrot(t_data *data);
int print_mandelbrot(t_data	*data);

//window.c
int	init_window(t_data	*data);

#endif