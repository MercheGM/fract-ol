/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/15 19:56:08 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_arg(int argc, char *argv[])
{
	if ((argc == 2) && (ft_atoi(argv[1]) == 1 || ft_atoi(argv[1]) == 2))
		return (0);
	ft_printf("Argument incorrect: ./fractol fractal_number\n");
	ft_printf("Please introduce:\n[1] to see Julia\n[2] to see Mandelbrot\n");
	exit;
}