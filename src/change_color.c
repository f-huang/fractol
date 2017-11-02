/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 23:22:07 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 14:39:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	change_color(t_env *e)
{
	if (e->mlx_img.color != F_BLUE)
		e->mlx_img.color += (enum e_fractal_color)1;
	else
		e->mlx_img.color = F_BW;
	if (e->mlx_img.color == F_BW)
		e->mlx_img.rgb = (t_rgb) { .r = 10, .g = 10, .b = 10 };
	else if (e->mlx_img.color == F_RED)
		e->mlx_img.rgb = (t_rgb) { .r = 255, .g = 150, .b = 150 };
	else if (e->mlx_img.color == F_GREEN)
		e->mlx_img.rgb = (t_rgb) { .r = 150, .g = 255, .b = 150 };
	else if (e->mlx_img.color == F_BLUE)
		e->mlx_img.rgb = (t_rgb) { .r = 150, .g = 150, .b = 255 };
}
