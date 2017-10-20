/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_put_pixel_img.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:45:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 16:47:48 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"

void	fract_ol_put_pixel_img(t_mlx_img *img, t_offset offset, t_rgb rgb)
{
	offset.x *= 4;
	if (offset.y < img->height\
		&& offset.x < (unsigned int)img->size_line)
	{
		img->address[offset.y * img->size_line + offset.x] = rgb.b;//((r & 0xff) << 16);
		img->address[offset.y * img->size_line + offset.x + 1] = rgb.g;// ((g & 0xff) << 8);
		img->address[offset.y * img->size_line + offset.x + 2] = rgb.r;//(b & 0xff);
	}
}
