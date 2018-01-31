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

	if (ft_strcmp(str, "WIN") == 0)
		i = WIN;
	if (ft_strcmp(str, "CAM") == 0)
		i = CAM;
	if (ft_strcmp(str, "LIG") == 0)
		i = LIG;
	if (ft_strcmp(str, "SPH") == 0)
		i = SPH;
	if (ft_strcmp(str, "CYL") == 0)
		i = CYL;
	if (ft_strcmp(str, "CON") == 0)
		i = CON;
	if (ft_strcmp(str, "PLA") == 0)
		i = PLA;
	return (i);
}

int		read_first_letters(char *str, int i)
{
	char	*tmp_str;
	int		j;
	int		f;

	if (!tmp_str = malloc(sizeof char) * 4)
		return(0);
	j = 0;
	while (j < 3)
	{
		tmp_str[j] = str[i];
		i++;
		j++;
	}
	tmp_str[i] = '\0';
	f = find_form(tmp_str);
	free(tmp_str);
	return (f);
}

int		skip_space(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int		atoi_custom(const char *str, int *i)
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