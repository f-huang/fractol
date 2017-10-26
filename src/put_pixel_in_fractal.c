/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_in_fractal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 13:13:11 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/26 18:20:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

void	put_pixel_in_fractal(t_mlx_img *mlx_img, t_offset offset, int i)
{
	t_rgb	rgb;

	ft_bzero(&rgb, sizeof(rgb));
	if (i == mlx_img->fractal.iteration)
		rgb = (t_rgb) { .r = 0x0, .g = 0x0, .b = 0x0 };
	else
		rgb = (t_rgb) { .r = i % 60, .g = i % 100, .b = i % 50 };
	fract_ol_put_pixel_img(mlx_img, offset, rgb);
}
