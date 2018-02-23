/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:16:38 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/14 14:16:40 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec_color3 	color_double_product(t_vec_color3 v1, double i)
{
	t_vec_color3	res;

	res.r = v1.r * i;
	res.g = v1.g * i;
	res.b = v1.b * i;
	return (res);
}

t_vec_color3	vector_assign_colors(int r, int g, int b)
{
	t_vec_color3 v;

	v.r = r;
	v.g = g;
	v.b = b;
	return (v);
}

t_vec_color3	color_product(t_vec_color3 v1, t_vec_color3 v2)
{
	t_vec_color3 v;

	v.r = v1.r * v2.r;
	v.g = v1.g * v2.g;
	v.b = v1.b * v2.b;
	return (v);
}

t_vec_color3	color_addition(t_vec_color3 v1, t_vec_color3 v2)
{
	t_vec_color3 v;

	v.r = v1.r + v2.r;
	v.g = v1.g + v2.g;
	v.b = v1.b + v2.b;
	return (v);
}

t_vec_color3	color_mix(t_vec_color3 v1, t_vec_color3 v2)
{
	t_vec_color3 v;

	v.r = v1.r - (v1.r - v2.r)/2;
	v.g = v1.g - (v1.g - v2.g)/2;
	v.b = v1.b - (v1.b - v2.b)/2;
	return (v);
}