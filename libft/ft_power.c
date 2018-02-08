/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:16:15 by gnegri            #+#    #+#             */
/*   Updated: 2018/02/08 17:16:18 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int value, int power)
{
	int i;
	int result;

	i = 2;
	result = value;
	while (i <= power)
	{
		result = result * value;
		i++;
	}
	return (result);
}
