/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/17 21:01:14 by mergarci         ###   ########.fr       */
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

bool check_c(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if ((ft_isdigit(str[i])) || (str[i] == '-') || (str[i] == '.'))
			i++;
		else
			return (false);
	}
	return (true);	
}

int check_init_fractol(int argc, char *argv[], t_data *data, int pos, int temp)
{
	int err;
	double cr;
	double ci;
	int num;
	
	cr = 10;
	ci = 10;
	err = 0;
	//printf("cr: %s ci: %s\n", argv[pos + 1], argv[pos + 2]);
	if ((!ft_strncmp(argv[pos], "M", 1) || !ft_strncmp(argv[pos], "m", 1)) && (argc == pos + 1))
		init_mandelbrot(data, temp);
	else if ((!ft_strncmp(argv[pos], "J", 1) || !ft_strncmp(argv[pos], "j", 1)) && (argc == pos + 1))
		init_julia(data, temp, 0.7, 0.230);
	else if ((!ft_strncmp(argv[pos], "J3", 2) || !ft_strncmp(argv[pos], "j3", 2)) && (argc == pos + 3))
	{
		if (check_c(argv[pos + 1]))
			cr = ft_atof(argv[pos + 1]);
		if (check_c(argv[pos + 1]))
			ci = ft_atof(argv[pos + 2]);
		if (((cr >= -1) && (cr <= 1)) &&  ((ci >= -1) && (ci <= 1)))
		{
			//printf("cr: %f ci: %f\n", cr, ci);
			init_julia(data, temp, cr, ci);
		}
		else
			err = 1;
		//check valor double
		//init_julia3(data, temp, 0.7, 0.230);
	}
	else
		err = 1;
	return (err);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	int		err;
	int		pos;
	int		temp;

	pos = 2;
	temp = ITER;
	err = 0;
	if (argc >= 3 && argc <= 7)
	{
		if (!ft_strncmp(argv[1], "-i", 2) && ((argc >= 5) && (argc <= 7)))
		{
			temp = ft_atoi(argv[2]);
			pos = 4;
		}
		else
			err = 1;
		if (!err && (!ft_strncmp(argv[1], "-f", 2) || !ft_strncmp(argv[3], "-f", 2)) \
			&& ((argc >= 3) && (argc <= 7)))
			err = check_init_fractol(argc, argv, data, pos, temp);
		else
			err = 1;
	}
	else
		err = 1;
	return (err);
}
