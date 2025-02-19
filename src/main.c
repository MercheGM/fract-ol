/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:14 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/18 20:26:25 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*int main(int argc, char *argv[])
{
	
	check_arg(argc, argv);
	if (ft_atoi(argv[1]) == 1)
		ft_printf("We'll see Julia fractal\n");
	else if (ft_atoi(argv[1]) == 2)
		ft_printf("We'll see Mandelbrot fractal\n");
	
	return (0);

}*/

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!data.mlx)
	{
		ft_printf("ERROR: MLX init failed\n");
		return (EXIT_FAILURE);
	}
	data.img = mlx_new_image(data.mlx, 500, 200);
	if (!data.img)
	{
		ft_printf("ERROR: MLX img failed\n");
		mlx_terminate(data.mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data.mlx, data.img, 0, 0))
	{
		ft_printf("ERROR: Failed to put image to window\n");
		mlx_delete_image(data.mlx, data.img);
		mlx_terminate(data.mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(data.mlx);
	return (0);
}
