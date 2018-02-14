/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:17:19 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/14 14:17:20 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
static int	check_shadow_objects(t_mlx *mlx, float x, float y)
{
	t_object_list *tmp;

	tmp = mlx->map->list;
	while (mlx->map->list != NULL)
	{
		if (mlx->map->list->type == 14)
			sphere_intersection_init(mlx, x, y);
		if (mlx->map->list->type == 15)
			cylindre_intersection_init(mlx, x, y);
		if (mlx->map->list->type == 16)
			cone_intersection_init(mlx, x, y);
		if (mlx->map->list->type == 17)
			plan_intersection_init(mlx, x, y);
		mlx->map->list = mlx->map->list->next;
	}
	mlx->map->list = tmp;
	return(0);
}

static int	create_ray_shadow(t_mlx *mlx, t_object_list *source, float i, float j)
{

	mlx->map->light_ray->origin = vector_assign_values(source->light.position.x, source->light.position.y, source->light.position.z);
	mlx->map->light_ray->forward = vector_substraction(source->light.hit_point, mlx->map->light_ray->origin);
	mlx->map->light_ray->forward = vector_normalize(mlx->map->light_ray->forward);
	mlx->map->light_ray->right = vector_cross((t_vec3){0.0, 1.0, 0.0}, mlx->map->light_ray->forward);
	mlx->map->light_ray->right = vector_normalize(mlx->map->light_ray->right);
	mlx->map->light_ray->up = vector_cross(mlx->map->light_ray->forward, mlx->map->light_ray->right);
	mlx->map->light_ray->direction = (t_vec3){i * mlx->map->light_ray->right.x + j * mlx->map->light_ray->up.x + FOV * mlx->map->light_ray->forward.x, i * mlx->map->light_ray->right.y + j * mlx->map->light_ray->up.y
		+ FOV * mlx->map->light_ray->forward.y, i * mlx->map->light_ray->right.z + j * mlx->map->light_ray->up.z + FOV * mlx->map->light_ray->forward.z};
	mlx->map->light_ray->direction = vector_normalize(mlx->map->light_ray->direction);
	mlx->map->light_ray->length = 1000000000000;
	return (0);
}

static int	ray_loop_shadow(t_mlx *mlx, t_object_list *source)
{
	float 	x;
	float 	y;
	float 	i;
	float	j;
	t_ray	*light_ray;

	y = 0;
	if (!(light_ray = (t_ray *)malloc(sizeof(t_ray))))
		return (-1);
	mlx->map->light_ray = light_ray;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = (2 * (x + 0.5) / (float)WIN_WIDTH - 1);
			j = (1 - 2 * (y + 0.5) / (float)WIN_HEIGHT);
			create_ray_shadow(mlx, source, i ,j);
			check_shadow_objects(mlx, x, y);
			x++;
		}
		y++;
	}
	return(0);
}*/

int	light_hit(t_mlx *mlx)
{
	int	hit;

	hit = 0;
	ray_loop(mlx);
	if (mlx->cam->ray[mlx->map->light_count]->sphere_intersection == 1
		|| mlx->cam->ray[mlx->map->light_count]->plan_intersection == 1
		|| mlx->cam->ray[mlx->map->light_count]->cone_intersection == 1
		|| mlx->cam->ray[mlx->map->light_count]->cylindre_intersection == 1)
		hit = 1;
	return (hit);
}