/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:50:53 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/27 13:51:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

long long	 get_timestamp(void)
{
	struct timespec	spec;
	long long		ret;

	clock_gettime(CLOCK_REALTIME, &spec);
	ret = spec.tv_sec * 1000LL + spec.tv_nsec / 1000000LL;
	return (ret);
}
