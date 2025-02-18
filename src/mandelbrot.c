/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:40:42 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/18 17:24:07 by mergarci         ###   ########.fr       */
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
int mandelbrot(void)
{
	int i;

	i = 10;
	ft_printf("Mandelbrot: %d\n", i);
	return (i);
}