/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:59:13 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/18 21:35:25 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_data *data, double zoom_factor, int x, int y)
{
	double	pointer_x;
	double	pointer_y;

	pointer_x = 0;
	pointer_y = 0;
	if ((x != 0) && (y != 0))
	{
		pointer_x = data->x_min + (data->x_max - data->x_min) * \
					((double)x / (WIN_WIDTH - 1));
		pointer_y = data->y_min + (data->y_max - data->y_min) * \
					((double)y / (WIN_HEIGHT - 1));
	}
	data->x_min = pointer_x + zoom_factor * (data->x_min - pointer_x);
	data->x_max = pointer_x + zoom_factor * (data->x_max - pointer_x);
	data->y_min = pointer_y + zoom_factor * (data->y_min - pointer_y);
	data->y_max = pointer_y + zoom_factor * (data->y_max - pointer_y);
	data->max_iter += 2;
}

void	zoom_out(t_data *data, double zoom_factor, int x, int y)
{
	double	pointer_x;
	double	pointer_y;

	pointer_x = 0;
	pointer_y = 0;
	if ((x != 0) && (y != 0))
	{
		pointer_x = data->x_min + (data->x_max - data->x_min) * \
					((double)x / (WIN_WIDTH - 1));
		pointer_y = data->y_max - (data->y_max - data->y_min) * \
					((double)y / (WIN_HEIGHT - 1));
	}
	data->x_min = pointer_x + (data->x_min - pointer_x) / zoom_factor;
	data->x_max = pointer_x + (data->x_max - pointer_x) / zoom_factor;
	data->y_min = pointer_y + (data->y_min - pointer_y) / zoom_factor;
	data->y_max = pointer_y + (data->y_max - pointer_y) / zoom_factor;
	data->max_iter -= 2;
}

void	scroll_zoom(double xdelta, double ydelta, void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = (t_data *)param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	check_mouse_pos(&x, &y);
	if (ydelta > 0)
		zoom_in(data, data->zoom_factor, x, y);
	else if (ydelta < 0)
		zoom_out(data, data->zoom_factor, x, y);
	print_fractal(data);
}
