/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_burning_ship.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:58:19 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/29 17:42:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

static int	define_z_complex(t_complex c, int max_iterations)
{
	int			i;
	long double	square_real;
	long double	square_imaginary;
	t_complex	z;

	ft_bzero(&z, sizeof(t_complex));
	ft_memcpy(&z, &c, sizeof(t_complex));
	i = -1;
	while (++i < max_iterations\
		&& (square_real = z.real * z.real)
			+ (square_imaginary = z.imaginary * z.imaginary) < 4.0)
	{
		z = (t_complex) {
			.imaginary = 2.0 * ft_abs(z.imaginary * z.real) + c.imaginary,
			.real = square_real - square_imaginary + c.real
		};
	}
	return (i);
}

void	*draw_burning_ship(void *args)
{
	t_draw_helper	*helper;
	t_complex		c;
	int				i;

	helper = (t_draw_helper*)args;
	ft_bzero(&c, sizeof(t_complex));
	while (helper->offset.x < helper->range.x)
	{
		c.real = helper->offset.x / helper->img->fractal.zoom + helper->img->fractal.abscissa.min;
		helper->offset.y = 0;
		while (helper->offset.y < helper->range.y)
		{
			c.imaginary = helper->offset.y / helper->img->fractal.zoom + helper->img->fractal.ordinate.min;
			i = define_z_complex(c, helper->img->fractal.iteration);
			put_pixel_in_fractal(helper->img, helper->offset, i);
			++helper->offset.y;
		}
		++helper->offset.x;
	}
	return (NULL);
}
