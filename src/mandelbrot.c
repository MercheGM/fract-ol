/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:40:42 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/25 17:23:38 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void init_mandelbrot(t_data *data)
{
	data->maxIter = 300;
}

int print_mandelbrot(t_data	*data, double zoom, double offsetX, double offsetY)
{
    // Dibuja el fractal: recorre cada píxel de la imagen
	uint32_t x = 0;
	uint32_t y = 0;
    while (x < WIDTH)
    {
		y = 0;
        while (y < HEIGHT)
        {
            // Mapea el píxel al plano complejo
            double c_re = ((double)x / WIDTH - 0.5) * 3.5 / zoom + offsetX;
            double c_im = ((double)y / HEIGHT - 0.5) * 2.0 / zoom + offsetY;
            double z_re = 0;
            double z_im = 0;
            int iterations = 0;
            while (z_re * z_re + z_im * z_im <= 4 && iterations < data->maxIter)
            {
                double temp = z_re * z_re - z_im * z_im + c_re;
                z_im = 2 * z_re * z_im + c_im;
                z_re = temp;
                iterations++;
            }
            // Asigna un color según las iteraciones (puedes mejorar la paleta de colores)
            uint32_t color;
            if (iterations == data->maxIter)
                color = 0x000000FF; // negro para puntos dentro del fractal
			else if ((iterations <= data->maxIter / 3) && (iterations <= 0))
				color = 0xFF0000FF;
			else if ((iterations > data->maxIter / 3) && (iterations <= 2 * (data->maxIter / 3)))
				color = 0x00FF00FF;
			else
                color = 0x0000FFFF | ((iterations * 255 / data->maxIter) << 16);
            // Dibuja el píxel en la imagen
            mlx_put_pixel(data->img, x, y, color);
			y++;
        }
		x++;

    }
    // Muestra la imagen en la ventana
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    return (0);
}

int mandelbrot(t_data	*data)
{
	init_mandelbrot(data);
    // Parámetros para el fractal
    double zoom = 1;
    double offsetX = 0;
    double offsetY = 0;
	print_mandelbrot(data, zoom, offsetX, offsetY);


    // Registra el callback para eventos de teclado
    mlx_key_hook(data->mlx, my_keyhook, data);
    // Bucle principal de MLX42 para procesar eventos
    mlx_loop(data->mlx);
	
    return EXIT_SUCCESS;
}
