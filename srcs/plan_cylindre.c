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

int	plan_intersection_init(t_mlx *mlx, t_vec3 origin, t_vec3 direction)
{
	double	dist_inter;

	mlx->cam->ray[mlx->map->light_count]->plan_intersection = 0;
	dist_inter = ((vector_dot_product(mlx->map->list->plan.rotation, mlx->map->list->plan.position) -
		vector_dot_product(mlx->map->list->plan.rotation, origin)) / vector_dot_product(mlx->map->list->plan.rotation, direction));
	if (dist_inter < 0.0001)
		return (false);
	if (dist_inter < mlx->cam->ray[mlx->map->light_count]->length)
	{
		mlx->cam->ray[mlx->map->light_count]->length = dist_inter;
		mlx->cam->ray[mlx->map->light_count]->hit_object_pos = mlx->map->list->plan.position;
		mlx->cam->ray[mlx->map->light_count]->hit_object_col = mlx->map->list->plan.color;
		mlx->cam->ray[mlx->map->light_count]->plan_intersection = 1;
	}
	if (mlx->cam->ray[mlx->map->light_count]->plan_intersection == 1 && mlx->map->shadow == 0)
		draw(mlx, mlx->x, mlx->y);
	return (0);
}

int	cylindre_intersection_init(t_mlx *mlx, t_vec3 origin, t_vec3 direction)
{
	double	disc;
	double	t0;
	double	t1;
	double	a;
	double	b;
	double	c;
	t_vec3	dist;

	mlx->cam->ray[mlx->map->light_count]->cylindre_intersection = 0;
	dist = vector_substraction(origin, mlx->map->list->cylindre.position);
	vector_normalize(mlx->map->list->cylindre.direction);
	a = vector_dot_product(direction, direction) - pow(vector_dot_product(direction, mlx->map->list->cylindre.direction), 2);
	b = 2 * (vector_dot_product(direction, dist) -
		(vector_dot_product(direction, mlx->map->list->cylindre.direction) * vector_dot_product(dist, mlx->map->list->cylindre.direction)));
	c = vector_dot_product(dist, dist) - pow(vector_dot_product(dist, mlx->map->list->cylindre.direction), 2) - pow(mlx->map->list->cylindre.radius, 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	t0 = (-b + sqrtf(disc)) / (2 * a);
	t1 = (-b - sqrtf(disc)) / (2 * a);
	if (t0 > t1)
		t0 = t1;
	if (t0 < mlx->cam->ray[mlx->map->light_count]->length)
	{
		mlx->cam->ray[mlx->map->light_count]->length = t0;
		mlx->cam->ray[mlx->map->light_count]->hit_object_pos = mlx->map->list->cylindre.position;
		mlx->cam->ray[mlx->map->light_count]->hit_object_col = mlx->map->list->cylindre.color;
		mlx->cam->ray[mlx->map->light_count]->cylindre_intersection = 1;
	}
	if (mlx->cam->ray[mlx->map->light_count]->cylindre_intersection == 1 && mlx->map->shadow == 0)
		draw(mlx, mlx->x, mlx->y);
	return (true);
}

