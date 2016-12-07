/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:07:57 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/06 15:06:52 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_instructions(t_data **data)
{
	mlx_string_put((*data)->mlx_ptr, (*data)->mlx_win, 35, 35, TEXT_COLOR,
	"isometrie = 1");
	mlx_string_put((*data)->mlx_ptr, (*data)->mlx_win, 35, 55, TEXT_COLOR,
	"parallele = 2");
	mlx_string_put((*data)->mlx_ptr, (*data)->mlx_win, 35, 75, TEXT_COLOR,
	"deplacement = up, down, left, right");
	mlx_string_put((*data)->mlx_ptr, (*data)->mlx_win, 35, 95, TEXT_COLOR,
	"zoom = +, -");
	mlx_string_put((*data)->mlx_ptr, (*data)->mlx_win, 35, 115, TEXT_COLOR,
	"altitude = h, g");
	return (0);
}

int	display_management(t_data **data)
{
	int bpp;
	int sizeline;
	int endian;

	bpp = 16;
	sizeline = 2000 * bpp / 8;
	endian = 1;
	if (!((*data)->mlx_ptr = mlx_init()))
		return (0);
	if (!((*data)->mlx_win = mlx_new_window((*data)->mlx_ptr, 2000, 1300,
	"FdF")))
		return (0);
	if (!((*data)->img_ptr = mlx_new_image((*data)->mlx_ptr, 2000, 1300)))
		return (0);
	mlx_expose_hook((*data)->mlx_win, display_map, data);
	mlx_key_hook((*data)->mlx_win, my_key_func, data);
	mlx_loop((*data)->mlx_ptr);
	return (1);
}

int	ft_color_bis(int coef)
{
	coef = -coef * 2;
	if (coef < -3 * 255)
		return (0x0000FF);
	else if (coef < -2 * 255 && coef >= -3 * 255)
		return (0x00FFFF - (coef * -1 - 2 * 255) * 256);
	else if (coef < -1 * 255 && coef >= -2 * 255)
		return (0x00FF00 + (coef * -1 - 1 * 255));
	else if (coef < 0 && coef >= -1 * 255)
		return (0xFFFF00 + (coef) * 256 * 256);
	else if (coef < 1 * 256 && coef >= 0)
		return (0xFFFF00 - 256 * coef);
	else if (coef < 2 * 256 && coef >= 1 * 256)
		return (0xFF0000 + coef - 256);
	else if (coef < 3 * 256 && coef >= 2 * 256)
		return (0xFF00FF + (coef - 2 * 256) * 256);
	else
		return (0xFFFFFF);
}

int	ft_color(t_data *data, int i, int k, int j)
{
	int res;
	int dx;
	int dy;

	dx = data->grid->tab_coordf[k].x - data->grid->tab_coordf[i].x;
	dy = data->grid->tab_coordf[k].y - data->grid->tab_coordf[i].y;
	dx = (dx >= 0) ? dx : -dx;
	dy = (dy >= 0) ? dy : -dy;
	if (dx >= dy)
	{
		res = ft_color_bis(data->grid->tab_coord[i].z * 10 + j * 10 *
		(data->grid->tab_coord[k].z - data->grid->tab_coord[i].z) / (dx));
	}
	else
	{
		res = ft_color_bis(data->grid->tab_coord[i].z * 10 + j * 10 *
		(data->grid->tab_coord[k].z - data->grid->tab_coord[i].z) / (dy));
	}
	return (res);
}
