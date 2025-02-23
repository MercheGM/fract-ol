/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:40:42 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/23 19:44:12 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*complex double	mandelbrot(int max, complex double z0, complex double c)
{
	if (max > 0)
		return (mandelbrot(max - 1, cpow(z0, 2) + c, c));
	else if (cabs(z0) > 2)
		return (0);
	else
		return (1);
}*/
void mandelbrot(t_data *data)
{
	ft_printf("Mandelbrot function\n");
	for (int x = 0; x < data->img->width; x++)
		for(int y= 0; y < data->img->height; y++)
			mlx_put_pixel(data->img, x, y, rand() % RAND_MAX);

}