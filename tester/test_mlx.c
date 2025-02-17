/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:06:07 by mergarci          #+#    #+#             */
/*   Updated: 2025/02/15 19:24:56 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_key(int key, void *param)
{
	ft_putchar_fd('X', 1);
	ft_printf("*%d*\n", key);
	return (0);
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	ft_printf("%s\n", "holi holi");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250,250, 0xFFFFFF);
	mlx_key_hook(mlx_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
