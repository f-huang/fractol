/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:51:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/29 20:52:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

static int	define_z_complex(t_complex c, t_complex z, int max_iterations)
{
	int			i;
	long double	square_z;
	long double	square_imaginary;

	i = -1;
	while (++i < max_iterations\
		&& (square_z = z.real * z.real)
			+ (square_imaginary = z.imaginary * z.imaginary) < 4.0)
	{
		z = (t_complex) {
			.imaginary = 2.0 * z.imaginary * z.real + c.imaginary,
			.real = square_z - square_imaginary + c.real
		};
	}
	return (i);
}

void		*draw_julia(void *args)
{
	t_draw_helper	*helper;
	t_complex		z;
	int				i;

	helper = (t_draw_helper*)args;
	ft_bzero(&z, sizeof(t_complex));
	while (helper->offset.x < helper->range.x)
	{
		z.real = helper->offset.x / helper->img->fractal.zoom + helper->img->fractal.abscissa.min;
		helper->offset.y = 0;
		while (helper->offset.y < helper->range.y)
		{
			z.imaginary = helper->offset.y / helper->img->fractal.zoom + helper->img->fractal.ordinate.min;
			i = define_z_complex(helper->img->fractal.motion_complex, z, helper->img->fractal.iteration);
			put_pixel_in_fractal(helper->img, helper->offset, i);
			++helper->offset.y;
		}
		++helper->offset.x;
	}
	return (NULL);
}
