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
#include <stdio.h>

static t_object_list 	*find_light(t_mlx *mlx)
{
	t_object_list 	*tmp;
	t_object_list	*light_source;

	tmp = mlx->map->begin_list;
	light_source = NULL;
	while (mlx->map->begin_list->next != NULL)
	{
		if (mlx->map->begin_list->type == 13)
		{
			light_source = mlx->map->begin_list;
			break ;
		}
		else
			mlx->map->begin_list = mlx->map->begin_list->next;
	}
	mlx->map->begin_list = tmp;
	return (light_source);
}

static int	check_light(t_object_list *new_elem, char *str)
{
	int		j;
	int		c;
	t_vec_color3	col;

	j = 0;
	if ((c = count_int(str)) != 10)
		return (false);
	new_elem->light.position = assign_vectors(str, &j, new_elem->light.position);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->light.direction = assign_vectors(str, &j, new_elem->light.direction);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->light.intensity = atoi_custom(str, &j);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->light.color = rgb_to_hex(col.r, col.g, col.b);
	return (true);
}

int 		init_light(t_object_list *new_elem, char *str)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (false);
	new_elem->light = *light;
	if (check_light(new_elem, str) == false)
	{
		free(light);
		return (false);
	}
	free(light);
	return (true);
}

int	light_ray(t_mlx *mlx)
{
	t_object_list	*source;
	t_vec3	hit_point;
	t_vec3	light;
  	float	cos_a;
	float	color;

	color = mlx->cam->ray->hit_object_col;
	cos_a = 0;
	source = find_light(mlx);
	if (mlx->cam->ray->sphere_intersection == 1 || mlx->cam->ray->plan_intersection == 1
		|| mlx->cam->ray->cone_intersection == 1 || mlx->cam->ray->cylindre_intersection == 1)
	{
		hit_point = vector_addition(mlx->cam->cam_pos, vector_float_product(mlx->cam->ray->direction, mlx->cam->ray->length));
		light = vector_substraction(source->light.position, hit_point);
		cos_a = (hit_point.x * light.x + hit_point.y * light.y + hit_point.z * light.z)
		/ (norme_vector(vector_normalize(hit_point)) * norme_vector(light));
		if (cos_a < 0 || cos_a > 1)
			cos_a = 0;
		//color = mlx->cam->ray->hit_object_col * source->light.color * cos_a;
		color = mlx->cam->ray->hit_object_col;
	}
	return (color);
}
