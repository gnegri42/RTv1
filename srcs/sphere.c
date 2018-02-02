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
	radius_sq = mlx->map->list->sphere.radius * mlx->map->list->sphere.radius;
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

int	sphere_intersection_init(t_mlx *mlx, int x, int y)
{
	/*t_vec3		origin_to_sphere;
	float		projection;
	t_vec3		distance_vector;

	mlx->cam->ray->sphere_intersection = 0;
	origin_to_sphere = vector_substraction(mlx->map->list->sphere.position, mlx->cam->ray->origin);
	if ((projection = vector_dot_product(origin_to_sphere, mlx->cam->ray->direction)) < 0)
		return (0);
	distance_vector = vector_substraction(origin_to_sphere, vector_float_product(mlx->cam->ray->direction, projection));
	sphere_intersection(mlx, distance_vector, projection, x, y);*/

	t_vec3	L;
	float	a;
	float	b;
	float	c;
	float	discr;
	float	x0;
	float	x1;
	float	q;
	float	tmp;

	mlx->cam->ray->sphere_intersection = 0;

	L = vector_substraction(mlx->cam->ray->origin, mlx->map->list->sphere.position);
	a = vector_dot_product(mlx->cam->view_dir, mlx->cam->view_dir);
	b = 2 * vector_dot_product(mlx->cam->view_dir, L);
	c = (vector_dot_product(L, L) - (mlx->map->list->sphere.radius * mlx->map->list->sphere.radius));
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		x0 = -0.5 * b / a;
		x1 = x0;
	}
	else
	{
		q = (b > 0) ? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
		x0 = q /a;
		x1 = c / q;
	}
	if (x0 > x1)
	{
		tmp = x0;
		x0 = x1;
		x1 = tmp;
	}
	if (x0 < 0)
	{
		x0 = x1;
		if (x0 < 0)
			return (0);
	}
	mlx->cam->ray->sphere_intersection = 1;
	return (0);
}
