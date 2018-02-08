/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:22:42 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/06 17:22:43 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_light(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 9)
		return (false);
	new_elem->spot.spot_pos = assign_vectors(str, &j, new_elem->spot.spot_pos);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->spot.spot_dir = assign_vectors(str, &j, new_elem->spot.spot_dir);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->spot.intensity = atoi_custom(str, &j);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->spot.color = rgb_to_hex(col.r, col.g, col.b);
	return (true);
}

int 		init_light(t_object_list *new_elem, char *str)
{
	t_spot	*spot;

	if (!(spot = (t_spot *)malloc(sizeof(t_spot))))
		return (false);
	new_elem->spot = *spot;
	if (check_light(new_elem, str) == false)
	{
		free(spot);
		return (false);
	}
	free(spot);
	return (true);
}
/*
int	light_ray(mlx)
{

}
*/
