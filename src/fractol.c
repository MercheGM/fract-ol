/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:53:56 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/19 21:10:40 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_fractal(int x, int y, t_data	*data)
{
	int	iter;

	iter = -1;
	if (data->type == MANDELBROT)
		iter = calculate_mandelbrot(x, y, data);
	else if (data-> type == JULIA)
		iter = calculate_julia(x, y, data);
	else if (data->type == JULIATHREE)
		iter = calculate_julia_three(x, y, data);
	else if (data->type == JULIACOSH)
		iter = calculate_julia_expz(x, y, data);
	else
		return (iter);
	return (iter);
}

int	print_fractal(t_data *data)
{
	int	x;
	int	y;
	int	iterations;
	int	color;

	iterations = 0;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			iterations = calculate_fractal(x, y, data);
			color = get_color(iterations, data);
			mlx_put_pixel(data->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	return (EXIT_SUCCESS);
}
