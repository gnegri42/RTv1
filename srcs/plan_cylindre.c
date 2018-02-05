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
	t_vec3	dist;
	float	dist_inter;
	float	option_2;
	float	disc;
	float	a;
	float	b;
	float	c;

	mlx->cam->ray->cylindre_intersection = 0;
	dist = vector_substraction(mlx->cam->cam_pos, mlx->map->list->cylindre.position);
	vector_normalize(mlx->map->list->cylindre.direction);
	
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	dist_inter = (-b + sqrt(disc)) / (2 * a);
	option_2 = (-b - sqrt(disc)) / (2 * a);
	if (dist_inter > option_2)
		dist_inter = option_2;
	if (dist_inter < mlx->cam->ray->length)
	{
		mlx->cam->ray->length = dist_inter;
		mlx->cam->ray->cylindre_intersection = 1;
	}
	if (mlx->cam->ray->cylindre_intersection == 1)
		draw(mlx, x, y, RED);
	return (0);
}