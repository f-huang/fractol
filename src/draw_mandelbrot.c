/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:50:30 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 11:56:54 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

void	draw_mandelbrot(t_draw_helper *helper, t_complex z, t_complex c)
{
	int			i;
	long double	square_real;
	long double	square_imaginary;

	ft_bzero(&z, sizeof(t_complex));
	i = -1;
	while (++i < helper->fractal.iteration\
		&& (square_real = z.real * z.real)
			+ (square_imaginary = z.imaginary * z.imaginary) < 4.0)
	{
		z = (t_complex) {
			.imaginary = 2.0 * z.imaginary * z.real + c.imaginary,
			.real = square_real - square_imaginary + c.real
		};
	}
	put_pixel_in_fractal(helper->img, helper->fractal, helper->offset, i);
}
