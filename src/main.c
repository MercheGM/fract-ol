/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:14 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/09 19:21:59 by mergarci         ###   ########.fr       */
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


/*
//#include "MLX42/MLX42.h"
#include <stdlib.h>
#include <string.h>
#define BPP sizeof(int32_t)

int32_t	main(void)
{
    mlx_t* mlx = mlx_init(256, 256, "MLX42", true);
    if (!mlx)
        exit(EXIT_FAILURE);

    mlx_image_t* img = mlx_new_image(mlx, 128, 128);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(img->pixels, 125, img->width * img->height * BPP);

    mlx_image_to_window(mlx, img, 15, 15);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}*/