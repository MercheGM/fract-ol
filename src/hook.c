/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:13:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/23 20:59:18 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	// Simple up or down detection.
	if (ydelta > 0)
		ft_printf("up! %d, %d\n",xdelta, ydelta);
	else if (ydelta < 0)
		ft_printf("down! %d, %d\n",xdelta, ydelta);
	
	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
    t_data *data;

    data = param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		mlx_put_pixel(data->img, 0, 1, 0xFF0000FF);

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_terminate(data->mlx);
		puts("Cerrando");
        exit(0);
    }
}
void	hook(void* param)
{
    t_data *data;

    data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_P))
		mlx_delete_image(data->mlx, data->img);
	for (int x = 0; x < data->img->width; x++)
		for(int y= 0; y < data->img->height; y++)
			mlx_put_pixel(data->img, x, y, rand() % RAND_MAX);
}

void	hook_mandelbrot(void* param)
{
    t_data *data;

    data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
		mlx_delete_image(data->mlx, data->img);
	for (int x = 0; x < data->img->width; x++)
		for(int y= 0; y < data->img->height; y++)
			mlx_put_pixel(data->img, x, y, rand() % RAND_MAX);
}