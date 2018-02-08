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
	t_vec3			translation;

	j = 0;
	if ((c = count_int(str)) != 10)
		return (false);
	new_elem->sphere.position = assign_vectors(str, &j, new_elem->sphere.position);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->sphere.radius = atoi_custom(str, &j);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->sphere.color = rgb_to_hex(col.r, col.g, col.b);
	while (str[j] < '0' || str[j] > '9')
		j++;
	translation = (t_vec3){0, 0, 0};
	translation = assign_vectors(str, &j, translation);
	new_elem->sphere.position = ft_translation(new_elem->sphere.position, translation);
	return (true);
}

int	check_plan(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 9)
		return (false);
	new_elem->plan.position = assign_vectors(str, &j, new_elem->plan.position);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->plan.rotation = assign_vectors(str, &j, new_elem->plan.rotation);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->plan.color = rgb_to_hex(col.r, col.g, col.b);
	return (true);
}

int	check_cylindre(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 10)
		return (false);
	new_elem->cylindre.position = assign_vectors(str, &j, new_elem->cylindre.position);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->cylindre.direction = assign_vectors(str, &j, new_elem->cylindre.direction);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->cylindre.radius = atoi_custom(str, &j);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->cylindre.color = rgb_to_hex(col.r, col.g, col.b);
	return (true);
}

int	check_cone(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 10)
		return (false);
	new_elem->cone.position = assign_vectors(str, &j, new_elem->cone.position);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->cone.direction = assign_vectors(str, &j, new_elem->cone.direction);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->cone.radius = atoi_custom(str, &j);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->cone.color = rgb_to_hex(col.r, col.g, col.b);
	return (true);
}
