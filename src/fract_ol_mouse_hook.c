/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol_mouse_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 21:02:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/26 20:30:57 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include <stdio.h>
#include "mlx.h"
#include "fract_ol.h"
#include "libft.h"

long long	 get_timestamp(void)
{
	struct timespec	spec;
	long long		ret;

	clock_gettime(CLOCK_REALTIME, &spec);
	ret = spec.tv_sec * 1000LL + spec.tv_nsec / 1000000LL;
	return (ret);
}

void		millisleep(int milliseconds)
{
	struct timespec	spec;

	if (milliseconds < 0)
		return ;
	spec = (struct timespec) {
		.tv_sec = milliseconds / 1000,
		.tv_nsec = (milliseconds % 1000) * 1000000
	};
	nanosleep(&spec, NULL);
}

int		fract_ol_mouse_hook(int button_code, int x, int y, t_env *e)
{
	static void		((*button_actions[])(t_env *e, int x, int y)) = {
		[SCROLL_WHEEL_ZOOM_IN] = zoom_in,
		[SCROLL_WHEEL_ZOOM_OUT] = zoom_out
	};
	static long long		start_rendering = 0;

	if (x > 0 && y > 0 && (button_code == SCROLL_WHEEL_ZOOM_IN
		|| button_code == SCROLL_WHEEL_ZOOM_OUT))
	{
		start_rendering = get_timestamp();
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_image(e->mlx, e->mlx_img.img);
		button_actions[button_code](e, x, y);
		fract_ol_create_image(e);
		printf("%lld\n", get_timestamp() - start_rendering);
		millisleep(start_rendering + 1000 / FPS - get_timestamp());
	}
	return (0);
}
