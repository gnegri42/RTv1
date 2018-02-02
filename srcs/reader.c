/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:47:15 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/31 10:47:24 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int init_object(t_map *map, t_object_list *new_elem, char *str, int o)
{
	int i;

	i = 0;
	if (o == 14)
		i = init_sphere(map, new_elem, str);
/*	
	if (o == PLA)
		i = init_plan(map, new_elem, str);
	if (o == LIG)
		i = init_light(map, new_elem, str);
	if (o == CYL)
		i = init_cylindre(map, new_elem, str);
	if (o == CON)
		i = init_cone(map, new_elem, str);
*/
	return (i);
}

static int	ft_verifs(int fd, t_map *map, char *line)
{
	if (get_next_line(fd, &line) < 0)
	{
		ft_putstr("Error : unable to read any content.\n");
		free(map->str);
		free(map->content);
		return (-1);
	}
	if (close(fd) == -1)
	{
		free(map->str);
		free(map->content);
		return (-1);
	}
	if (map->str[0] == '\0')
	{
		ft_putstr("Error: file is empty.\n");
		return (-1);
	}
	return (0);
}

static int	ft_check_read(int argc, char *argv, int *fd)
{
	if (argc != 2)
	{
		ft_putstr("Usage: ./rtv1 [input_file]\n");
		return (-1);
	}
	if ((*fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("Error : bad_file.\n");
		close(*fd);
		return (-1);
	}
	return (0);
}

int			ft_reader(int argc, char *argv, t_map *map)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;

	map->str = ft_strnew(1);
	if (ft_check_read(argc, argv, &fd) != 0)
		return (-1);
	map->nb_line = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tmp = map->str;
		tmp2 = ft_strjoin(tmp, line);
		map->str = ft_strjoin(tmp2, "\n");
		free(tmp);
		free(tmp2);
		map->nb_line++;
		free(line);
	}
	map->content = ft_strsplit(map->str, '\n');
	if (ft_verifs(fd, map, line) != 0)
		return (-1);
	return (0);
}
