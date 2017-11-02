/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal_parameters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:16:15 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 17:17:29 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

void	init_fractal_parameters(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		fractal->abscissa = (t_range) {
			.min = MANDELBROT_X1, .max = MANDELBROT_X2 };
		fractal->ordinate = (t_range) {
			.min = MANDELBROT_Y1, .max = MANDELBROT_Y2 };
	}
	else if (fractal->type == JULIA)
	{
		fractal->motion_complex = (t_complex) {
			.real = JULIA_INITIAL_REAL, .imaginary = JULIA_INITIAL_IMAGINARY };
		fractal->abscissa = (t_range) { .min = JULIA_X1, .max = JULIA_X2 };
		fractal->ordinate = (t_range) { .min = JULIA_Y1, .max = JULIA_Y2 };
	}
	else if (fractal->type == BURNING_SHIP)
	{
		fractal->abscissa = (t_range) {
			.min = BURNING_SHIP_X1, .max = BURNING_SHIP_X2 };
		fractal->ordinate = (t_range) {
			.min = BURNING_SHIP_Y1, .max = BURNING_SHIP_Y2 };
	}
	fractal->zoom = (IMAGE_SIZE / get_distance(fractal->ordinate.max,
		fractal->ordinate.min) + IMAGE_SIZE / get_distance(
		fractal->abscissa.max, fractal->abscissa.min)) / 2 - IMAGE_SIZE * 0.02;
	fractal->iteration = ITERATIONS;
}
