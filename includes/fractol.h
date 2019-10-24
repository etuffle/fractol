/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etuffleb <etuffleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:24:59 by etuffleb          #+#    #+#             */
/*   Updated: 2019/10/22 22:07:52 by etuffleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define HEIGHT 1500
# define WIDTH 1500
# define MAX_ITERATION 50
# define SCALE_K 1.1

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_status
{
	double			scale;
	int				mouse_x;
	int				mouse_y;
	int				off_x;
	int				off_y;
	t_complex		k;
}					t_status;

typedef struct		s_param
{
	void			*ptr;
	void			*win;
	void			*img_ptr;
	int				*img;
	int				fractal_case;
	t_status		*status;
}					t_param;

int					key_hook(int key, t_param *par);
int					mouse_move(int x, int y, t_param *param);
int					mouse_press(int button, int x, int y, t_param *par);
int					mouse_release(int button, int x, int y, t_param *par);
t_complex			init_complex(double re, double im);
t_status			*fill_status(t_param *par);
int					get_fractal_case(char *arg, char **str);
int					set_color(int iteration);
void				ft_error(char *str, int status);
void				fractol_draw(t_param *par);
int					fr_celtic_mandelbrot(t_complex c);
int					fr_mandelbrot(t_complex c);
int					fr_julia(t_complex c, t_param *par);
int					julia_motion(int x, int y, t_param *par);

#endif
