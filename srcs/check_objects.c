/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:44:47 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/01 14:44:49 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>
int	check_sphere(t_object_list *new_elem, char *str)
{
	int				j;
	int				c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 13)
		return (false);
	new_elem->sphere.position = assign_vectors(str, &j, new_elem->sphere.position);
	new_elem->sphere.direction = (t_vec3){1, 0, 0};
	loop(str, &j);
	new_elem->sphere.radius = atoi_custom(str, &j);
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->sphere.color = col;
	new_elem->sphere.direction = (t_vec3){1, 0, 0};
	transformations(&new_elem->sphere.position, &new_elem->sphere.direction, str, &j);
	return (true);
}

int	check_plan(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 12)
		return (false);
	new_elem->plan.position = assign_vectors(str, &j, new_elem->plan.position);
	new_elem->plan.rotation = (t_vec3){1, 0, 0};
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->plan.color = col;
	transformations(&new_elem->plan.position, &new_elem->plan.rotation, str, &j);
	return (true);
}

int	check_cylindre(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 13)
		return (false);
	new_elem->cylindre.position = assign_vectors(str, &j, new_elem->cylindre.position);
	new_elem->cylindre.direction = (t_vec3){0, 1, 0};
	loop(str, &j);
	new_elem->cylindre.radius = atoi_custom(str, &j);
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->cylindre.color = col;
	transformations(&new_elem->cylindre.position, &new_elem->cylindre.direction, str, &j);
	return (true);
}

int	check_cone(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 13)
		return (false);
	new_elem->cone.position = assign_vectors(str, &j, new_elem->cone.position);
	new_elem->cone.direction = (t_vec3){0, 1, 0};
	loop(str, &j);
	new_elem->cone.radius = atoi_custom(str, &j);
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->cone.color = col;
	transformations(&new_elem->cone.position, &new_elem->cone.direction,str, &j);
	return (true);
}
