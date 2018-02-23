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

int			skip_space(char *str, int i)
{
	if (str[i] == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

static int	check_negative(char *str, int *j)
{
	int *i;

	i = j;
	if (str[*j] == '-' || str[*j] == '+')
	{
		if (str[*i + 1] < '0' || str[*i + 1] > '9')
			return (false);
		return (true);
	}
	return (false);
}

void			loop(char *str, int *j)
{
	while (str[*j] < '0' || str[*j] > '9')
	{
		if (check_negative(str, j) == true)
			break ;
		(*j)++;
	}
}

t_vec3			assign_vectors(char *str, int *j, t_vec3 vec)
{
	double x;
	double y;
	double z;

	loop(str, j);
	x = atoi_custom(str, j);
	loop(str, j);
	y = atoi_custom(str, j);
	loop(str, j);
	z = atoi_custom(str, j);
	vec = vector_assign_values(x, y, z);
	return (vec);
}

double		vector_length(t_vec3 v1)
{
	double length;

	length = sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z);
	return (length);
}
