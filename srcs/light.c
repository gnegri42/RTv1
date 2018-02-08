/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:22:42 by bmuselet          #+#    #+#             */
/*   Updated: 2018/02/06 17:22:43 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
static t_object_list 	*find_light(t_mlx *mlx)
{
	t_object_list *tmp;
	t_object_list *light_source;

	tmp = mlx->map->list;
	while (mlx->map->list->next != NULL)
	{
		if (mlx->map->list->type == 13)
			light_source = mlx->map->list;
		else
			mlx->map->list = mlx->map->list->next;
	}
	mlx->map->list = tmp;
	return (light_source);
}
*/
static int	check_light(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 7)
		return (false);
	new_elem->spot.spot_pos = assign_vectors(str, &j, new_elem->spot.spot_pos);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->spot.spot_dir = assign_vectors(str, &j, new_elem->spot.spot_dir);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->spot.intensity = atoi_custom(str, &j);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->spot.color = rgb_to_hex(col.r, col.g, col.b);
	return (true);
}

int 		init_light(t_object_list *new_elem, char *str)
{
	t_spot	*spot;

	if (!(spot = (t_spot *)malloc(sizeof(t_spot))))
		return (false);
	new_elem->spot = *spot;
	if (check_light(new_elem, str) == false)
	{
		free(spot);
		return (false);
	}
	free(spot);
	return (true);
}

int	light_ray(t_mlx *mlx)
{
	//t_object_list 	*light_source;
	t_vec3	hit_point;
	t_vec3	normale;
	t_vec3	light_ray_direction;
	float 	d;
	int			color;

	color = 0;
	//light_source = find_light(mlx);
	if (mlx->cam->ray->sphere_intersection == 1 || mlx->cam->ray->plan_intersection == 1
		|| mlx->cam->ray->cone_intersection == 1 || mlx->cam->ray->cylindre_intersection == 1)
	{
		hit_point = vector_normalize(vector_addition(mlx->cam->ray->origin, vector_float_product(mlx->cam->ray->direction, mlx->cam->ray->length)));
		normale = vector_normalize(vector_substraction(hit_point, mlx->cam->ray->hit_object_pos));
		light_ray_direction = (t_vec3){-50, -100, 0};
		d = vector_dot_product(normale, light_ray_direction);
		if (d < 0.0f)
			d = 0;
	color = (mlx->cam->ray->hit_object_col);// * rgb_to_hex(255, 255, 255) * d;
	/*color = (((int)((mlx->cam->ray->hit_object_col * d) / mlx->p * 255) & 0xff) << 16)
	+ (((int)((mlx->cam->ray->hit_object_col * d) / mlx->p * 255) & 0xff) << 8)
	+ ((int)((mlx->cam->ray->hit_object_col * d) / mlx->p * 255) & 0xff);*/
	}
	return (color);
}
