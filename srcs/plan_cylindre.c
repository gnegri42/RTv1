/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:12:41 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/05 18:12:43 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	plan_intersection_init(t_mlx *mlx, float x, float y)
{
	float	dist_inter;

	mlx->cam->ray->plan_intersection = 0;
	dist_inter = ((vector_dot_product(mlx->map->list->plan.rotation, mlx->map->list->plan.position) -
		vector_dot_product(mlx->map->list->plan.rotation, mlx->cam->cam_pos)) / vector_dot_product(mlx->map->list->plan.rotation, mlx->cam->ray->direction));

	if (dist_inter < 0.0001)
		return (false);
	if (dist_inter < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = dist_inter;
		mlx->cam->ray->hit_object_pos = mlx->map->list->plan.position;
		mlx->cam->ray->hit_object_col = mlx->map->list->plan.color;
		mlx->cam->ray->plan_intersection = 1;
	}
	if (mlx->cam->ray->plan_intersection == 1)
		draw(mlx, x, y, mlx->map->list->plan.color);
	return (0);
}

int	cylindre_intersection_init(t_mlx *mlx, float x, float y)
{
	float	disc;
	float	t0;
	float	t1;
	float	a;
	float	b;
	float	c;
	t_vec3	dist;

	mlx->cam->ray->cylindre_intersection = 0;
	dist = vector_substraction(mlx->cam->cam_pos, mlx->map->list->cylindre.position);
	vector_normalize(mlx->map->list->cylindre.direction);
	a = vector_dot_product(mlx->cam->ray->direction, mlx->cam->ray->direction) - pow(vector_dot_product(mlx->cam->ray->direction, mlx->map->list->cylindre.direction), 2);
	b = 2 * (vector_dot_product(mlx->cam->ray->direction, dist) -
		(vector_dot_product(mlx->cam->ray->direction, mlx->map->list->cylindre.direction) * vector_dot_product(dist, mlx->map->list->cylindre.direction)));
	c = vector_dot_product(dist, dist) - pow(vector_dot_product(dist, mlx->map->list->cylindre.direction), 2) - pow(mlx->map->list->cylindre.radius, 2);
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
		mlx->cam->ray->hit_object_pos = mlx->map->list->plan.position;
		mlx->cam->ray->hit_object_col = mlx->map->list->plan.color;
		mlx->cam->ray->cylindre_intersection = 1;
	}
	if (mlx->cam->ray->cylindre_intersection == 1)
		draw(mlx, x, y, mlx->map->list->cylindre.color);
	return (true);
}
