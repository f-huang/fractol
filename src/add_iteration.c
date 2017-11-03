/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_iteration.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:37:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 14:40:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	add_iteration(t_env *e)
{
	if (e->fractals[e->index].iteration < MAX_ITERATIONS)
		e->fractals[e->index].iteration += 25;
}
