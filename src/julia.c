/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:53:41 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/11 17:19:31 by mergarci         ###   ########.fr       */
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

   /* data->c_re = -1.0877;
    data->c_im =  0.302;*/
    data->zoom_factor = 1;
    data->color = COLOR_PURPLE;
    data->transition = DEGRADED;
    data->step_size = 1;


}


int julia_iter(int x, int y, t_data * data)
{
    double z_re;
    double z_im;
    int iterations;
    double temp;
    int exp;
    
    z_re = ((double)x / WIN_WIDTH - 0.5) * 3.5 / data->zoom_factor + data->x_min;
    z_im = ((double)y / WIN_HEIGHT - 0.5) * 2.0 / data->zoom_factor + data->y_min;

    iterations = 0;
    temp = 0;
    exp = 2;
    while (pow(z_re, exp) + pow(z_im, exp) <= 4 && iterations < data->max_iter)
    {
        temp = pow(z_re, exp) - pow(z_im, exp) + data->c_re;
        z_im = exp * z_re * z_im + data->c_im;
        z_re = temp;
        iterations++;
    }
    return (iterations);
}

void print_julia(t_data *data)
{
    int x;
    int y;
    int iterations;
    int color;

    x = 0;
    while (x < WIN_WIDTH)
    {
        y = 0;
        while (y < WIN_HEIGHT)
        {
            iterations = julia_iter(x, y, data);
            // Asigna un color según las iteraciones
            color = get_color(iterations, data);
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
	print_julia(data);
    //printf("colores: R: %d G: %d, B: %d, A: %d\n", get_r(data->color), get_g(data->color), get_b(data->color), get_a(data->color));
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
    
   // mlx_mouse_hook(data->mlx, &mouse_hook, mlx);
    mlx_key_hook(data->mlx, my_keyhook, data);
    mlx_loop(data->mlx);
	
    return EXIT_SUCCESS;
}
