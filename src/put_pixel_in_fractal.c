/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_in_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:13:11 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/21 13:13:30 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

void	put_pixel_in_fractal(t_mlx_img *mlx_img, t_offset offset, double i)
{
	t_rgb	rgb;

	ft_bzero(&rgb, sizeof(rgb));
	if (i == mlx_img->fractal.iteration)
		rgb = (t_rgb) { .r = 0x0, .g = 0x0, .b = 0x0 };
	else
	{
		if (i >= 200)//#2df909
			rgb = (t_rgb) { .r = 0xee, .g = 0x58, .b = 0x59 };
		else if (i > 50 && i < 200)//#3f9630
			rgb = (t_rgb) { .r = 0x3f, .g = 0x96, .b = 0x30 };
		else if (i > 5)//#c4f2bc
			rgb = (t_rgb) { .r = 0xf0, .g = 0xf0, .b = 0xf0 };
		else
			rgb = (t_rgb) { .r = 0xce, .g = 0xc3, .b = 0xa7 };
	}
	fract_ol_put_pixel_img(mlx_img, offset, rgb);
}
