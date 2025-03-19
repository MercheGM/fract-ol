/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:40:42 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/19 21:09:06 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_data *data, int iter)
{
	data->win_title = "Mandelbrot Fractal";
	data->type = MANDELBROT;
	data->x_min = -2.0;
	data->x_max = 1.0;
	data->y_min = -1.5;
	data->y_max = 1.5;
	data->zoom_factor = 0.9;
	data->color = COLOR_PURPLE;
	data->transition = DEGRADED;
	data->step_size = 1;
	data->max_iter = iter;
}

int	calculate_mandelbrot(int x, int y, t_data	*data)
{
	double	z_re;
	double	z_im;
	int		iter;
	double	temp;

	z_re = 0;
	z_im = 0;
	iter = 0;
	data->c_re = data->x_min + ((double)x / WIN_WIDTH) * \
				(data->x_max - data->x_min);
	data->c_im = data->y_min + ((double)y / WIN_HEIGHT) * \
				(data->y_max - data->y_min);
	while ((z_re * z_re + z_im * z_im <= 4) && (iter < data->max_iter))
	{
		temp = z_re * z_re - z_im * z_im + data->c_re;
		z_im = 2 * z_re * z_im + data->c_im;
		z_re = temp;
		iter++;
	}
	return (iter);
}
