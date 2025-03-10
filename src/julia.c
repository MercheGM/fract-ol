/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:53:41 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/10 21:01:18 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_julia(t_data *data)
{
    data->win_title = "Julia Fractal";
    data->type = JULIA;
    data->x_min = 0.0;
    data->x_max = 0;
    data->y_min = 0.0;
    data->y_max = 0;
    data->c_re = -0.7;
    data->c_im =  0.270;
    data->zoom_factor = 1;
    data->color = COLOR_PURPLE;
    data->transition = DEGRADED;
    data->step_size = 1;


}


int calculate_julia(int x, int y, t_data	*data)
{

    double      z_re;
    double      z_im;
            // Mapeamos el píxel al plano complejo
    z_re = ((double)x / WIN_WIDTH - 0.5) * 3.5 / data->zoom_factor + data->x_min;
    z_im = ((double)y / WIN_WIDTH - 0.5) * 2.0 / data->zoom_factor + data->y_min;

     
    int iterations = 0;
    while (z_re * z_re + z_im * z_im <= 4 && iterations < data->max_iter)
    {
        double temp = z_re * z_re - z_im * z_im + data->c_re;
        z_im = 2 * z_re * z_im + data->c_im;
        z_re = temp;
        iterations++;
    }
    return (iterations);
}

void generate_julia(t_data *data)
{
    int max_iterations = 100;
    int x;
    int y;
    int iterations;

    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            iterations = calculate_julia(x, y, data);

            // Asigna un color según las iteraciones
            uint32_t color;
            if (iterations == data->max_iter)
                color = 0xFF000000; // negro (punto dentro del fractal)
            else
                color = 0xFF000000 | ((iterations * 255 / max_iterations) << 16); // rojo degradado

            // Dibuja el píxel en la imagen
            mlx_put_pixel(data->img, x, y, color);
            y++;
        }
        x++;
    }

    // Muestra la imagen en la ventana
    mlx_image_to_window(data->mlx, data->img, 0, 0);
}



int julia(t_data	*data)
{
	//init_mandelbrot(data);
	generate_julia(data);
    //printf("colores: R: %d G: %d, B: %d, A: %d\n", get_r(data->color), get_g(data->color), get_b(data->color), get_a(data->color));
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
    
   // mlx_mouse_hook(data->mlx, &mouse_hook, mlx);
    mlx_key_hook(data->mlx, my_keyhook, data);
    mlx_loop(data->mlx);
	
    return EXIT_SUCCESS;
}
