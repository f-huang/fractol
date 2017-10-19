/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:49:01 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:56:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

const char	*get_fractal_type_name(enum e_fractal_type type)
{
	static char	*names[] = {
		[MANDELBROT] = "Mandelbrot"
	};

	return (names[type]);
}
