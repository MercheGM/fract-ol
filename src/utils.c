/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:34:49 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/17 20:50:49 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double ft_atof(const char *nptr)
{
	int i;
	bool is_negative;
	double result;
    int exp;

	result = (double)ft_atoi(nptr);
	is_negative = false;
	i = 0;
    exp = 1;
	if (nptr[0] == '-')
		is_negative = true;
	while (nptr[i] != '.' && nptr[i])
        i++;
    if (nptr[i++] != 0)
    {
        while (nptr[i])
        {
            if (is_negative)
                result -= ((double)(nptr[i]) - '0') * pow(10, -1 * (exp++));
            else
                result += ((double)(nptr[i]) - '0') * pow(10, -1 * (exp++));
            i++;
        }
    }
	return (result);
}
