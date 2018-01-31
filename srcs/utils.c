/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:08:36 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/31 12:08:37 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		skip_space(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int		ft_atoi_custom(const char *str, int *i)
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
