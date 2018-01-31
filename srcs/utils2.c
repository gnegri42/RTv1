/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:38:30 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/31 16:38:31 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	assign_vectors(char *str, int *j, t_vec3 vec)
{
	float x;
	float y;
	float z;

	while (str[*j] < '0' || str[*j] > '9')
		(*j)++;
	x = atoi_custom(str, j);
	while (str[*j] < '0' || str[*j] > '9')
		(*j)++;
	y = atoi_custom(str, j);
	while (str[*j] < '0' || str[*j] > '9')
		(*j)++;
	z = atoi_custom(str, j);
	vec = vector_assign_values(x, y, z);
	return (vec);
}
