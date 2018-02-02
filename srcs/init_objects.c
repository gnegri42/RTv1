/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:28:03 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/31 14:28:06 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <stdio.h>

int init_light(t_map *map, t_object_list *new_elem, char *str)
{
	if (map)
	{
		if (str)
		{
			if (new_elem)
			return (0);
		}
	}
	return (0);
}

int init_sphere(t_map *map, t_object_list *new_elem, char *str)
{	
	t_sphere	*sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (-1);
	new_elem->sphere = *sphere;
	if (check_sphere(map, new_elem, str) == false)
		return (-1);
	free(sphere);
	return (0);
}

int init_cylindre(t_map *map, t_object_list *new_elem, char *str)
{
	if (map)
	{
		if (str)
		{
			if (new_elem)
			return (0);
		}
	}
	return (0);
}

int init_cone(t_map *map, t_object_list *new_elem, char *str)
{
	if (map)
	{
		if (str)
		{
			if (new_elem)
			return (0);
		}
	}
	return (0);
}

int init_plan(t_map *map, t_object_list *new_elem, char *str)
{
	if (map)
	{
		if (str)
		{
			if (new_elem)
			return (0);
		}
	}
	return (0);
}
