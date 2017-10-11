/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entire_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 15:57:02 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/25 18:47:03 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		total_len(t_ft_printf_env *e, size_t *len)
{
	t_printf		*link;

	*len = 0;
	link = e->full_lst;
	while (link != NULL)
	{
		*len += LEN;
		link = NEXT;
	}
}

static char		*final_string(t_ft_printf_env *e, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;
	t_printf		*link;

	if ((str = ft_strnew(len)) == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	link = e->full_lst;
	while (link)
	{
		j = 0;
		while (j < (size_t)LEN && i < len)
			str[i++] = RET[j++];
		link = NEXT;
	}
	return (str);
}

int				print_entire_list(t_ft_printf_env *e, int fd)
{
	size_t		len;
	char		*str;

	total_len(e, &len);
	str = final_string(e, len);
	write(fd, str, len);
	ft_strdel(&str);
	return (len);
}
