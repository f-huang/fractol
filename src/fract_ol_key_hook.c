/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_key_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 23:07:06 by fhuang            #+#    #+#             */
/*   Updated: 2017/04/22 15:29:39 by FannyHuang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

enum	e_key_hook
{
	ESC = 53
};

int		fract_ol_key_hook(int keycode, void *param)
{
	(void)param;
	ft_printf("keycode: %i\n", keycode);
	return (0);
}
