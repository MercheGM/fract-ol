/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/16 21:21:15 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_help(t_data *data)
{
	free(data);
	data = NULL;
	ft_printf("Arguments incorrect: ./fractol [-iter num] fractal_ID\n");
	ft_printf("Please introduce:\n");
	ft_printf("[M/m] to see Mandelbrot\n[J/j] to see Julia\n");
	ft_printf("If you want to change iterations number, use -iter \n");
	exit(EXIT_FAILURE);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	int		err;
	int		pos;
	int		temp;

	pos = 1;
	temp = ITER;
	err = 0;
	if (argc >= 2 && argc <= 6)
	{
		if (!ft_strncmp(argv[1], "-iter", 5) && ((argc >= 4) && (argc <= 6)))
		{
			temp = ft_atoi(argv[2]);
			pos = 3;
		}
		if (temp)
		{
			if (((!ft_strncmp(argv[pos], "M", 1) || !ft_strncmp(argv[pos], "m", 1))))
				init_mandelbrot(data, temp);
			else if (((!ft_strncmp(argv[pos], "J", 1) || \
				!ft_strncmp(argv[pos], "j", 1))))
				init_julia(data, temp);
			else
				err = 1;
		}
		else
			err = 1;
	}
	return (err);
}
