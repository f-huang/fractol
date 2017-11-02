/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 23:31:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 19:01:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"
#include "X11/X.h"

#define WINDOW_NAME "fract_ol"
#define _FRACTALS_ "\033[1mNAMES\033[0m\n\tMandelbrot\n\tJulia\n\tBurning_ship"
#define ERROR_PARAMETERS "usage: fract_ol name ...\n\n"_FRACTALS_

#define ERROR_MLX_INIT "mlx: count not init"
#define ERROR_MLX_WINDOW "mlx: could not create a new window"
#define ERROR_MLX_IMAGE "mlx: could not create a new image"

static int	fract_ol_error(const char *str)
{
	ft_putendl_fd(str, 2);
	return (-1);
}

int			main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if (ac < 2 || !init(&e, (const char**)av))
		return (-fract_ol_error(ERROR_PARAMETERS));
	if (!(e.mlx = mlx_init()))
		return (-fract_ol_error(ERROR_MLX_INIT));
	if (!(e.win = mlx_new_window(e.mlx, IMAGE_SIZE, IMAGE_SIZE, WINDOW_NAME)))
		return (-fract_ol_error(ERROR_MLX_WINDOW));
	if (!fract_ol_create_image(&e))
		return (-fract_ol_error(ERROR_MLX_IMAGE));
	mlx_hook(e.win, ButtonPress, ButtonPressMask, fract_ol_mouse_hook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, fract_ol_key_hook, &e);
	mlx_hook(e.win, MotionNotify, PointerMotionMask, fract_ol_motion_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
