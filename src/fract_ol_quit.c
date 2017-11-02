/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:34:36 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 13:49:17 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "fract_ol.h"

void	fract_ol_quit(t_env *e)
{
	ft_memdel((void**)&e->fractals);
	mlx_destroy_window(e->mlx, e->win);
	exit(EXIT_SUCCESS);
}
