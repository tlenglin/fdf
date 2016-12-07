/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:10:13 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/03 16:10:39 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_projection_iso(t_data **data)
{
	int i;

	i = 0;
	if (!((*data)->grid->tab_coordf = ft_memalloc(sizeof(t_coord) *
	(*data)->grid->length * (*data)->grid->width)))
		return (0);
	while (i < (*data)->grid->length * (*data)->grid->width)
	{
		(*data)->grid->tab_coordf[i].x = CT1 *
		(float)(*data)->grid->tab_coord[i].x * 50 - CT2 *
		(float)(*data)->grid->tab_coord[i].y * 50;
		(*data)->grid->tab_coordf[i].y = (float)(*data)->grid->tab_coord[i].z *
		0.1 * 50 * (*data)->grid->coef + CT1 / 2 *
		(float)(*data)->grid->tab_coord[i].x * 50 + CT2 / 2 *
		(float)(*data)->grid->tab_coord[i].y * 50;
		i++;
	}
	return (1);
}

int	ft_projection_par(t_data **data)
{
	int i;

	i = 0;
	if (!((*data)->grid->tab_coordf = ft_memalloc(sizeof(t_coord) *
	(*data)->grid->length * (*data)->grid->width)))
		return (0);
	while (i < (*data)->grid->length * (*data)->grid->width)
	{
		(*data)->grid->tab_coordf[i].x = (float)(*data)->grid->tab_coord[i].x
		* 50 + CT * (float)(*data)->grid->tab_coord[i].z * 0.1 * 50 *
		(*data)->grid->coef;
		(*data)->grid->tab_coordf[i].y = (float)(*data)->grid->tab_coord[i].y *
		50 + CT / 2 * (float)(*data)->grid->tab_coord[i].z * 0.1 * 50 *
		(*data)->grid->coef;
		i++;
	}
	return (1);
}

int	my_key_func_bis(int keycode, t_data **data)
{
	int i;

	if (keycode == 53)
		exit(0);
	if (keycode == 83)
		ft_projection_iso(data);
	if (keycode == 84)
		ft_projection_par(data);
	if (keycode == 123)
	{
		i = 0;
		while (i < (*data)->grid->length * (*data)->grid->width)
		{
			(*data)->grid->tab_coordf[i].x -= 100;
			i++;
		}
	}
	mlx_clear_window((*data)->mlx_ptr, (*data)->mlx_win);
	display_map(data);
	return (0);
}

int	my_key_func_ter(int keycode, t_data **data)
{
	int i;

	i = 0;
	if (keycode == 124)
	{
		while (i < (*data)->grid->length * (*data)->grid->width)
		{
			(*data)->grid->tab_coordf[i].x += 100;
			i++;
		}
	}
	if (keycode == 69)
	{
		while (i < (*data)->grid->length * (*data)->grid->width)
		{
			(*data)->grid->tab_coordf[i].x *= 1.5;
			(*data)->grid->tab_coordf[i].y *= 1.5;
			i++;
		}
	}
	mlx_clear_window((*data)->mlx_ptr, (*data)->mlx_win);
	display_map(data);
	return (0);
}
