/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:16:57 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/09 19:07:02 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_window(t_data	*data)
{
	printf("ttulo: %s. Tam: %dx%d\n", data->win_title, WIN_WIDTH, WIN_HEIGHT);
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
	return (0);
}

void closing_window(t_data *data)
{
	mlx_terminate(data->mlx);
	mlx_close_window(data->mlx);
	ft_printf("Closing..\n");
	free(data);
	exit(0);
}
