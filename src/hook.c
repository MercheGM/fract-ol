/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:13:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/02 20:27:35 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data, double zoom_factor)
{
		double width;
		double height;
		double center_x;
		double center_y;
		
		width = (data->x_max - data->x_min) * zoom_factor;
        height = (data->y_max - data->y_min) * zoom_factor;
        center_x = (data->x_max + data->x_min) / 2;
        center_y = (data->y_max + data->y_min) / 2;
        data->x_min = center_x - width / 2;
        data->x_max = center_x + width / 2;
        data->y_min = center_y - height / 2;
        data->y_max = center_y + height / 2;
}

void	zoom_out(t_data *data, double zoom_factor)
{
		double width;
		double height;
		double center_x;
		double center_y;
		
		width = (data->x_max - data->x_min) / zoom_factor;
		height = (data->y_max - data->y_min) / zoom_factor;
		center_x = (data->x_max + data->x_min) / 2;
		center_y = (data->y_max + data->y_min) / 2;
        data->x_min = center_x - width / 2;
        data->x_max = center_x + width / 2;
        data->y_min = center_y - height / 2;
        data->y_max = center_y + height / 2;
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_data *data;
	int x;
	int y;
	data = (t_data *)param;
	// Simple up or down detection.
	//void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);
	mlx_get_mouse_pos(data->mlx,&x,&y); //___Aquí conseguimos la posición de X,Y a la hora de hacer scroll
	printf("pos x: %d, y: %d\n", x,y);
	if (ydelta > 0)
	{
		printf("up! %f, %f\n",xdelta, ydelta);
		zoom_in(data, data->zoom_factor);
	}
	else if (ydelta < 0)
	{
		printf("down! %f, %f\n",xdelta, ydelta);
		zoom_out(data, data->zoom_factor);
	}
	print_mandelbrot(data);

}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
    t_data *data;

    data = param;
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
	{
		puts("ZZZZWorld");
		//mlx_delete_image(data->mlx, data->img);
		//print_mandelbrot(data);
	}
	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_PRESS)
		mlx_put_pixel(data->img, WIDTH / 2, HEIGHT / 2, 0xFF0000FF);

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
