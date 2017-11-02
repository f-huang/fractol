/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fractal_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:53:24 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 11:08:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

enum e_fractal_type	get_fractal_type(const char *name)
{
	int		i;

	i = 0;
	while (i < NB_FRACTALS)
	{
		if (ft_strequ(name, get_fractal_name((enum e_fractal_type)i)))
			return (i);
		++i;
	}
	return (-1);
}
