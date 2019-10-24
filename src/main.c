/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:34:01 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/22 22:14:08 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_set_image(t_param *p, t_complex mi, t_complex ma, t_complex fac)
{
	int			x;
	int			y;
	int			color;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		c.im = ma.im - (y + (p->status->off_y)) / p->status->scale * fac.im;
		x = 0;
		while (x < WIDTH)
		{
			c.re = mi.re + (x + (p->status->off_x)) / p->status->scale * fac.re;
			if (p->fractal_case == 1)
				color = set_color(fr_mandelbrot(c));
			else if (p->fractal_case == 2)
				color = set_color(fr_julia(c, p));
			else if (p->fractal_case == 3)
				color = set_color(fr_celtic_mandelbrot(c));
			p->img[(int)(y * HEIGHT + x)] = color;
			x++;
		}
		y++;
	}
}

void	fractol_draw(t_param *par)
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;

	min = init_complex(-2.0, -2.0);
	max.re = 2.0;
	max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	factor = init_complex((max.re - min.re) / (WIDTH - 1), \
		(max.im - min.im) / (HEIGHT - 1));
	mlx_clear_window(par->ptr, par->win);
	fractol_set_image(par, min, max, factor);
	mlx_put_image_to_window(par->ptr, par->win, par->img_ptr, 0, 0);
}

void	create_win(t_param *par, char *s, int fractal_case)
{
	int			bi_pi;
	int			size_l;
	int			en;

	par->ptr = mlx_init();
	par->win = mlx_new_window(par->ptr, WIDTH, HEIGHT, s);
	par->fractal_case = fractal_case;
	par->status = fill_status(par);
	if (!(par->img_ptr = mlx_new_image(par->ptr, WIDTH, HEIGHT)))
		ft_error("Error", 2);
	par->img = (int *)mlx_get_data_addr(par->img_ptr, &bi_pi, &size_l, &en);
	fractol_draw(par);
	mlx_hook(par->win, 2, 0, key_hook, par);
	mlx_hook(par->win, 4, 0, mouse_press, par);
	if (fractal_case == 2)
		mlx_hook(par->win, 6, 0, mouse_move, par);
	mlx_loop(par->ptr);
}

int		main(int ac, char **av)
{
	int			fractal_case;
	char		*s;
	t_param		*param;

	s = NULL;
	if (ac != 2)
		ft_error("Usage: ./fractol <Mandelbrot/Julia/Celtic_Mandelbrot>", 2);
	if (!(fractal_case = get_fractal_case(av[1], &s)))
		ft_error(\
		"Choose fractal:\tMandelbrot;\n\t\tJulia;\n\t\tCeltic_Mandelbrot", 0);
	if (!(param = malloc(sizeof(t_param))))
		ft_error("Error", 2);
	create_win(param, s, fractal_case);
	free(param->status);
	mlx_destroy_image(param->ptr, param->img_ptr);
	free(param);
	free(s);
	return (0);
}
