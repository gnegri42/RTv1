/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:34:34 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/06 15:34:35 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	cone_intersection_init(t_mlx *mlx, float x, float y)
{
	float	disc;
	float	t0;
	float	t1;
	float	a;
	float	b;
	float	c;
	t_vec3	dist;

	mlx->cam->ray->cone_intersection = 0;
	dist = vector_substraction(mlx->cam->cam_pos, mlx->map->list->cone.position);
	vector_normalize(mlx->map->list->cone.direction);
	a = vector_dot_product(mlx->cam->ray->direction, mlx->cam->ray->direction) - (1 + pow(tan(mlx->map->list->cone.radius), 2)) *
		pow(vector_dot_product(mlx->cam->ray->direction, mlx->map->list->cone.direction), 2);
	b = 2 * (vector_dot_product(mlx->cam->ray->direction, dist) - (1 + pow(tan(mlx->map->list->cone.radius), 2))
		* vector_dot_product(mlx->cam->ray->direction, mlx->map->list->cone.direction) * vector_dot_product(dist, mlx->map->list->cone.direction));
	c = vector_dot_product(dist, dist) - (1 + pow(tan(mlx->map->list->cone.radius), 2)) * pow(vector_dot_product(dist, mlx->map->list->cone.direction), 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	t0 = (-b + sqrtf(disc)) / (2 * a);
	t1 = (-b - sqrtf(disc)) / (2 * a);
	if (t0 > t1)
		t0 = t1;
	if (t0 < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = t0;
		mlx->cam->ray->cone_intersection = 1;
	}
	if (mlx->cam->ray->cone_intersection == 1)
		draw(mlx, x, y, RED);
	return (true);
}