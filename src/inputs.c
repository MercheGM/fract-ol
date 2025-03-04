/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/04 21:09:05 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void print_help()
{
	ft_printf("Argument incorrect: ./fractol fractal_number\n");
	ft_printf("Please introduce:\n[M1] to see Mandelbrot\n[J1] to see Julia\n");
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	int err;
	char *str;
	int temp;
	
	printf("tam: %dx%d\n", WIN_WIDTH, WIN_HEIGHT);
	temp = ITER;
	err = 0;
	if (argc >= 2 )
	{
		if (!ft_strncmp(argv[1],"-iter", 5))
			temp = ft_atoi(argv[2]);
		else if (((!ft_strncmp(argv[1],"M", 1) || !ft_strncmp(argv[1],"m", 1)) || \
			((!ft_strncmp(argv[3],"M", 1) || !ft_strncmp(argv[3],"m", 1)))))
			init_mandelbrot(data);
		else if (((!ft_strncmp(argv[1],"J", 1) || !ft_strncmp(argv[1],"j", 1)) || \
			((!ft_strncmp(argv[3],"J", 1) || !ft_strncmp(argv[3],"j", 1)))))
			init_julia(data);
		
		data->max_iter = temp;
		return (err);
	}
	print_help();
	exit(1);
}
