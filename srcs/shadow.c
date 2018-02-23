/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:17:19 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/14 14:17:20 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	light_hit(t_mlx *mlx, t_object_list *source, t_vec3	normale)
{
	int		hit;

	hit = 0;
	mlx->map->shadow = 1;
	check_ray_objects(mlx, source->light.hit_point, source->light.dist);
	if (source->light.length > mlx->cam->ray[mlx->map->light_count]->length)
		hit = 1;
	mlx->map->shadow = 0;
	return (hit);
}