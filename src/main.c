/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:28:14 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/18 18:04:51 by mergarci         ###   ########.fr       */
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

int	deal_key(int key, void *param)
{
	ft_putchar_fd('X', 1);
	//ft_printf("*%d*\n", key);
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	//ft_printf("%s\n", "holi holi");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	//mlx_pixel_put(mlx_ptr, win_ptr, 250,250, 0xFFFFFF);
	//mlx_key_hook(mlx_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}