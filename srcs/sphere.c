/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:07:52 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/31 18:07:54 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	sphere_intersection(t_mlx *mlx, t_vec3 distance_vector, float projection)
{
	float	distance_sq;
	float	radius_sq;
	float	new_length;

	distance_sq = vector_dot_product(distance_vector, distance_vector);
	radius_sq = mlx->map->list->sphere.radius * mlx->map->list->sphere.radius;
	if (distance_sq > radius_sq)
		mlx->cam->ray[mlx->map->light_count]->sphere_intersection = 0;
	new_length = projection - sqrtf(radius_sq - distance_sq);
	if (new_length < mlx->cam->ray[mlx->map->light_count]->length)
	{
		mlx->cam->ray[mlx->map->light_count]->length = new_length;
		mlx->cam->ray[mlx->map->light_count]->hit_object_pos = mlx->map->list->sphere.position;
		mlx->cam->ray[mlx->map->light_count]->hit_object_col = mlx->map->list->sphere.color;
		mlx->cam->ray[mlx->map->light_count]->hit_object_radius = mlx->map->list->sphere.radius;
		mlx->cam->ray[mlx->map->light_count]->sphere_intersection = 1;
	}
	if (mlx->cam->ray[mlx->map->light_count]->sphere_intersection == 1 && mlx->map->shadow == 0)
		draw(mlx, mlx->x, mlx->y);
	return (0);
}

int	sphere_intersection_init(t_mlx *mlx, t_vec3 origin, t_vec3 direction)
{
	t_vec3		origin_to_sphere;
	float		projection;
	t_vec3		distance_vector;

	mlx->cam->ray[mlx->map->light_count]->sphere_intersection = 0;
	origin_to_sphere = vector_substraction(mlx->map->list->sphere.position, origin);
	if ((projection = vector_dot_product(origin_to_sphere, direction)) < 0)
		return (0);
	distance_vector = vector_substraction(origin_to_sphere, vector_float_product(mlx->cam->ray[mlx->map->light_count]->direction, projection));
	sphere_intersection(mlx, distance_vector, projection);
	return (0);
}
