/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:44:14 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/03 16:10:43 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_key_func_quat(int keycode, t_data **data)
{
	int i;

	if (keycode == 78)
	{
		i = 0;
		while (i < (*data)->grid->length * (*data)->grid->width)
		{
			(*data)->grid->tab_coordf[i].x *= 0.6;
			(*data)->grid->tab_coordf[i].y *= 0.6;
			i++;
		}
	}
	if (keycode == 4)
	{
		(*data)->grid->coef += 1;
		ft_projection_iso(data);
	}
	if (keycode == 5)
	{
		(*data)->grid->coef -= 1;
		ft_projection_iso(data);
	}
	mlx_clear_window((*data)->mlx_ptr, (*data)->mlx_win);
	display_map(data);
	return (0);
}

int	my_key_func_cinq(int keycode, t_data **data)
{
	int i;

	if (keycode == 125)
	{
		i = 0;
		while (i < (*data)->grid->length * (*data)->grid->width)
		{
			(*data)->grid->tab_coordf[i].y += 100;
			i++;
		}
	}
	if (keycode == 126)
	{
		i = 0;
		while (i < (*data)->grid->length * (*data)->grid->width)
		{
			(*data)->grid->tab_coordf[i].y -= 100;
			i++;
		}
	}
	mlx_clear_window((*data)->mlx_ptr, (*data)->mlx_win);
	display_map(data);
	return (0);
}

int	my_key_func(int keycode, t_data **data)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 83 || keycode == 84 || keycode == 123)
		my_key_func_bis(keycode, data);
	if (keycode == 124 || keycode == 69)
		my_key_func_ter(keycode, data);
	if (keycode == 78 || keycode == 4 || keycode == 5)
		my_key_func_quat(keycode, data);
	if (keycode == 125 || keycode == 126)
		my_key_func_cinq(keycode, data);
	return (0);
}
