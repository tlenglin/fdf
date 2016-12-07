/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 09:12:09 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/06 11:22:24 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_draw_line1_bis(t_calc **calc, t_data *data, int i, int k)
{
	int j;
	int x;
	int y;

	j = 1;
	x = data->grid->tab_coordf[i].x;
	y = data->grid->tab_coordf[i].y;
	(*calc)->cumul = (*calc)->dx / 2;
	while (j <= (*calc)->dx)
	{
		x += (*calc)->xinc;
		(*calc)->cumul += (*calc)->dy;
		if ((*calc)->cumul >= (*calc)->dx)
		{
			(*calc)->cumul -= (*calc)->dx;
			y += (*calc)->yinc;
		}
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, 800 + x, 200 + y,
			ft_color(data, i, k, j));
		j++;
	}
	return (0);
}

int	ft_draw_line1_ter(t_calc **calc, t_data *data, int i, int k)
{
	int j;
	int x;
	int y;

	j = 1;
	x = data->grid->tab_coordf[i].x;
	y = data->grid->tab_coordf[i].y;
	(*calc)->cumul = (*calc)->dy / 2;
	while (j <= (*calc)->dy)
	{
		y += (*calc)->yinc;
		(*calc)->cumul += (*calc)->dx;
		if ((*calc)->cumul >= (*calc)->dy)
		{
			(*calc)->cumul -= (*calc)->dy;
			x += (*calc)->xinc;
		}
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, 800 + x, 200 + y,
			ft_color(data, i, k, j));
		j++;
	}
	return (0);
}

int	ft_draw_line1(t_data *data, int i, int k)
{
	t_calc	*calc;
	int		j;

	j = 1;
	if (!(calc = ft_memalloc(sizeof(t_calc))))
		return (0);
	calc->dx = data->grid->tab_coordf[k].x - data->grid->tab_coordf[i].x;
	calc->dy = data->grid->tab_coordf[k].y - data->grid->tab_coordf[i].y;
	calc->xinc = (calc->dx >= 0) ? 1 : -1;
	calc->yinc = (calc->dy >= 0) ? 1 : -1;
	calc->dx = (calc->dx >= 0) ? calc->dx : -calc->dx;
	calc->dy = (calc->dy >= 0) ? calc->dy : -calc->dy;
	if (calc->dx >= calc->dy)
		ft_draw_line1_bis(&calc, data, i, k);
	else
		ft_draw_line1_ter(&calc, data, i, k);
	free(calc);
	calc = NULL;
	return (1);
}

int	display_map(t_data **data)
{
	int	i;

	i = 0;
	ft_instructions(data);
	while (i < (*data)->grid->length * (*data)->grid->width)
	{
		if ((i + 1) % (*data)->grid->width != 0)
		{
			ft_draw_line1(*data, i, i + 1);
		}
		if (i < ((*data)->grid->length - 1) * (*data)->grid->width)
		{
			ft_draw_line1(*data, i, i + (*data)->grid->width);
		}
		i++;
	}
	return (1);
}
