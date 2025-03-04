/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:14 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/04 20:20:34 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}*/
int main(int argc, char *argv[])
{
	int		err;
	t_data	*data;
	
	err = check_arg(argc, argv, data);
	if (!err)
	{
		err = init_window(data);
		//mlx_scroll_hook(data->mlx, &my_scrollhook, data);
		//mlx_key_hook(data->mlx, &my_keyhook, data);
		if (data->type == MANDELBROT)
			mandelbrot(data);
		else if (data->type == JULIA)
		{
			ft_printf("We'll see Julia fractal\n");
			
			//mlx_loop_hook(data->mlx, &hook_mandelbrot, data);
		}
	}
	//mlx_loop_hook(data->mlx, &hook, data);
	//mlx_loop(data->mlx);
	mlx_close_window(data->mlx);
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