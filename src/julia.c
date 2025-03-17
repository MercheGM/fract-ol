/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:53:41 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/17 20:08:00 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *data, int iter, double cr, double ci)
{
	data->win_title = "Julia Fractal";
	data->type = JULIA;
	data->x_min = -2.0;
	data->x_max = 2.0;
	data->y_min = -1.5;
	data->y_max = 1.5;
	data->c_re = cr;
	data->c_im = ci;
	data->zoom_factor = 0.9;
	data->color = COLOR_PURPLE;
	data->transition = DEGRADED;
	data->step_size = 1;
	data->max_iter = iter;
}

/*int	calculate_julia(int x, int y, t_data *data)
{
	double	zx;
	double	zy;
	double	temp;
	int		iter;

	zx = data->x_min + ((double)x / WIN_WIDTH) * (data->x_max - data->x_min);
	zy = data->y_min + ((double)y / WIN_HEIGHT) * (data->y_max - data->y_min);
	iter = 0;
	while ((zx * zx + zy * zy < 4) && (iter < data->max_iter))
	{
		temp = zx * zx - zy * zy + data->c_re;
		zy = 2.0 * zx * zy + data->c_im;
		zx = temp;
		iter++;
	}
	return (iter);
}*/

int	calculate_julia(int x, int y, t_data *data)
{
	double	zx;
	double	zy;
	double	temp;
	int		iter;

	zx = data->x_min + ((double)x / WIN_WIDTH) * (data->x_max - data->x_min);
	zy = data->y_min + ((double)y / WIN_HEIGHT) * (data->y_max - data->y_min);
	iter = 0;
	while ((zx * zx + zy * zy < 4) && (iter < data->max_iter))
	{
		temp = zx * zx - zy * zy + data->c_re;
		zy = 2.0 * zx * zy + data->c_im;
		zx = temp;
		iter++;
	}
	return (iter);
}

void	print_julia(t_data *data)
{
	int	x;
	int	y;
	int	iterations;
	int	color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		iterations = 0;
		while (y < WIN_HEIGHT)
		{
			iterations = calculate_julia(x, y, data);
			color = get_color(iterations, data);
			mlx_put_pixel(data->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
