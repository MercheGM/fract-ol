/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:14 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/25 17:26:52 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Callback para manejar eventos de teclado
void key_callback(mlx_key_data_t keydata, void *param)
{
    mlx_t *mlx = (mlx_t *)param;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(mlx);
}




int main(int argc, char *argv[])
{
	int		err;
	t_data	*data;
	
	err = check_arg(argc, argv);
	if (!err)
	{
		err = init_window(data);
		//mlx_scroll_hook(data->mlx, &my_scrollhook, NULL);
		//mlx_key_hook(data->mlx, &my_keyhook, data);
		if (ft_atoi(argv[1]) == 1)
		{
			ft_printf("We'll see Julia fractal\n");
		}
		else if (ft_atoi(argv[1]) == 2)
		{
			ft_printf("We'll see Mandelbrot fractal\n");
			mandelbrot(data);
			//mlx_loop_hook(data->mlx, &hook_mandelbrot, data);
		}
	}
	//mlx_loop_hook(data->mlx, &hook, data);
	//mlx_loop(data->mlx);
	mlx_close_window(data->mlx);
	return (0);

}



