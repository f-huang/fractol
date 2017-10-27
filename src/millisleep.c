/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   millisleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:51:24 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/27 13:51:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

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
