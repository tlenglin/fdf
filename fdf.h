/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:50:28 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/06 15:41:17 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFF_SIZE 1
# define CT1 0.7
# define CT2 0.7
# define CT 0.5
# define TEXT_COLOR 0xFFFFFF

typedef struct	s_calc
{
	int xinc;
	int yinc;
	int dx;
	int dy;
	int cumul;
}				t_calc;

typedef struct	s_coord
{
	int	x;
	int	y;
	int	z;
}				t_coord;

typedef struct	s_coordf
{
	float	x;
	float	y;
}				t_coordf;

typedef struct	s_grid
{
	int			length;
	int			width;
	int			coef;
	t_coord		*tab_coord;
	t_coordf	*tab_coordf;
}				t_grid;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	char	*img;
	t_grid	*grid;
}				t_data;

int				width_grid(t_data **data, char *file, int i);
int				fill_coord(char *file, t_data **data, int i);
int				fill_length_width(t_data **data, char *file);
int				fill_grid(t_data **data, char *file);
int				fill_file(char *buffer, char **file);
int				display_management(t_data **data);
int				display_map(t_data **data);
int				ft_projection_iso(t_data **data);
int				ft_projection_par(t_data **data);
int				my_key_func(int keycode, t_data **data);
int				ft_draw_line1(t_data *data, int i, int j);
int				ft_color(t_data *data, int i, int k, int j);
int				ft_instructions(t_data **data);
int				fill_grid_bis(t_data **data, char *file, int i, int count);
int				ft_draw_line1_bis(t_calc **calc, t_data *data, int i, int k);
int				ft_draw_line1_ter(t_calc **calc, t_data *data, int i, int k);
int				my_key_func_bis(int keycode, t_data **data);
int				my_key_func_ter(int keycode, t_data **data);
int				my_key_func_quat(int keycode, t_data **data);
int				my_key_func_cinq(int keycode, t_data **data);
int				ft_algo(t_data **data, char *file);
int				ft_usage(int argc, int error);
int				ft_color_bis(int coef);
int				ft_free_all(t_data **data, char **buffer, char **file);
int				end_of_file(t_data **data, char *file, int i);

#endif
