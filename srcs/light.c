/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:13:09 by gnegri            #+#    #+#             */
/*   Updated: 2018/02/08 10:13:10 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	check_light(t_object_list *new_elem, char *str)
{
	int				j;
	int				c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 8)
		return (false);
	new_elem->light.position = assign_vectors(str, &j, new_elem->light.position);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->light.direction = assign_vectors(str, &j, new_elem->light.direction);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->light.intensity = atoi_custom(str, &j);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->light.color = rgb_to_hex(col.r, col.g, col.b);
	return (true);
}

int init_light(t_object_list *new_elem, char *str)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (false);
	new_elem->light = *light;
	if (check_light(new_elem, str) == false)
	{
		free(light);
		return (false);
	}
	free(light);
	return (true);
}
