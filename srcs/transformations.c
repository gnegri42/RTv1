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
static t_vec3	ft_rotation_z(t_vec3 ex_pos, float angle)
{
	float new_x;
	float new_y;
	t_vec3	new_pos;

	angle = ft_deg2rad(angle);
	new_x = ex_pos.x * cosf(angle) + ex_pos.y * -sinf(angle);
	new_y = ex_pos.x * sinf(angle) + ex_pos.y * cosf(angle);
	new_pos.x = new_x;
	new_pos.y = new_y;
	new_pos.z = ex_pos.z;
	return (new_pos);
}

static t_vec3	ft_rotation_y(t_vec3 ex_pos, float angle)
{
	float new_x;
	float new_z;
	t_vec3	new_pos;

	angle = ft_deg2rad(angle);
	new_x = ex_pos.x * cosf(angle) + ex_pos.z * sinf(angle);
	new_z = ex_pos.x * -sinf(angle) + ex_pos.z * cosf(angle);
	new_pos.x = new_x;
	new_pos.z = new_z;
	new_pos.y = ex_pos.y;
	return (new_pos);
}

static t_vec3	ft_rotation_x(t_vec3 ex_pos, float angle)
{
	float 	new_y;
	float 	new_z;
	t_vec3	new_pos;

	angle = ft_deg2rad(angle);
	new_y = ex_pos.y * cosf(angle) + ex_pos.z * -sinf(angle);
	new_z = ex_pos.y * sinf(angle) + ex_pos.z * cosf(angle);
	new_pos.y = new_y;
	new_pos.z = new_z;
	new_pos.x = ex_pos.x;
	return (new_pos);
}

static t_vec3	ft_translation(t_vec3 ex_pos, t_vec3 param)
{
	t_vec3	new_pos;

	new_pos.x = ex_pos.x + param.x;
	new_pos.y = ex_pos.y + param.y;
	new_pos.z = ex_pos.z + param.z;
	return (new_pos);
}

void			transformations(t_vec3 *position, char *str, int *j)
{
	t_vec3	translation;
	t_vec3	rotation_degree;

	loop(str, j);
	translation = (t_vec3){0, 0, 0};
	translation = assign_vectors(str, j, translation);
	*position = ft_translation(*position, translation);
	loop(str, j);
	rotation_degree = (t_vec3){0, 0, 0};
	rotation_degree = assign_vectors(str, j, rotation_degree);
	*position = ft_rotation_x(*position, rotation_degree.x);
	*position = ft_rotation_y(*position, rotation_degree.y);
	*position = ft_rotation_z(*position, rotation_degree.z);
}
