/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:40:42 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/10 20:01:29 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_mandelbrot(t_data *data)
{
    data->win_title = "Mandelbrot Fractal";
    data->type = MANDELBROT;
    data->x_min = -2.0;
    data->x_max = 1.0;
    data->y_min = -1.5;
    data->y_max = 1.5;
    data->zoom_factor = 0.9;
    data->color = COLOR_PURPLE;
    data->transition = DEGRADED;
    data->step_size = 1;
}

void pixel_to_complex(int x, int y, t_data	*data)
{
    data->c_re = data->x_min + ((double)x / WIN_WIDTH) * (data->x_max - data->x_min);
    data->c_im = data->y_min + ((double)y / WIN_HEIGHT) * (data->y_max - data->y_min);
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
    while ((z_re * z_re + z_im * z_im <= 4) && (i < data->max_iter)) 
    {
        temp = z_re * z_re - z_im * z_im + data->c_re;
        z_im = 2 * z_re * z_im + data->c_im;
        z_re = temp;
        i++;
    }
    return (i);
}


int print_mandelbrot(t_data	*data )
{
	int x;
	int y;
    int iterations;
    int color;
    
    iterations = 0;
    x = 0;
    y = 0;
    while (x < WIN_WIDTH)
    {
		y = 0;
        while (y < WIN_HEIGHT)
        {
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
	//init_mandelbrot(data);
	print_mandelbrot(data);
    //printf("colores: R: %d G: %d, B: %d, A: %d\n", get_r(data->color), get_g(data->color), get_b(data->color), get_a(data->color));
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
    
   // mlx_mouse_hook(data->mlx, &mouse_hook, mlx);
    mlx_key_hook(data->mlx, my_keyhook, data);
    mlx_loop(data->mlx);
	
    return EXIT_SUCCESS;
}
