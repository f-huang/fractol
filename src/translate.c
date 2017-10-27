/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:10:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/27 11:29:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

#define TRANSLATE_VALUE(x) 150 / x

void	translate_left(t_env *e)
{
	e->mlx_img.fractal.abscissa.min -= TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
	e->mlx_img.fractal.abscissa.max -= TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
}

void	translate_right(t_env *e)
{
	e->mlx_img.fractal.abscissa.min += TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
	e->mlx_img.fractal.abscissa.max += TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
}

void	translate_up(t_env *e)
{
	e->mlx_img.fractal.ordinate.min -= TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
	e->mlx_img.fractal.ordinate.max -= TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
}

void	translate_down(t_env *e)
{
	e->mlx_img.fractal.ordinate.min += TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
	e->mlx_img.fractal.ordinate.max += TRANSLATE_VALUE(e->mlx_img.fractal.zoom);
}
