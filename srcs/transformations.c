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

static t_vec3	ft_rotation_z(t_vec3 ex_pos, float angle)
{
	float new_x;
	float new_y;

	new_x = ex_pos.x * cos(angle) + ex_pos.y * -sin(angle);
	new_y = ex_pos.x * sin(angle) + ex_pos.y * cos(angle);
	ex_pos.x = new_x;
	ex_pos.y = new_y;
	return (ex_pos);
}

static t_vec3	ft_rotation_y(t_vec3 ex_pos, float angle)
{
	float new_x;
	float new_z;

	new_x = ex_pos.x * cos(angle) + ex_pos.z * sin(angle);
	new_z = ex_pos.x * -sin(angle) + ex_pos.z * cos(angle);
	ex_pos.x = new_x;
	ex_pos.z = new_z;
	return (ex_pos);
}

static t_vec3	ft_rotation_x(t_vec3 ex_pos, float angle)
{
	float new_y;
	float new_z;

	new_y = ex_pos.y * cos(angle) + ex_pos.z * -sin(angle);
	new_z = ex_pos.y * sin(angle) + ex_pos.z * cos(angle);
	ex_pos.y = new_y;
	ex_pos.z = new_z;
	return (ex_pos);
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
	float	rotation_degree;

	loop(str, j);
	translation = (t_vec3){0, 0, 0};
	translation = assign_vectors(str, j, translation);
	*position = ft_translation(*position, translation);
	loop(str, j);
	rotation_degree = atoi_custom(str, j);
	if (rotation_degree != 0)
	{
		rotation_degree = ft_deg2rad(rotation_degree);
		*position = ft_rotation_x(*position, rotation_degree);
		*position = ft_rotation_y(*position, rotation_degree);
		*position = ft_rotation_z(*position, rotation_degree);
	}
}
