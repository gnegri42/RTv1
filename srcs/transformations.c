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

static t_vec3	ft_translation(t_vec3 ex_pos, t_vec3 param)
{
	t_vec3	new_pos;

	new_pos.x = ex_pos.x + param.x;
	new_pos.y = ex_pos.y + param.y;
	new_pos.z = ex_pos.z + param.z;
	return (new_pos);
}

void			transformations(t_vec3 *position, t_vec3 *direction, char *str, int *j)
{
	t_vec3	translation;
	t_vec3	inv_pos;
	t_vec3	tmp_pos;
	t_vec3	rotation_degree;

	loop(str, j);
	tmp_pos = *position;
	inv_pos = vector_float_product(tmp_pos, -1);
	*position = ft_translation(*position, inv_pos);
	rotation_degree = (t_vec3){0, 0, 0};
	rotation_degree = assign_vectors(str, j, rotation_degree);
	ft_rotation(position, rotation_degree);
	ft_rotation(direction, rotation_degree);
	*position = ft_translation(*position, tmp_pos);
	loop(str, j);
	translation = (t_vec3){0, 0, 0};
	translation = assign_vectors(str, j, translation);
	*position = ft_translation(*position, translation);
}
