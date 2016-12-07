/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:27:11 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/06 12:05:17 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fill_length_width(t_data **data, char *file)
{
	int i;
	int count;
	int k;

	count = 1;
	i = 0;
	while (file[i])
	{
		while (file[i] != '\n' && file[i])
		{
			i++;
		}
		if (file[i] == '\n' && file[i])
		{
			if ((k = width_grid(data, file, i)) == 0)
				return (0);
			count++;
			i++;
		}
	}
	if (file[i - 1] == '\n')
		count--;
	(*data)->grid->length = count;
	return (k);
}

int	fill_grid_bis(t_data **data, char *f, int i, int count)
{
	while (f[i])
	{
		while (f[i] == ' ' && f[i])
			i++;
		if (f[i] != '\0' && f[i] != '\n' && !((f[i] <= '9' && f[i] >= '0')
		|| f[i] == '-'))
			return (0);
		else if (((f[i] <= '9' && f[i] >= '0') || f[i] == '-') && f[i])
		{
			if (!(fill_coord(f, data, i++)))
				return (0);
			while ((f[i] <= '9' && f[i] >= '0') || f[i] == '-')
				i++;
			count++;
		}
		else if (f[i] == '\n' || f[i] == '\0')
		{
			if (count % (*data)->grid->width != 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int	fill_grid(t_data **data, char *file)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if ((fill_length_width(data, file)) == 0)
		return (0);
	if (!((*data)->grid->tab_coord = ft_memalloc(sizeof(t_coord) *
	(*data)->grid->length * (*data)->grid->width)))
		return (0);
	if (!(fill_grid_bis(data, file, i, count)))
		return (0);
	return (1);
}
