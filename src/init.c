/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 10:23:32 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 10:35:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fract_ol.h"

static int	is_type_already_present(t_fractal *fractals, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		if (index != i && fractals[i].type == fractals[index].type)
			return (1);
		++i;
	}
	return (0);
}

static int	get_number_of_fractals(const char **av)
{
	int		i;
	int		j;
	int		total;

	total = 0;
	i = 1;
	while (av[i])
	{
		if ((int)(get_fractal_type(av[i])) == -1)
			return (-1);
		j = i + 1;
		while (av[j])
		{
			if (ft_strequ(av[i], av[j]))
			{
				--total;
				break ;
			}
			++j;
		}
		++i;
		++total;
	}
	return (total);
}

int			init(t_env *e, const char **av)
{
	int		i;
	int		j;

	if ((e->number_of_fractals = get_number_of_fractals(av)) == -1 ||
	!(e->fractals = ft_memalloc(sizeof(t_fractal) * (e->number_of_fractals))))
		return (0);
	e->mlx_img.size = IMAGE_SIZE;
	i = 0;
	j = 0;
	while (av[++i] && j < e->number_of_fractals)
	{
		e->fractals[j].type = get_fractal_type(av[i]);
		if (!is_type_already_present(e->fractals, j))
		{
			init_fractal_parameters(e->fractals + j);
			++j;
		}
	}
	e->mlx_img.color = F_RED;
	e->screen_cut_size = e->mlx_img.size / NB_THREADS +\
		((int)e->mlx_img.size % NB_THREADS ? 1 : 0);
	e->nb_screen_cut = e->mlx_img.size / e->screen_cut_size +\
		((int)e->mlx_img.size % e->screen_cut_size ? 1 : 0);
	return (1);
}
