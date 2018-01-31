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

static int	sphere_intersection(t_mlx *mlx, t_vec3 distance_vector, float projection, int x, int y)
{
	float	distance_sq;
	float	radius_sq;
	float	new_length;

	distance_sq = vector_dot_product(distance_vector, distance_vector);
	radius_sq = mlx->map->sphere->radius * mlx->map->sphere->radius;
	if (distance_sq > radius_sq)
		mlx->cam->ray->sphere_intersection = 0;
	new_length = projection - sqrtf(radius_sq - distance_sq);
	if (new_length < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = new_length;
		mlx->cam->ray->sphere_intersection = 1;
	}
	if (mlx->cam->ray->sphere_intersection == 1)
		draw(mlx, x, y);
	return (0);
}

int	check_sphere(t_mlx *mlx, int x, int y)
{
	t_sphere	*sphere;
	t_vec3		origin_to_sphere;
	float		projection;
	t_vec3		distance_vector;


	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (-1);
	mlx->map->sphere = sphere;
	mlx->cam->ray->sphere_intersection = 0;
	mlx->map->sphere->radius = 8;
	sphere->position = vector_assign_values(0, 0, 40);
	origin_to_sphere = vector_substraction(sphere->position, mlx->cam->ray->origin);
	projection = vector_dot_product(origin_to_sphere, mlx->cam->ray->direction);
	distance_vector = vector_substraction(origin_to_sphere, vector_float_product(mlx->cam->ray->direction, projection));
	sphere_intersection(mlx, distance_vector, projection, x, y);
	free(sphere);
	return (0);
}
