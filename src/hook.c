/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:56:48 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/22 22:08:22 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_hook(int key, t_param *par)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	(void)par;
	return (0);
}

int			mouse_move(int x, int y, t_param *par)
{
	if (par->fractal_case == 2)
	{
		par->status->mouse_x = x;
		par->status->mouse_y = y;
		julia_motion(x, y, par);
	}
	return (0);
}

int			mouse_press(int button, int x, int y, t_param *par)
{
	if (button == 5)
	{
		par->status->scale *= SCALE_K;
		par->status->off_x = par->status->off_x * 1.1 + x * 0.1;
		par->status->off_y = par->status->off_y * 1.1 + y * 0.1;
	}
	else if (button == 4)
	{
		par->status->scale /= SCALE_K;
		par->status->off_x = par->status->off_x / 1.1 - x * 0.1;
		par->status->off_y = par->status->off_y / 1.1 - y * 0.1;
	}
	fractol_draw(par);
	return (0);
}
