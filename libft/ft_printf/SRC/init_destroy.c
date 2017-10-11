/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 23:31:30 by fhuang            #+#    #+#             */
/*   Updated: 2017/04/17 00:44:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		destroy_ft_printf_env(t_ft_printf_env *e)
{
	t_printf		*link;
	t_printf		*tmp;

	link = e->full_lst;
	while (link)
	{
		tmp = link;
		link = NEXT;
		if (tmp->transformed_str != NULL)
			free(tmp->transformed_str);
		if (tmp != NULL)
			free(tmp);
		ft_bzero(tmp, sizeof(t_printf));
	}
	init_ft_printf_env(e);
}

void		init_ft_printf_env(t_ft_printf_env *e)
{
	e->full_lst = NULL;
	e->arg_lst = NULL;
}
