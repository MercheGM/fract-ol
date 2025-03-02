/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:15:32 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/02 20:26:21 by mergarci         ###   ########.fr       */
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
    double      minRe;
    double      maxRe;
    double      minIm;
    double      maxIm;
    int         maxIter;
    double      x_min;
    double      x_max;
    double      y_min;
    double      y_max;
    double      c_re;
    double      c_im;
    double      zoom_factor;
}               t_data;

# define WIDTH 700
# define HEIGHT 500

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