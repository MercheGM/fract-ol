/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:13:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/16 19:48:14 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_mouse_pos(int *x, int *y)
{
	if (*x > WIN_WIDTH)
		*x = (int)(WIN_WIDTH / 2);
	if (*y > WIN_HEIGHT)
		*y = (int)(WIN_HEIGHT / 2);
}

void	changing_colors(t_data *data)
{
	if (data->color == COLOR_PURPLE)
		data->color = NEON_PINK;
	else if (data->color == NEON_PINK)
		data->color = NEON_BLUE;
	else if (data->color == NEON_BLUE)
		data->color = COLOR_RED;
	else if (data->color == COLOR_RED)
		data->color = COLOR_PURPLE;
}

void	changing_transition(t_data *data)
{
	if (data->transition == PSYCHEDELIC)
		data->transition = DEGRADED;
	else if (data->transition == DEGRADED)
		data->transition = DEGRADED_BLACK;
	else if (data->transition == DEGRADED_BLACK)
		data->transition = PSYCHEDELIC;
}

void	move(mlx_key_data_t key, t_data *data)
{
	double	step;

	step = 0.1;
	if (key.key == MLX_KEY_LEFT)
	{
		data->x_min -= (data->x_max - data->x_min) * step;
		data->x_max -= (data->y_max - data->y_min) * step;
	}
	else if (key.key == MLX_KEY_RIGHT)
	{
		data->x_min += (data->x_max - data->x_min) * step;
		data->x_max += (data->x_max - data->x_min) * step;
	}
	else if (key.key == MLX_KEY_DOWN)
	{
		data->y_min += (data->y_max - data->y_min) * step;
		data->y_max += (data->y_max - data->y_min) * step;
	}
	else if (key.key == MLX_KEY_UP)
	{
		data->y_min -= (data->y_max - data->y_min) * step;
		data->y_max -= (data->y_max - data->y_min) * step;
	}
}

void	key_events(mlx_key_data_t key, void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	check_mouse_pos(&x, &y);
	if (key.key == MLX_KEY_Z && key.action == MLX_PRESS)
		zoom_in(data, data->zoom_factor, 0, 0);
	if (key.key == MLX_KEY_X && key.action == MLX_PRESS)
		zoom_out(data, data->zoom_factor, 0, 0);
	if (key.key == MLX_KEY_SPACE && key.action == MLX_PRESS)
		changing_transition(data);
	if (key.key == MLX_KEY_C && key.action == MLX_PRESS)
		changing_colors(data);
	if ((key.key == MLX_KEY_LEFT || key.key == MLX_KEY_RIGHT || \
		key.key == MLX_KEY_UP || key.key == MLX_KEY_DOWN) && \
		key.action == MLX_PRESS)
		move(key, data);
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		closing_window(data);
	print_fractal(data);
}
