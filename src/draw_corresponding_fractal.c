/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corresponding_fractal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:03:02 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/29 21:33:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

static void	*draw_image(void *args)
{
	t_draw_helper	*helper;
	t_complex		c;
	t_complex		z;

	helper = (t_draw_helper*)args;
	ft_bzero(&z, sizeof(t_complex));
	while (helper->offset.x < helper->range.x)
	{
		c.real = helper->offset.x / helper->img->fractal.zoom + helper->img->fractal.abscissa.min;
		helper->offset.y = 0;
		while (helper->offset.y < helper->range.y)
		{
			c.imaginary = helper->offset.y / helper->img->fractal.zoom + helper->img->fractal.ordinate.min;
			helper->f(helper, z, c);
			++helper->offset.y;
		}
		++helper->offset.x;
	}
	return (NULL);
}

void		draw_corresponding_fractal(t_draw_helper *helper, pthread_t *thread)
{
	static void	((*f[])(t_draw_helper *, t_complex, t_complex)) = {
		[MANDELBROT] = draw_mandelbrot,
		[JULIA] = draw_julia,
		[BURNING_SHIP] = draw_burning_ship
	};
	helper->f = f[helper->img->fractal.type];
	pthread_create(thread, NULL, &draw_image, helper);
}
