/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/20 16:35:02 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_help(t_data *data)
{
	free(data);
	data = NULL;
	ft_printf("Arguments incorrect: ./fractol [-i <num>] -f <fractal_ID>\n");
	ft_printf("-> fractal_ID:\n");
	ft_printf("\tj\tMandelbrot set\n\tj0\tJulia set\n");
	ft_printf("\tj3\tJulia set with function: f(z):z^3+c\n");
	ft_printf("\tj4\tJulia set with function: f(z) = exp(z^3) - 0.59\n");
	ft_printf("-> [-i <num>]\tOptional. Change iterations number\n");
	exit(EXIT_FAILURE);
}

bool	check_c(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_isdigit(str[i])) || (str[i] == '-') || (str[i] == '.'))
			i++;
		else
			return (false);
	}
	return (true);
}

int	check_julia_inputs(char *argv[], t_data *data, int *info, int type)
{
	int		err;
	double	cr;
	double	ci;

	err = 0;
	cr = 10;
	ci = 10;
	if (check_c(argv[info[0] + 1]))
		cr = ft_atof(argv[info[0] + 1]);
	if (check_c(argv[info[0] + 1]))
		ci = ft_atof(argv[info[0] + 2]);
	if (((cr >= -1) && (cr <= 1)) && ((ci >= -1) && (ci <= 1)))
	{
		init_julia(data, info[1], cr, ci);
		if (type == JULIATHREE)
			data->type = JULIATHREE;
		else if (type == JULIACOSH)
			data->type = JULIACOSH;
	}
	else
		err = 1;
	return (err);
}

int	check_init_fractol(int argc, char *argv[], t_data *data, int *info)
{
	int		err;
	int		num;

	err = 0;
	if (!info[2] && (argc == 3 || argc == 5))
	{
		if (!ft_strncmp(argv[info[0]], "m", 2))
			init_mandelbrot(data, info[1]);
		else if (!ft_strncmp(argv[info[0]], "j0", 3))
			init_julia(data, info[1], -0.70176, -0.3842);
		else
			err = 1;
	}
	else if (!info[2] && (argc == 5 || argc == 7))
	{
		if (!ft_strncmp(argv[info[0]], "j3", 3))
			err = check_julia_inputs(argv, data, info, JULIATHREE);
		else if (!ft_strncmp(argv[info[0]], "j4", 3))
			err = check_julia_inputs(argv, data, info, JULIACOSH);
		else
			err = 1;
	}
	else
		err = 1;
	return (err);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	int		err;
	int		*info;

	info = (int *)ft_calloc(4, sizeof(int));
	if (!info)
		return (EXIT_FAILURE);
	info[0] = 2;
	info[1] = ITER;
	info[2] = 0;
	if (argc >= 3 && argc <= 7)
	{
		if (!ft_strncmp(argv[1], "-i", 2) && (argc == 5 || argc == 7))
		{
			info[0] = 4;
			info[1] = ft_atoi(argv[2]);
		}
		info[2] = check_init_fractol(argc, argv, data, info);
	}
	else
		info[2] = 1;
	err = info[2];
	return (free_mem(info), err);
}
