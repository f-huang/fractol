/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:23:32 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 11:09:30 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "fract_ol.h"

static int	is_type_already_present(t_fractal *fractals, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (index != i && fractals[i].type == fractals[index].type)
			return (1);
		++i;
	}
	return (0);
}

static int	get_number_of_fractals(const char **av)
{
	int		i;
	int		j;
	int		total;

	total = 0;
	i = 1;
	while (av[i])
	{
		if ((int)(get_fractal_type(av[i])) == -1)
			return (-1);
		j = i + 1;
		while (av[j])
		{
			if (ft_strequ(av[i], av[j]))
			{
				--total;
				break ;
			}
			++j;
		}
		++i;
		++total;
	}
	return (total);
}

static void	init_fractal_parameters(t_fractal *fractal)
{
	if (fractal->type == MANDELBROT)
	{
		fractal->abscissa = (t_range) { .min = MANDELBROT_X1, .max = MANDELBROT_X2 };
		fractal->ordinate = (t_range) { .min = MANDELBROT_Y1, .max = MANDELBROT_Y2 };
	}
	else if (fractal->type == JULIA)
	{
		fractal->motion_complex = (t_complex) { .real = JULIA_INITIAL_REAL, .imaginary = JULIA_INITIAL_IMAGINARY };
		fractal->abscissa = (t_range) { .min = JULIA_X1, .max = JULIA_X2 };;
		fractal->ordinate = (t_range) { .min = JULIA_Y1, .max = JULIA_Y2 };

	}
	else if (fractal->type == BURNING_SHIP)
	{
		fractal->abscissa = (t_range) { .min = BURNING_SHIP_X1, .max = BURNING_SHIP_X2 };
		fractal->ordinate = (t_range) { .min = BURNING_SHIP_Y1, .max = BURNING_SHIP_Y2 };
	}
	fractal->zoom = (IMAGE_SIZE / get_distance(fractal->ordinate.max, fractal->ordinate.min)\
		+ IMAGE_SIZE / get_distance(fractal->abscissa.max, fractal->abscissa.min)) / 2 - IMAGE_SIZE * 0.02;
	fractal->iteration = ITERATIONS;
}

int		init(t_env *e, const char **av)
{
	int		i;
	int		j;

	if ((e->number_of_fractals = get_number_of_fractals(av)) == -1)
		return (0);
	if (!(e->fractals = ft_memalloc(sizeof(t_fractal) * (e->number_of_fractals))))
		return (0);
	e->mlx_img.size = IMAGE_SIZE;
	i = 1;
	j = 0;
	while (av[i] && j < e->number_of_fractals)
	{
		e->fractals[j].type = get_fractal_type(av[i]);
		if (!is_type_already_present(e->fractals, j))
		{
			init_fractal_parameters(e->fractals + j);
			++j;
		}
		++i;
	}
	e->mlx_img.rgb = (t_rgb) { .r = 50, .g = 50, .b = 50 };
	return (1);
}
