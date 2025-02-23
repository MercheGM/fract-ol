/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:16:57 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/23 19:11:59 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_window(t_data	*data)
{

	data->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!data->mlx)
	{
		ft_printf("ERROR: MLX init failed\n");
		return (EXIT_FAILURE);
	}
	data->img = mlx_new_image(data->mlx, 500, 200);
	if (!data->img)
	{
		ft_printf("ERROR: MLX img failed\n");
		mlx_terminate(data->mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->img, 0, 0))
	{
		ft_printf("ERROR: Failed to put image to window\n");
		mlx_delete_image(data->mlx, data->img);
		mlx_terminate(data->mlx);
		return (EXIT_FAILURE);
	}
	
	return (0);
}
