/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_name_to_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 18:53:24 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/19 18:59:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

enum e_fractal_type	fract_ol_name_to_type(const char *name)
{
	int		i;

	i = 0;
	while (i < NB_FRACTALS)
	{
		if (!ft_strcmp(name, get_fractal_type_name((enum e_fractal_type)i)))
			return (i);
		++i;
	}
	return (-1);
}
