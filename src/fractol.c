/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:33:53 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/21 22:44:27 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_fractal_case(char *arg, char **str)
{
	int			fractal_case;

	fractal_case = 0;
	if (ft_strequ(arg, "Mandelbrot"))
		fractal_case = 1;
	if (ft_strequ(arg, "Julia"))
		fractal_case = 2;
	if (ft_strequ(arg, "Celtic_Mandelbrot"))
		fractal_case = 3;
	*str = ft_strdup(arg);
	return (fractal_case);
}

int		julia_motion(int x, int y, t_param *par)
{
	par->status->k = init_complex(4 * ((double)x / WIDTH - 0.5),\
			4 * ((double)(HEIGHT - y) / HEIGHT - 0.5));
	fractol_draw(par);
	return (0);
}

int		fr_julia(t_complex c, t_param *par)
{
	t_complex	z;
	int			iteration;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < MAX_ITERATION)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + par->status->k.re,\
					2.0 * z.re * z.im + par->status->k.im);
		iteration++;
	}
	return (iteration);
}

int		fr_mandelbrot(t_complex c)
{
	t_complex	z;
	int			iteration;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < MAX_ITERATION)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + c.re,\
						2.0 * z.re * z.im + c.im);
		iteration++;
	}
	return (iteration);
}

int		fr_celtic_mandelbrot(t_complex c)
{
	t_complex	z;
	int			iteration;

	z = init_complex(c.re, c.im);
	iteration = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < MAX_ITERATION)
	{
		z = init_complex(fabs(pow(z.re, 2.0) - pow(z.im, 2.0)) + c.re,\
						2.0 * z.re * z.im + c.im);
		iteration++;
	}
	return (iteration);
}
