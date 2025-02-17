/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:14 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/15 19:59:31 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char *argv[])
{
	
	check_arg(argc, argv);
	if (ft_atoi(argv[1]) == 1)
		ft_printf("We'll see Julia fractal\n");
	else if (ft_atoi(argv[1]) == 2)
		ft_printf("We'll see Mandelbrot fractal\n");
	
	return (0);

}