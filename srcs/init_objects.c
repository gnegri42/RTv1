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

static int init_sphere(t_object_list *new_elem, char *str)
{	
	t_sphere	*sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (-1);
	new_elem->sphere = *sphere;
	if (check_sphere(new_elem, str) == false)
		return (-1);
	free(sphere);
	return (0);
}

static int init_cylindre(t_object_list *new_elem, char *str)
{
	t_cylindre	*cylindre;

	if (!(cylindre = (t_cylindre *)malloc(sizeof(t_cylindre))))
		return (-1);
	new_elem->cylindre = *cylindre;
	if (check_cylindre(new_elem, str) == false)
		return (-1);
	free(cylindre);
	return (0);
}

/*static int init_cone(t_object_list *new_elem, char *str)
{
		if (str)
		{
			if (new_elem)
			return (0);
		}
	return (0);
}*/

static int init_plan(t_object_list *new_elem, char *str)
{
	t_plan	*plan;

	if (!(plan = (t_plan *)malloc(sizeof(t_plan))))
		return (-1);
	new_elem->plan = *plan;
	if (check_plan(new_elem, str) == false)
		return (-1);
	free(plan);
	return (0);
}

int init_object(t_object_list *new_elem, char *str, int o)
{
	int i;

	i = 0;
	if (o == 14)
		i = init_sphere(new_elem, str);
	if (o == 17)
		i = init_plan(new_elem, str);
	if (o == 15)
		i = init_cylindre(new_elem, str);
/*	if (o == CON)
		i = init_cone(map, new_elem, str);*/
	return (i);
}