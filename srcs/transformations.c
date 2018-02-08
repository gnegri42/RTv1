/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 11:26:43 by gnegri            #+#    #+#             */
/*   Updated: 2018/02/08 11:26:44 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>
static t_vec3	ft_translation(t_vec3 ex_pos, t_vec3 param)
{
	t_vec3	new_pos;

	new_pos.x = ex_pos.x + param.x;
	new_pos.y = ex_pos.y + param.y;
	new_pos.z = ex_pos.z + param.z;
	return (new_pos);
}

void			transformations(t_object_list *new_elem, char *str, int *j)
{
	t_vec3	translation;
	//t_vec3	rotation;
	loop(str, j);
	translation = (t_vec3){0, 0, 0};
	translation = assign_vectors(str, j, translation);
	new_elem->sphere.position = ft_translation(new_elem->sphere.position, translation);
}
