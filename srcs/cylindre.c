/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:03:22 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/31 16:03:24 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	cylindre_intersection(t_mlx *mlx, t_vec3 distance_vector, float projection, float x, float y)
{
	float	distance_sq;
	float	radius_sq;
	float	new_length;

	distance_sq = vector_dot_product(distance_vector, distance_vector);
	radius_sq = mlx->map->cylindre->radius * mlx->map->cylindre->radius;
	if (distance_sq > radius_sq)
		mlx->cam->ray->cylindre_intersection = 0;
	new_length = projection - sqrtf(radius_sq - distance_sq);
	if (new_length < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = new_length;
		mlx->cam->ray->cylindre_intersection = 1;
	}
	if (mlx->cam->ray->cylindre_intersection == 1)
		draw(mlx, x, y);
	return (0);
}

int	check_cylindre(t_mlx *mlx, float x, float y)
{
	t_cylindre	*cylindre;
	t_vec3		origin_to_cylindre;
	float		projection;
	t_vec3		distance_vector;


	if (!(cylindre = (t_cylindre *)malloc(sizeof(t_cylindre))))
		return (-1);
	mlx->map->cylindre = cylindre;
	mlx->cam->ray->cylindre_intersection = 0;
	mlx->map->cylindre->radius = 5;
	cylindre->position = vector_assign_values(0, 0, 40);
	origin_to_cylindre = vector_substraction(cylindre->position, mlx->cam->ray->origin);
	projection = vector_dot_product(origin_to_cylindre, mlx->cam->ray->direction);
	distance_vector = vector_substraction(origin_to_cylindre, vector_float_product(mlx->cam->ray->direction, projection));
	cylindre_intersection(mlx, distance_vector, projection, x, y);
	free(cylindre);
	return (0);
}
