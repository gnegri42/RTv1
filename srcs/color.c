/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:10:12 by gnegri            #+#    #+#             */
/*   Updated: 2018/02/06 16:10:13 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				atoi_color(const char *str, int *i)
{
	int v;
	int posneg;

	v = 0;
	posneg = 1;
	while (str[*i] == '\n' || str[*i] == '\t' || str[*i] == '\v' ||
			str[*i] == '\r' || str[*i] == '\f' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
		posneg = -1;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		v = v * 10 + str[*i] - 48;
		(*i)++;
	}
	return (posneg * v);
}

t_vec_color3	assign_colors(char *str, int *j, t_vec_color3 col)
{
	int r;
	int g;
	int b;

	while (str[*j] < '0' || str[*j] > '9')
		(*j)++;
	r = atoi_color(str, j);
	while (str[*j] < '0' || str[*j] > '9')
		(*j)++;
	g = atoi_color(str, j);
	while (str[*j] < '0' || str[*j] > '9')
		(*j)++;
	b = atoi_color(str, j);
	col = vector_assign_colors(r, g, b);
	return (col);
}

