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

static int		find_form(char *str)
{
	int i;

	i = 0;
	if (ft_strcmp(str, "CAM") == 0)
		i = 12;
	if (ft_strcmp(str, "LIG") == 0)
		i = 13;
	if (ft_strcmp(str, "SPH") == 0)
		i = 14;
	if (ft_strcmp(str, "CYL") == 0)
		i = 15;
	if (ft_strcmp(str, "CON") == 0)
		i = 16;
	if (ft_strcmp(str, "PLA") == 0)
		i = 17;
	return (i);
}

int				read_first_letters(char *str, int i)
{
	char	*tmp_str;
	int		j;
	int		f;
	
	tmp_str = (char *)malloc(sizeof(char) * 4);
	j = 0;
	while (j < 3)
	{	
		tmp_str[j] = str[i];
		i++;
		j++;
	}
	tmp_str[3] = '\0';
	f = find_form(tmp_str);
	free(tmp_str);
	return (f);
}

int				count_int(char *str)
{
	int i;
	int nb_int;

	i = 0;
	nb_int = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '.' && (str[i + 1] >= '0' && str[i + 1] <= '9')))
		{
			nb_int++;
			while (((str[i] >= '0' && str[i] <= '9') || str[i] == '.') && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (nb_int);
}

static float	atoi_custom_next(const char *str, int *i, float v)
{
	int power;
	float value;

	power = 2;
	(*i)++;
	v = v + (str[*i] - 48) * 0.1;
	(*i)++;
	while ((str[*i] >= '0' && str[*i] <= '9') && str[*i + 1] != '\0')
	{
		value = ft_power(10, power);
		v = v + (float)(str[*i] - 48) * (float)(1 / value);
		(*i)++;
		power++;
	}
	return (v);
}

float			atoi_custom(const char *str, int *i)
{
	float v;
	float posneg;

	v = 0;
	posneg = 1;
	while (str[*i] == '\n' || str[*i] == '\t' || str[*i] == '\v' ||
			str[*i] == '\r' || str[*i] == '\f' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-')
		posneg = -1;
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
	while (((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '.') && str[*i + 1] != '\0')
	{
		if (str[*i] == '.' && (str[*i + 1] >= '0' && str[*i + 1] <= '9'))
		{
			v = atoi_custom_next(str, i, v);
			break;
		}
		else
			v = v * 10 + str[*i] - 48;
		(*i)++;
	}
	return (posneg * v);
}
