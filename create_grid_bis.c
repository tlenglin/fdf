/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:09:02 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/05 19:54:14 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	width_grid(t_data **data, char *file, int i)
{
	int	count;
	int	j;

	j = i - 1;
	count = 0;
	while (file[j] != '\n' && j >= 0)
	{
		while (file[j] == ' ' && file[j] != '\n' && j >= 0)
			j--;
		if (file[j] != '\n' && j >= 0 && file[j] != ' ')
		{
			while (file[j] != '\n' && j >= 0 && file[j] != ' ')
				j--;
			count++;
		}
	}
	if ((*data)->grid->width != 0)
	{
		if ((*data)->grid->width != count)
			return (0);
	}
	else
		(*data)->grid->width = count;
	return (i);
}

int	fill_coord_bis(t_data **data, int res)
{
	int	i;

	i = 0;
	while ((*data)->grid->tab_coord[i].x != 0 && (*data)->grid->tab_coord[i].y
	!= 0)
	{
		i++;
	}
	if (i == (((*data)->grid->width + 1) * (*data)->grid->length + 1) + 1)
	{
		return (0);
	}
	(*data)->grid->tab_coord[i].x = (i % (*data)->grid->width) + 1;
	(*data)->grid->tab_coord[i].y = (i / (*data)->grid->width) + 1;
	(*data)->grid->tab_coord[i].z = -res;
	return (1);
}

int	fill_coord(char *file, t_data **data, int i)
{
	int		j;
	char	*tmp;
	int		res;
	int		res2;
	int		k;

	j = i;
	while ((file[j] <= '9' && file[j] >= '0') || file[j] == '-')
		j++;
	if (!(tmp = ft_strsub(file, i, j - i)))
		return (0);
	res = ft_atoi(tmp);
	free(tmp);
	k = (res < 0) ? 2 : 1;
	res2 = res;
	while (res2 /= 10)
		k++;
	if (k != j - i)
		return (0);
	fill_coord_bis(data, res);
	return (1);
}
