/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mergarci <mergarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:15:32 by mergarci          #+#    #+#             */
/*   Updated: 2025/03/17 20:08:47 by mergarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/ft_printf.h"
# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <math.h>

# define M_PI 3.14159265358979323846
# define WIN_WIDTH 600
# define WIN_HEIGHT 500

# define ITER 60

# define COLOR_BLACK 0x000000FF
# define NEON_PINK 0xFF149300
# define NEON_GREEN 0x00FF00
# define NEON_BLUE 0x00FFFF00
# define NEON_YELLOW 0xBBFF0000
# define NEON_RED 0xFF000000
# define COLOR_WHITE 0xFFFFFFFF
# define COLOR_PURPLE 0x6C3483FF
# define COLOR_END 0xABEBC6FF
# define COLOR_RED 0xFF0000FF

# define MANDELBROT 1
# define JULIA 2

# define PSYCHEDELIC 1
# define DEGRADED_BLACK 2
# define DEGRADED 3

typedef struct s_data
{
	char		*win_title;
	int			type;
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			max_iter;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		c_re;
	double		c_im;
	double		zoom_factor;
	uint32_t	color;
	int			transition;
	int			step_size;
}				t_data;

//inputs.c
int			check_arg(int argc, char *argv[], t_data *data);
int			print_help(t_data *data);
//hook.c
void		scroll_zoom(double xdelta, double ydelta, void *param);
void		key_events(mlx_key_data_t keydata, void *param);
void		hook(void *param);
void		check_mouse_pos(int *x, int *y);
double ft_atof(const char *nptr);
//mandelbrot.c
void		init_mandelbrot(t_data *data, int iter);
int			print_mandelbrot(t_data	*data);
int			mandelbrot(t_data *data);

//window.c
int			init_window(t_data	*data);
void		closing_window(t_data *data);
int			print_fractal(t_data *data);
int			fractal(t_data	*data);

//julia.c
void	init_julia(t_data *data, int iter, double cr, double ci);
//int calculate_julia(int x, int y, t_data * data);
void		print_julia(t_data	*data);
//int julia(t_data	*data);

//zoom.c
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		zoom_in(t_data *data, double zoom_factor, int x, int y);
void		zoom_out(t_data *data, double zoom_factor, int x, int y);

//colors.c
uint32_t	get_color(int iterations, t_data *data);

//color_utils.c
int			get_rgba(int r, int g, int b, int a);
int			get_r(int rgba);
int			get_g(int rgba);
int			get_b(int rgba);
int			get_a(int rgba);
#endif