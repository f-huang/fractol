/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:52:12 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/09 18:52:16 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		arglst_add(t_printf **lst, t_printf *new)
{
	t_printf		*link;

	if (*lst)
	{
		link = *lst;
		while (NEXT_ARG)
			link = NEXT_ARG;
		NEXT_ARG = new;
	}
	else
		*lst = new;
}

void			add_link(t_ft_printf_env *e, t_printf *new, bool arg)
{
	t_printf		*link;
	t_printf		**lst;

	new->next = NULL;
	new->next_arg = NULL;
	lst = &e->full_lst;
	if (*lst)
	{
		link = *lst;
		while (NEXT)
			link = NEXT;
		NEXT = new;
	}
	else
		*lst = new;
	if (arg)
		arglst_add(&e->arg_lst, new);
}
