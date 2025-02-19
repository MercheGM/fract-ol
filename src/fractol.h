/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:15:32 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/18 20:08:29 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/ft_printf.h"
#include<math.h>

typedef struct s_data
{
    mlx_t       *mlx;
    mlx_image_t *img;
    double      minRe;
    double      maxRe;
    double      minIm;
    double      maxIm;
    int         maxIter;
}               t_data;

# define WIDTH 700
# define HEIGHT 500

//inputs.c
int	check_arg(int argc, char *argv[]);

#endif