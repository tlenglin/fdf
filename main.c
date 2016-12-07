/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:50:02 by tlenglin          #+#    #+#             */
/*   Updated: 2016/12/06 15:41:05 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fill_file(char *buffer, char **file)
{
	char *tmp;

	if (!(tmp = ft_strjoin(*file, buffer)))
		return (0);
	free(*file);
	*file = NULL;
	if (!(*file = ft_strdup(tmp)))
		return (0);
	free(tmp);
	tmp = NULL;
	return (1);
}

int	ft_algo(t_data **data, char *file)
{
	int i;

	i = 0;
	if (!(fill_grid(data, file)))
		return (0);
	if ((*data)->grid->coef == 0)
		(*data)->grid->coef = 1;
	if (!(ft_projection_iso(data)))
		return (0);
	if (!(display_management(data)))
		return (0);
	return (1);
}

int	ft_usage(int argc, int error)
{
	if (error == 0)
	{
		if (argc != 2)
			write(2, "usage: fdf input_file\n", 22);
		return (0);
	}
	else
	{
		write(2, "error\n", 6);
		return (0);
	}
}

int	ft_free_all(t_data **data, char **buffer, char **file)
{
	free((*data)->grid->tab_coord);
	free((*data)->grid->tab_coord);
	free((*data)->grid);
	free(*data);
	free(*file);
	free(*buffer);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*buffer;
	t_data	*data;
	char	*file;
	int		ret;

	if (!(data = ft_memalloc(sizeof(t_data))) || argc != 2)
		return (ft_usage(argc, 0));
	if (!(data->grid = ft_memalloc(sizeof(t_grid))))
		return (ft_usage(argc, 1));
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_usage(argc, 1));
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (ft_usage(argc, 1));
	if (!(file = ft_strnew(BUFF_SIZE)))
		return (ft_usage(argc, 1));
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (!(fill_file(buffer, &file)))
			return (ft_usage(argc, 1));
	}
	if (ft_algo(&data, file) == 0)
		return (ft_usage(argc, 1));
	ft_free_all(&data, &buffer, &file);
	return (1);
}
