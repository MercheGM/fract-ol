/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:40:42 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/02 20:32:27 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
void init_mandelbrot(t_data *data)
{
	data->maxIter = 200;
    data->x_min = -2.0;
    data->x_max = 1.0;
    data->y_min = -1.5;
    data->y_max = 1.5;
    data->zoom_factor = 0.9;
}

// Función para mapear píxel a coordenada compleja
void pixel_to_complex(int x, int y, t_data	*data)
{
    data->c_re = data->x_min + ((double)x / WIDTH) * (data->x_max - data->x_min);
    data->c_im = data->y_min + ((double)y / HEIGHT) * (data->y_max - data->y_min);
}

// Función para calcular el número de iteraciones en Mandelbrot
int mandelbrot_iter(t_data	*data) 
{
    double z_re;
    double z_im;
    int i;
    double temp;
    
    z_re = 0;
    z_im = 0;
    i = 0;
    while ((z_re * z_re + z_im * z_im <= 4) && (i < data->maxIter)) {
        temp = z_re * z_re - z_im * z_im + data->c_re;
        z_im = 2 * z_re * z_im + data->c_im;
        z_re = temp;
        i++;
    }
    return (i);
}

// Función para obtener un color basado en el número de iteraciones
uint32_t get_color(int iterations, t_data	*data) 
{
    if (iterations == data->maxIter)
        return 0x000000; // negro para puntos dentro del conjunto
    return (iterations * 0x00FF00 / data->maxIter); // ejemplo de gradiente
}

int print_mandelbrot(t_data	*data)
{
    // Dibuja el fractal: recorre cada píxel de la imagen
	int x = 0;
	int y = 0;
    int iterations = 0;
    uint32_t color;
    
    while (x < WIDTH)
    {
		y = 0;
        while (y < HEIGHT)
        {
            // Mapea el píxel al plano complejo
            pixel_to_complex(x, y, data);
            iterations = mandelbrot_iter(data);
            color = get_color(iterations, data);
            mlx_put_pixel(data->img, x, y, color);
			y++;
        }
		x++;
    }
    mlx_image_to_window(data->mlx, data->img, 0, 0);
    return (0);
}

int mandelbrot(t_data	*data)
{
	init_mandelbrot(data);
	print_mandelbrot(data);
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
    
   // mlx_mouse_hook(data->mlx, &mouse_hook, mlx);
    // Registra el callback para eventos de teclado
    //mlx_key_hook(data->mlx, my_keyhook, data);
    // Bucle principal de MLX42 para procesar eventos
    mlx_loop(data->mlx);
	
    return EXIT_SUCCESS;
}
