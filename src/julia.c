/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:53:41 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/04 20:08:18 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_julia(t_data *data)
{
    data->win_title = "Julia Fractal";
    data->type = JULIA;
	//data->max_iter = ITER;
    data->x_min = -2.0;
    data->x_max = 1.0;
    data->y_min = -1.5;
    data->y_max = 1.5;
    data->zoom_factor = 0.9;
    data->color = COLOR_PSYCHEDELIC;

}