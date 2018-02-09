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

int	check_sphere(t_object_list *new_elem, char *str)
{
	int				j;
	int				c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 10)
		return (false);
	new_elem->sphere.position = assign_vectors(str, &j, new_elem->sphere.position);
	loop(str, &j);
	new_elem->sphere.radius = atoi_custom(str, &j);
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->sphere.color = rgb_to_hex(col.r, col.g, col.b);
	transformations(&new_elem->sphere.position, str, &j);
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
	loop(str, &j);
	new_elem->plan.rotation = assign_vectors(str, &j, new_elem->plan.rotation);
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->plan.color = rgb_to_hex(col.r, col.g, col.b);
	transformations(&new_elem->plan.position, str, &j);
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
	loop(str, &j);
	new_elem->cylindre.direction = assign_vectors(str, &j, new_elem->cylindre.direction);
	loop(str, &j);
	new_elem->cylindre.radius = atoi_custom(str, &j);
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->cylindre.color = rgb_to_hex(col.r, col.g, col.b);
	transformations(&new_elem->cylindre.position, str, &j);
	return (true);
}

int	check_cone(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 14)
		return (false);
	new_elem->cone.position = assign_vectors(str, &j, new_elem->cone.position);
	loop(str, &j);
	new_elem->cone.direction = assign_vectors(str, &j, new_elem->cone.direction);
	loop(str, &j);
	new_elem->cone.radius = atoi_custom(str, &j);
	loop(str, &j);
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->cone.color = rgb_to_hex(col.r, col.g, col.b);
	transformations(&new_elem->cone.position, str, &j);
	return (true);
}
