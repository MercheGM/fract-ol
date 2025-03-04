/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:01:58 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/04 21:02:36 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}
uint32_t get_transition(int iter, int max_iter)
{
    double a = (double)iter / max_iter;
    // Se usan funciones coseno para crear un efecto cíclico en el gradiente
    int r = (int)((0.5 * cos(2 * M_PI * a) + 0.5) * 255);
    int g = (int)((0.5 * cos(2 * M_PI * a + 2 * M_PI/3) + 0.5) * 255);
    int b = (int)((0.5 * cos(2 * M_PI * a + 4 * M_PI/3) + 0.5) * 255);
    printf("r:%d g:%d b:%d \n", r, g, b);
    return get_rgba(r, g, b, a);
}
// Función para obtener un color basado en el número de iteraciones
uint32_t get_color(int iterations, t_data	*data) 
{
    uint32_t color;
    
    if (iterations == data->max_iter)
        color = COLOR_BLACK; 
    /*else if (iterations == 0)
        color = NEON_YELLOW;
    else if ((iterations > 0) && (iterations <= (int)(data->max_im / 2)))
        color = NEON_BLUE;
    else if ((iterations > (int)(data->max_im / 2)) && (iterations < (int)(data->max_im)))
        color = NEON_PINK;*/
    else
        color = iterations * data->color / data->max_iter;
        //color = get_rgba(255 *(iterations / data->max_iter), 0, 255 *(iterations / data->max_iter), 0);
    return (color); 
}
