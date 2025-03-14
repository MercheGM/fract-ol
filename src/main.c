/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:14 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/11 16:59:25 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char *argv[])
{
	int		err;
	t_data	*data;
	
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	err = check_arg(argc, argv, data);
	if (!err)
	{
		err = init_window(data);
		if (data->type == MANDELBROT)
			mandelbrot(data);
		else if (data->type == JULIA)
		{
			ft_printf("We'll see Julia fractal\n");
			julia(data);
			//mlx_loop_hook(data->mlx, &hook_mandelbrot, data);
		}
		else
		{
			free(data);
			data = NULL;
		}
	}
	closing_window(data);
	return (0);

}

//#include "MLX42/MLX42.h"
/*#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct s_julia {
    mlx_t *mlx;
    mlx_image_t *img;
    double c_re;
    double c_im;
    double zoom;
    double offsetX;
    double offsetY;
} t_julia;

double ft_pow(double n, int exp)
{
    int result;

    result = 1;
    while (exp--)
        result *= n;
    return (result);
}
int julia_iter(int x, int y, t_julia * data, int max_iterations)
{
    double z_re;
    double z_im;
    int iterations;
    double temp;
    int exp;
    
    z_re = ((double)x / WIDTH - 0.5) * 3.5 / data->zoom + data->offsetX;
    z_im = ((double)y / HEIGHT - 0.5) * 2.0 / data->zoom + data->offsetY;

    iterations = 0;
    temp = 0;
    exp = 2;
    while (pow(z_re, exp) + pow(z_im, exp) <= 4 && iterations < max_iterations)
    {
        temp = pow(z_re, exp) - pow(z_im, exp) + data->c_re;
        z_im = exp * z_re * z_im + data->c_im;
        z_re = temp;
        iterations++;
    }
    return (iterations);
}
void generate_julia2(t_julia *data)
{
    int max_iterations = 30;
    int exp = 2;
    int iterations;
    for (uint32_t x = 0; x < WIDTH; x++)
    {
        for (uint32_t y = 0; y < HEIGHT; y++)
        {
            iterations = julia_iter(x, y, data, max_iterations);
            // Asigna un color según las iteraciones
            uint32_t color;
            if (iterations == max_iterations)
                color = 0xFFFFFFFF; // negro (punto dentro del fractal)
            else
                color = 0x000000FF | ((iterations * 255 / max_iterations) << 24); // rojo degradado

            // Dibuja el píxel en la imagen
            mlx_put_pixel(data->img, x, y, color);
        }
    }

    // Muestra la imagen en la ventana
    mlx_image_to_window(data->mlx, data->img, 0, 0);
}

// Callback para cerrar la ventana con la tecla ESC
void key_callback(mlx_key_data_t keydata, void *param)
{
    t_julia *data = (t_julia *)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(data->mlx);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Uso: %s <c_re> <c_im>\n", argv[0]);
        return EXIT_FAILURE;
    }

    t_julia data;

    // Convierte argumentos a números
    data.c_re = atof(argv[1]);
    data.c_im = atof(argv[2]);
    data.zoom = 1.0;
    data.offsetX = 0.0;
    data.offsetY = 0.0;
    
    int i = 4;
    //printf("%i - %f\n", i, pow(i, 2));
    // Inicializa MLX42
    data.mlx = mlx_init(WIDTH, HEIGHT, "Fractal de Julia", false);
    if (!data.mlx)
        return EXIT_FAILURE;

    // Crea una imagen
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    if (!data.img)
        return EXIT_FAILURE;

    // Genera el fractal de Julia
    generate_julia2(&data);

    // Maneja eventos de teclado
    mlx_key_hook(data.mlx, key_callback, &data);

    // Loop principal de eventos
    mlx_loop(data.mlx);

    return EXIT_SUCCESS;
}*/
