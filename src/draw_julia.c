/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:51:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 14:15:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

void	draw_julia(t_draw_helper *helper, t_complex z, t_complex c)
{
	int			i;
	long double	square_real;
	long double	square_imaginary;

	i = -1;
	while (++i < helper->fractal.iteration\
		&& (square_real = c.real * c.real)
			+ (square_imaginary = c.imaginary * c.imaginary) < 4.0)
	{
		c = (t_complex) {
			.imaginary = 2.0 * c.imaginary * c.real
				+ helper->fractal.motion_complex.imaginary,
			.real = square_real - square_imaginary
				+ helper->fractal.motion_complex.real
		};
	}
	put_pixel_in_fractal(helper->img, helper->fractal, helper->offset, i);
	(void)z;
}
