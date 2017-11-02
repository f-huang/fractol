/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:31:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 11:52:23 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"
#include "X11/X.h"
#include <stdio.h>

#define WINDOW_NAME "fract_ol"

int		main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if (ac < 2)
		return (-fract_ol_error("Not enough parameters"));
	if (!init(&e, (const char**)av))
		return (-fract_ol_error("Wrong parameters")); // TODO: Change error output
	if (!(e.mlx = mlx_init()))
		return (-fract_ol_error("Could not init mlx."));
	if (!(e.win = mlx_new_window(e.mlx, IMAGE_SIZE, IMAGE_SIZE, WINDOW_NAME)))
		return (-fract_ol_error("Could not create a new window."));
	if (!fract_ol_create_image(&e))
		return (-fract_ol_error("An error occured during the image creation."));
	mlx_hook(e.win, ButtonPress, ButtonPressMask, fract_ol_mouse_hook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, fract_ol_key_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, fract_ol_motion_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
