/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/19 22:03:52 by mergarci         ###   ########.fr       */
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

int	check_init_fractol(int ac, char *argv[], t_data *data, int *i)
{
	int		err;
	int		num;

	err = 0;
	if (!i[2] && (!ft_strncmp(argv[1], "-f", 2) || \
					!ft_strncmp(argv[3], "-f", 2)) && ((ac >= 3) && (ac <= 7)))
	{
		if ((!ft_strncmp(argv[i[0]], "M", 2) || \
				!ft_strncmp(argv[i[0]], "m", 2)) && (ac == i[0] + 1))
			init_mandelbrot(data, i[1]);
		else if ((!ft_strncmp(argv[i[0]], "J0", 3) || \
				!ft_strncmp(argv[i[0]], "j0", 3)) && (ac == i[0] + 1))
			init_julia(data, i[1], 0.7, 0.230);
		else if ((!ft_strncmp(argv[i[0]], "J3", 3) || \
					!ft_strncmp(argv[i[0]], "j3", 3)) && (ac == i[0] + 3))
			err = check_julia_inputs(argv, data, i, JULIATHREE);
		else if ((!ft_strncmp(argv[i[0]], "J4", 3) || \
					!ft_strncmp(argv[i[0]], "j4", 3)) && (ac == i[0] + 3))
			err = check_julia_inputs(argv, data, i, JULIACOSH);
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
		if (!ft_strncmp(argv[1], "-i", 2) && ((argc >= 5) && (argc <= 7)))
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
