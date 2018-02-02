/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:10:09 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/31 17:10:12 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <stdio.h>

static t_object_list	*new_list_object(t_map *map, char *str, int object, int object_nb)
{
	t_object_list	*new_elem;

	new_elem = NULL;
	new_elem = (t_object_list*)malloc(sizeof(t_object_list));
	if ((new_elem) == NULL)
		return (new_elem);
	new_elem->type = object;
	new_elem->object_nb = object_nb;
	new_elem->next = NULL;
	if (init_object(map, new_elem, str, object) == false)
		return (NULL);
	return (new_elem);
}

static int				new_list(t_map *map, char *str, int i, int nb_object)
{
	t_object_list *tmp;
	
	if (!map->list)
	{
		if ((map->list = new_list_object(map, str, i, nb_object)) == NULL)
			return (-1);
		return (0);
	}
	else
		tmp = map->list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_list_object(map, str, i, nb_object);
	return (0);
}

static int				check_first_char(t_map *map, int i)
{
	int	j;

	j = 0;
	j = skip_space(map->content[i], j);
	if (map->content[i][j] < 'A' || map->content[i][j] > 'Z')
		return (false);
	return (true);
}

static int				check_cam(t_cam *cam, char *str)
{
	int		j;
	int		c;

	j = 0;
	if ((c = count_int(str)) != 7)
		return (false);
	cam->cam_pos = assign_vectors(str, &j, cam->cam_pos);
	while (str[j] < '0' || str[j] > '9')
		j++;
	cam->view_dir = assign_vectors(str, &j, cam->view_dir);
	while (str[j] < '0' || str[j] > '9')
		j++;
	cam->screen_dist = atoi_custom(str, &j);
	return (true);
}

int						init_data(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;
	int		nb_object;

	i = 0;
	nb_object = 0;
	while (i < map->nb_line)
	{	
		while (check_first_char(map, i) != true && i < map->nb_line)
			i++;
		j = skip_space(map->content[i], 0);
		if (read_first_letters(map->content[i], j) == CAM)
		{
			if (check_cam(mlx->cam, map->content[i]) == false)
				return (false);
		}
		else if (read_first_letters(map->content[i], j) != 0
			&& read_first_letters(map->content[i], j) != CAM)
		{
			if (new_list(map, map->content[i], read_first_letters(map->content[i], j), nb_object) != 0)
				return (-1);
			else
				nb_object++;
		}
		i++;
	}
	printf("%f ", map->list->sphere.position.x);
	printf("%f ", map->list->sphere.position.y);
	printf("%f\n", map->list->sphere.position.z);
	printf("%f\n", map->list->sphere.radius);
	return (true);
}
