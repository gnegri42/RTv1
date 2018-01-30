/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:21:06 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/30 11:21:09 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	vector_product(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x * v2.x;
	res.y = v1.y * v2.y;
	res.z = v1.z * v2.z;
	return (res);
}

t_vec3	vector_normalize(t_vec3 v1)
{
	t_vec3	res;
	double	length;

	length = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	if (length == 0)
	{
		res.x = 0;
		res.y = 0;
		res.z = 0;
		return (res);
	}
	length = 1 / length;
	res.x = v1.x * length;
	res.y = v1.y * length;
	res.z = v1.z * length;
	return (res);
}

float	vector_dot_product(t_vec3 v1, t_vec3 v2)
{
	float	dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot);
}