/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 11:26:43 by gnegri            #+#    #+#             */
/*   Updated: 2018/02/08 11:26:44 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3	ft_translation(t_vec3 ex_pos, t_vec3 param)
{
	t_vec3	new_pos;

	new_pos.x = ex_pos.x + param.x;
	new_pos.y = ex_pos.y + param.y;
	new_pos.z = ex_pos.z + param.z;
	return (new_pos);
}
