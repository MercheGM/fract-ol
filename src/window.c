/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:16:57 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/16 21:00:07 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_window(t_data	*data)
{
	data->mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, data->win_title, true);
	if (!data->mlx)
	{
		ft_printf("ERROR: MLX init failed\n");
		return (EXIT_FAILURE);
	}
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img)
	{
		ft_printf("ERROR: MLX img failed\n");
		mlx_terminate(data->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	closing_window(t_data *data)
{
	mlx_terminate(data->mlx);
	mlx_close_window(data->mlx);
	ft_printf("Closing..\n");
	free(data);
	exit(0);
}

int	print_fractal(t_data *data)
{
	if (data->type == MANDELBROT)
		print_mandelbrot(data);
	else
		print_julia(data);
	return (EXIT_SUCCESS);
}

int	fractal(t_data	*data)
{
	print_fractal(data);
	mlx_scroll_hook(data->mlx, &scroll_zoom, data);
	mlx_key_hook(data->mlx, key_events, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
