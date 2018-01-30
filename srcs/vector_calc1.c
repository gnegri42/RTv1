/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:03:35 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/29 18:03:36 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	vector_substraction(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vec3 vector_int_product(t_vec3 v1, int i)
{
	t_vec3	res;

	res.x = v1.x * i;
	res.y = v1.y * i;
	res.z = v1.z * i;
	return (res);
}

t_vec3	vector_assign_values(float x, float y, float z)
{
	t_vec3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vec3	vector_addition(t_vec3 v1, t_vec3 v2)
{
	t_vec3	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec3 vector_float_product(t_vec3 v1, float i)
{
	t_vec3	res;

	res.x = v1.x * i;
	res.y = v1.y * i;
	res.z = v1.z * i;
	return (res);
}