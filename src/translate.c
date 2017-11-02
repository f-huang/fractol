/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 11:10:31 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 14:18:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

#define GET_TRANSLATE(x) 150 / x

void	translate_left(t_env *e)
{
	e->fractals[e->index].
		abscissa.min -= GET_TRANSLATE(e->fractals[e->index].zoom);
	e->fractals[e->index].
		abscissa.max -= GET_TRANSLATE(e->fractals[e->index].zoom);
}

void	translate_right(t_env *e)
{
	e->fractals[e->index].
		abscissa.min += GET_TRANSLATE(e->fractals[e->index].zoom);
	e->fractals[e->index].
		abscissa.max += GET_TRANSLATE(e->fractals[e->index].zoom);
}

void	translate_up(t_env *e)
{
	e->fractals[e->index].
		ordinate.min -= GET_TRANSLATE(e->fractals[e->index].zoom);
	e->fractals[e->index].
		ordinate.max -= GET_TRANSLATE(e->fractals[e->index].zoom);
}

void	translate_down(t_env *e)
{
	e->fractals[e->index].
		ordinate.min += GET_TRANSLATE(e->fractals[e->index].zoom);
	e->fractals[e->index].
		ordinate.max += GET_TRANSLATE(e->fractals[e->index].zoom);
}
