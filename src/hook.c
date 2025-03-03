/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:13:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/03 21:01:50 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data, double zoom_factor, int x, int y)
{
		double center_x;
		double center_y;
		double pointer_x;
		double pointer_y;
		
		pointer_x = data->x_min + (data->x_max - data->x_min) * ((double)x / (WIN_WIDTH - 1));
    	pointer_y = data->y_max - (data->y_max - data->y_min) * ((double)y / (WIN_HEIGHT- 1));
		center_x = (data->x_max + data->x_min) / 2;
		center_y = (data->y_max + data->y_min) / 2;
        data->x_min = pointer_x + zoom_factor * (data->x_min - pointer_x);
        data->x_max = pointer_x + zoom_factor * (data->x_max - pointer_x);
        data->y_min = pointer_y + zoom_factor * (data->y_min - pointer_y);
        data->y_max = pointer_y + zoom_factor * (data->y_max - pointer_y);
}

void	zoom_out(t_data *data, double zoom_factor, int x, int y)
{
		double center_x;
		double center_y;
		double pointer_x;
		double pointer_y;
		
		pointer_x = data->x_min + (data->x_max - data->x_min) * ((double)x / (WIN_WIDTH - 1));
    	pointer_y = data->y_max - (data->y_max - data->y_min) * ((double)y / (WIN_HEIGHT- 1));
		center_x = (data->x_max + data->x_min) / 2;
		center_y = (data->y_max + data->y_min) / 2;
        data->x_min = pointer_x + (data->x_min - pointer_x) / zoom_factor;
        data->x_max = pointer_x + (data->x_max - pointer_x) / zoom_factor;
        data->y_min = pointer_y + (data->y_min - pointer_y) / zoom_factor;
        data->y_max = pointer_y + (data->y_max - pointer_y) / zoom_factor;
}

void check_mouse_pos(int *x, int *y)
{
	if (*x > WIN_WIDTH)
		*x = (int)(WIN_WIDTH/2);
	if (*y > WIN_HEIGHT) 
		*y = (int)(WIN_HEIGHT/2);
}

void my_scrollhook(double xdelta, double ydelta, void* param)
{
	t_data *data;
	int x;
	int y;
	
	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx,&x,&y);
	check_mouse_pos(&x, &y);
	if (ydelta > 0)
		zoom_in(data, data->zoom_factor, x, y);
	else if (ydelta < 0)
		zoom_out(data, data->zoom_factor, x, y);
	print_mandelbrot(data);

}
void changing_colors(t_data *data)
{
	//printf("old %X\n", data->color);
	if (data->color == COLOR_PSYCHEDELIC)
		data->color = COLOR3;
	else if (data->color == COLOR3)
		data->color = NEON_BLUE;
	else if (data->color == NEON_BLUE)
		data->color = NEON_YELLOW;
	else if (data->color == NEON_YELLOW)
		data->color = NEON_RED;
	else if (data->color == NEON_RED)
		data->color = WHITE;
	printf("new %X\n", data->color);
}

void my_keyhook(mlx_key_data_t keydata, void* param)
{
    t_data *data;
	int x, y;
	
    data = param;
	mlx_get_mouse_pos(data->mlx,&x,&y);
	check_mouse_pos(&x, &y);
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		zoom_in(data, data->zoom_factor, x, y);
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		zoom_out(data, data->zoom_factor, x, y);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		changing_colors(data);
	if (keydata.key == MLX_KEY_O && keydata.action == MLX_PRESS)
		puts("Changing colors2!!");
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
    {
        mlx_terminate(data->mlx);
		puts("Cerrando");
        exit(0);
    }
	print_mandelbrot(data);
}
