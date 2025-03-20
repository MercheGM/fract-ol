/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:01:58 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/20 18:18:35 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_degraded_black(int iterations, t_data *data)
{
	int	r;
	int	g;
	int	b;
	int	a;

	r = get_r(data->color);
	g = get_g(data->color);
	b = get_b(data->color);
	a = get_a(data->color);
	return (get_rgba(iterations * (get_r(data->color) / ITER), \
						iterations * (get_g(data->color) / ITER), \
						iterations * (get_b(data->color) / ITER), a));
}

uint32_t	interpolation_step(uint32_t color, double t)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = (uint8_t)((1 - t) * get_r(color) + t * get_r(COLOR_END));
	g = (uint8_t)((1 - t) * get_g(color) + t * get_g(COLOR_END));
	b = (uint8_t)((1 - t) * get_b(color) + t * get_b(COLOR_END));
	a = (uint8_t)((1 - t) * get_a(color) + t * get_a(COLOR_END));
	return (get_rgba(r, g, b, a));
}

uint32_t	get_degraded_steps(t_data *data, int iter, int steps)
{
	int			step;
	double		t;
	uint32_t	color;

	step = (int)(iter / data->step_size);
	t = (double) step / steps;
	color = interpolation_step(data->color, t);
	return (color);
}

uint32_t	get_color(int iterations, t_data *data)
{
	uint32_t	color;

	color = get_rgba(0, 0, 0, 0);
	if (iterations == data->max_iter)
		color = COLOR_BLACK;
	else
	{
		if (data->transition == DEGRADED_BLACK)
			color = get_degraded_black(iterations, data);
		else if (data->transition == PSYCHEDELIC)
			color = iterations * (data->color / ITER);
		else if (data->transition == DEGRADED)
			color = get_degraded_steps(data, iterations, 20);
	}
	return (color);
}
