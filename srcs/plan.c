/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 18:08:24 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/31 18:08:26 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	plan_intersection(t_mlx *mlx, t_vec3 distance_vector, float projection, float x, float y)
{
	float	distance_sq;
	float	radius_sq;
	float	new_length;

	distance_sq = vector_dot_product(distance_vector, distance_vector);
	radius_sq = mlx->map->plan->radius * mlx->map->plan->radius;
	if (distance_sq > radius_sq)
		mlx->cam->ray->plan_intersection = 0;
	new_length = projection - sqrtf(radius_sq - distance_sq);
	if (new_length < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = new_length;
		mlx->cam->ray->plan_intersection = 1;
	}
	if (mlx->cam->ray->plan_intersection == 1)
		draw(mlx, x, y);
	return (0);
}

int	check_plan(t_mlx *mlx, float x, float y)
{
	t_plan	*plan;
	t_vec3		origin_to_plan;
	float		projection;
	t_vec3		distance_vector;


	if (!(plan = (t_plan *)malloc(sizeof(t_plan))))
		return (-1);
	mlx->map->plan = plan;
	mlx->cam->ray->plan_intersection = 0;
	mlx->map->plan->radius = 5;
	plan->position = vector_assign_values(0, 0, 40);
	origin_to_plan = vector_substraction(plan->position, mlx->cam->ray->origin);
	projection = vector_dot_product(origin_to_plan, mlx->cam->ray->direction);
	distance_vector = vector_substraction(origin_to_plan, vector_float_product(mlx->cam->ray->direction, projection));
	plan_intersection(mlx, distance_vector, projection, x, y);
	free(plan);
	return (0);
}
