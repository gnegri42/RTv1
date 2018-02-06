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
	/*t_vec3	n;
	t_vec3	l;
	t_vec3	p0l0;
	float	denom;*/

	mlx->cam->ray->plan_intersection = 0;
	dist_inter = ((vector_dot_product(mlx->map->list->plan.rotation, mlx->map->list->plan.position) -
		vector_dot_product(mlx->map->list->plan.rotation, mlx->cam->cam_pos)) / vector_dot_product(mlx->map->list->plan.rotation, mlx->cam->ray->direction));

	/*l = mlx->cam->ray->direction;
	n = vector_normalize(mlx->map->list->plan.rotation);
	denom = vector_dot_product(n, l);
	p0l0 = vector_substraction(mlx->map->list->plan.position, mlx->cam->cam_pos);
	dist_inter = vector_dot_product(p0l0, n) / denom;*/

	if (dist_inter < 0.0001)
		return (false);
	if (dist_inter < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = dist_inter;
		mlx->cam->ray->plan_intersection = 1;
	}
	if (mlx->cam->ray->plan_intersection == 1)
		draw(mlx, x, y, WHITE);
	return (0);
}

int	cylindre_intersection_init(t_mlx *mlx, float x, float y)
{
	//t_vec3	dist;
	t_vec3	p0;
	float	t0;
	float	t1;
	float	disc;
	//float 	tmp;
	//float	y0;
	float	y1;
	float	a;
	float	b;
	float	c;

	mlx->cam->ray->cylindre_intersection = 0;
	p0 = vector_assign_values(mlx->cam->ray->origin.x - mlx->map->list->cylindre.position.x, 
		mlx->cam->ray->origin.y - mlx->map->list->cylindre.position.y, 
		mlx->cam->ray->origin.z - mlx->map->list->cylindre.position.z);
	a = mlx->cam->ray->direction.x * mlx->cam->ray->direction.x + mlx->cam->ray->direction.z * mlx->cam->ray->direction.z;
	b = mlx->cam->ray->direction.x * p0.x + mlx->cam->ray->direction.z * p0.z;
	c = p0.x * p0.x + p0.z * p0.z - mlx->map->list->cylindre.radius * mlx->map->list->cylindre.radius;
	disc = b * b - 4 * a * c;
	t0 = (-b + sqrt(disc)) / (2 * a);
	t1 = (-b - sqrt(disc)) / (2 * a);
	if (t1 < 0.00000001)
		return (false);
	y1 = p0.y + t1 * mlx->map->list->cylindre.direction.y;
	if (y1 > 0)
	{
		mlx->cam->ray->cylindre_intersection = 1;
	}
	/*
	METHODE WOOTRACER
	dist = vector_substraction(mlx->cam->cam_pos, mlx->map->list->cylindre.position);
	vector_normalize(mlx->map->list->cylindre.direction);
	a = mlx->map->list->cylindre.direction.x * mlx->map->list->cylindre.direction.x + mlx->map->list->cylindre.direction.z * mlx->map->list->cylindre.direction.z;
	b = 2 * mlx->map->list->cylindre.direction.x * mlx->map->list->cylindre.position.x + 2 * mlx->map->list->cylindre.direction.z * mlx->map->list->cylindre.position.z;
	c = mlx->map->list->cylindre.position.x * mlx->map->list->cylindre.position.x + mlx->map->list->cylindre.position.z * mlx->map->list->cylindre.position.z - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (false);
	t0 = (-b + sqrt(disc)) / (2 * a);
	t1 = (-b - sqrt(disc)) / (2 * a);
	if (t0 > t1)
	{
		tmp = t0;
		t0 = t1;
		t1 = tmp;
	}
	y0 = mlx->map->list->cylindre.position.y + t0 * mlx->map->list->cylindre.direction.y;
	y1 = mlx->map->list->cylindre.position.y + t1 * mlx->map->list->cylindre.direction.y;
	if (y0 >= -1 && y0 <= 1)
	{
		if (t0 <= 0)
			return (false);
		else
		{
			mlx->cam->ray->cylindre_intersection = 1;
		}
	}
	*/
	/*
	if (t0 < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = dist_inter;
		mlx->cam->ray->cylindre_intersection = 1;
	}*/
	if (mlx->cam->ray->cylindre_intersection == 1)
		draw(mlx, x, y, BLUE);
	return (true);
}