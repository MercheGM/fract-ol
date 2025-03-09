/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:01:58 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/09 21:07:37 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}



/*uint32_t get_transition(int iter, int max_iter)
{
    double a = (double)iter / max_iter;
    // Se usan funciones coseno para crear un efecto cíclico en el gradiente
    int r = (int)((0.5 * cos(2 * M_PI * a) + 0.5) * 255);
    int g = (int)((0.5 * cos(2 * M_PI * a + 2 * M_PI/3) + 0.5) * 255);
    int b = (int)((0.5 * cos(2 * M_PI * a + 4 * M_PI/3) + 0.5) * 255);
    //printf("r:%d g:%d b:%d \n", r, g, b);
    return (get_rgba(r, g, b, a));
}*/

// Get the red channel.
int get_r(int rgba)
{
    return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
    return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
    return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
    return (rgba & 0xFF);
}

uint32_t get_degraded(int iterations, t_data *data)
{
    int r;
    int g;
    int b;
    int a;

    r = get_r(data->color);
    g = get_g(data->color);
    b = get_b(data->color);
    a = get_a(data->color);
    return(get_rgba(iterations * (get_r(data->color) / ITER), \
                        iterations * (get_g(data->color) / ITER), \
                        iterations * (get_b(data->color) / ITER), a));
}
// Función para obtener un color basado en el número de iteraciones
uint32_t get_color(int iterations, t_data	*data) 
{
    uint32_t color;
    
    if (iterations == data->max_iter)
        color = COLOR_BLACK; 
    else
    {
        if (data->transition == DEGRADED)
            color = get_degraded(iterations, data);
        else if (data->transition == PSYCHEDELIC)
            color = iterations * (data->color / ITER);

    }
        //color = iterations * (data->color / ITER);
    return (color); 
}

