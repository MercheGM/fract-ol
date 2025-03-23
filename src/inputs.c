/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:34:16 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/23 17:01:13 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	print_help(t_data *data)
{
	free_mem(data);
	ft_printf("ERROR: Arguments incorrect!! Please, follow below structure:\n");
	ft_printf("./fractol -f <fractal_ID> <cr> <ci>\n");
	ft_printf("\tm\tMandelbrot set\n");
	ft_printf("\tj0\tJulia set with function: f(z) = z^2+c (*)\n");
	ft_printf("\tj3\tJulia set with function: f(z) = z^3+c (*)\n");
	ft_printf("\tj4\tJulia set with function: f(z) = exp(z^3) - 0.59\n");
	ft_printf("\t\t(*) j0 and j3 need <cr> and <ci> inputs\n");
	ft_printf("\t<cr>\tReal part of a complex number\n");
	ft_printf("\t<ci>\tImaginary part of a complex number\n");
	ft_printf("Enjoy my fractol project! =)\n");
	exit(EXIT_FAILURE);
}

bool	check_c(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-') && i == 0) 
			i++;
		else if ((ft_isdigit(str[i])) || (str[i] == '.'))
			i++;
		else
			return (false);
	}
	return (true);
}

int	check_julia_inputs(char *argv[], t_data *data, int type)
{
	int		err;
	double	cr;
	double	ci;

	err = 0;
	cr = 10;
	ci = 10;
	if (check_c(argv[3]))
		cr = ft_atof(argv[3]);
	if (check_c(argv[4]))
		ci = ft_atof(argv[4]);
	if (((cr >= -1) && (cr <= 1)) && ((ci >= -1) && (ci <= 1)))
	{
		init_julia(data, cr, ci);
		if (type == JULIATHREE)
			data->type = JULIATHREE;
		else if (type == JULIA)
			data->type = JULIA;
	}
	else
		err = 1;
	return (err);
}

int	check_init_fractol(int argc, char *argv[], t_data *data)
{
	int		err;

	err = 0;
	if (argc == 3)
	{
		if (!ft_strncmp(argv[2], "m", 2))
			init_mandelbrot(data);
		else if (!ft_strncmp(argv[2], "j4", 3))
			init_julia(data, 0, 0);
		else
			err = 1;
	}
	else if (argc == 5)
	{
		if (!ft_strncmp(argv[2], "j3", 3))
			err = check_julia_inputs(argv, data, JULIATHREE);
		else if (!ft_strncmp(argv[2], "j0", 3))
			err = check_julia_inputs(argv, data, JULIA);
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

	if (argc == 3 || argc == 5)
		err = check_init_fractol(argc, argv, data);
	else
		err = 1;
	return (err);
}
