/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 22:48:56 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/12 02:30:45 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		new_link(t_ft_printf_env *e, char *str, char *type, bool arg)
{
	t_printf		*new;

	if (!(new = (t_printf*)ft_memalloc(sizeof(t_printf))))
		exit(EXIT_FAILURE);
	if (arg == false)
	{
		if ((new->transformed_str = ft_strndup(str, (int)(type - str))) == NULL)
			exit(EXIT_FAILURE);
		new->len = ft_strlen(new->transformed_str);
	}
	else
	{
		if ((get_struct(new, str, *type, -1)) == -1)
			return (-1);
	}
	add_link(e, new, arg);
	return (0);
}
