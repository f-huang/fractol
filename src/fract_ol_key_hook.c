/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_key_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 23:07:06 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/20 13:32:28 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

int		fract_ol_key_hook(int keycode, t_env *e)
{
	static void		((*key_actions[])(t_env *)) = {
		[ESC] = fract_ol_quit
	};

	ft_printf("keycode: %i\n", keycode);
	if (keycode == ESC)
		key_actions[keycode](e);
	return (0);
}
