/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corresponding_fractal.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:03:02 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/29 18:44:28 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	draw_corresponding_fractal(t_draw_helper *helper, pthread_t *thread, enum e_fractal_type type)
{
	static void	(*(*f[])(void *)) = {
		[MANDELBROT] = draw_mandelbrot,
		[JULIA] = draw_julia,
		[BURNING_SHIP] = draw_burning_ship
	};
	pthread_create(thread, NULL, f[type], helper);
}
