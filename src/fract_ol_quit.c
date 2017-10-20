/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_quit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 10:34:36 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 11:34:57 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include "fract_ol.h"

void	fract_ol_quit(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	ft_strdel(&e->mlx_img.address);
	exit(EXIT_SUCCESS);
}
