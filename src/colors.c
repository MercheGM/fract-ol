/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 21:01:58 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/10 19:53:21 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

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

uint32_t get_degraded_black(int iterations, t_data *data)
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
// Función para interpolar entre dos colores en formato 0xAARRGGBB
uint32_t interpolar_color(t_data *data, int iter) 
{
    double t = (double) iter / data->max_iter;
    
    // Extraer componentes (cada uno usa 2 bytes)
    uint8_t r1 = (data->color >> 24) & 0xFF;
    uint8_t g1 = (data->color >> 16) & 0xFF;
    uint8_t b1 = (data->color >> 8)  & 0xFF;
    uint8_t a1 = (data->color)       & 0xFF;

    // Interpolación lineal para cada canal
    uint8_t a = (uint8_t)((1 - t) * a1 + t * 0x00);
    uint8_t r = (uint8_t)((1 - t) * r1 + t * 0x00);
    uint8_t g = (uint8_t)((1 - t) * g1 + t * 0xFF);
    uint8_t b = (uint8_t)((1 - t) * b1 + t * 0xFF);

    // Reconstruir el color interpolado en formato 0xAARRGGBB
    return ((r << 24) | (g << 16) | (b << 8) | a);
}

// Función escalonada para interpolación de color
uint32_t get_degraded_steps(t_data *data, int iter,  int pasos) {
    int step = (int)(iter / data->step_size);  // Número de escalón actual
    double t = (double) step / pasos;  // Factor de interpolación basado en el escalón

    // Extraer componentes de color
    uint8_t r1 = (data->color >> 24) & 0xFF;
    uint8_t g1 = (data->color >> 16) & 0xFF;
    uint8_t b1 = (data->color >> 8)  & 0xFF;
    uint8_t a1 = (data->color)       & 0xFF;

    uint8_t r2 = (COLOR_END >> 24) & 0xFF; 
    uint8_t g2 = (COLOR_END >> 16) & 0xFF;
    uint8_t b2 = (COLOR_END >> 8)  & 0xFF;
    uint8_t a2 = (COLOR_END)       & 0xFF;

    // Interpolación en escalones
    uint8_t a = (uint8_t)((1 - t) * a1 + t * a2);
    uint8_t r = (uint8_t)((1 - t) * r1 + t * r2);
    uint8_t g = (uint8_t)((1 - t) * g1 + t * g2);
    uint8_t b = (uint8_t)((1 - t) * b1 + t * b2);

    return ((r << 24) | (g << 16) | (b << 8) | a);
}


// Función para obtener un color basado en el número de iteraciones
uint32_t get_color(int iterations, t_data	*data) 
{
    uint32_t color;
    
    if (iterations == data->max_iter)
        color = COLOR_BLACK; 
    else
    {
        if (data->transition == DEGRADED_BLACK)
            color = get_degraded_black(iterations, data);
        else if (data->transition == PSYCHEDELIC)
            color = iterations * (data->color / ITER);
        else if (data->transition == DEGRADED)
            color = get_degraded_steps(data, iterations, 20);
    }
    return (color); 
}

