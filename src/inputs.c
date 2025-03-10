/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/10 20:13:11 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void print_help(t_data *data)
{
	free(data);
	data = NULL;
	ft_printf("Arguments incorrect: ./fractol [-iter num] fractal_ID\n");
	ft_printf("Please introduce:\n[M/m] to see Mandelbrot\n[J/j] to see Julia\n");
	ft_printf("If you want to change iterations number, use -iter\n");
	exit(1);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	int err;
	char *str;
	int temp;
	
	temp = ITER;
	err = 0;
	if (argc >= 2 && argc <= 6)
	{
		if (!ft_strncmp(argv[1],"-iter", 5) && ((argc >= 4) && (argc <= 6)))
			temp = ft_atoi(argv[2]);
		if (((!ft_strncmp(argv[1],"M", 1) || !ft_strncmp(argv[1],"m", 1)) || \
			((!ft_strncmp(argv[3],"M", 1) || !ft_strncmp(argv[3],"m", 1)))))
			init_mandelbrot(data);
		else if (((!ft_strncmp(argv[1],"J", 1) || !ft_strncmp(argv[1],"j", 1)) || \
			((!ft_strncmp(argv[3],"J", 1) || !ft_strncmp(argv[3],"j", 1)))))
		{
			
			init_julia(data);
		}
		else
			print_help(data);
		data->max_iter = temp;
		return (err);
	}
	print_help(data);
	return (err);
}
