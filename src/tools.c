/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:34:14 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/22 22:08:37 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_error(char *str, int status)
{
	ft_putendl(str);
	exit(status);
}

t_status	*fill_status(t_param *par)
{
	if (!(par->status = malloc(sizeof(t_status))))
		ft_error("Error", 2);
	par->status->mouse_x = WIDTH / 2;
	par->status->mouse_y = HEIGHT / 2;
	par->status->off_x = 0;
	par->status->off_y = 0;
	par->status->scale = 1;
	return (par->status);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int			set_color(int iteration)
{
	double		t;
	int			res;

	t = (double)iteration / (double)MAX_ITERATION;
	res = (int)(9 * (1 - t) * pow(t, 3) * 255) << 16;
	res |= (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255) << 8;
	res |= (int)(8.5 * pow((1 - t), 3) * t * 255);
	return (res);
}
