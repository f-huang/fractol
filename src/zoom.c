/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 10:54:52 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/21 11:00:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

void	zoom_in(t_env *e, int x, int y)
{
	double	x_percent_in_win;
	double	y_percent_in_win;
	double	new_width;
	double	new_height;

	e->mlx_img.fractal.iteration *= 1.1;
	e->mlx_img.fractal.zoom *= 1.5;
	x_percent_in_win = x / e->mlx_img.width;
	new_width = e->mlx_img.width / e->mlx_img.fractal.zoom;
	e->mlx_img.fractal.abscissa.min = x_percent_in_win * get_distance(\
		e->mlx_img.fractal.abscissa.max, e->mlx_img.fractal.abscissa.min) -\
		ft_abs(e->mlx_img.fractal.abscissa.min) - x_percent_in_win * new_width;
	e->mlx_img.fractal.abscissa.max = e->mlx_img.fractal.abscissa.min + new_width;

	y_percent_in_win = y / e->mlx_img.height;
	new_height = e->mlx_img.height / e->mlx_img.fractal.zoom;
	e->mlx_img.fractal.ordinate.min = y_percent_in_win * get_distance(\
		e->mlx_img.fractal.ordinate.max, e->mlx_img.fractal.ordinate.min) -\
		ft_abs(e->mlx_img.fractal.ordinate.min) - y_percent_in_win * new_height;
	e->mlx_img.fractal.ordinate.max = e->mlx_img.fractal.ordinate.min + new_height;
}
