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
	t_object_list 			*tmp;
	t_object_list		  *light_source;

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
	if ((c = count_int(str)) != 7)
		return (false);
	new_elem->light.position = assign_vectors(str, &j, new_elem->light.position);
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
	t_vec3			hit_point;
	t_vec3			dist;
	t_vec3			normale;
	t_vec3			view_direction;
	t_vec3			half_angle;
	float			blinn_term;
	float			length;
	float 			d;
	int				color;

	color = BLACK;
	source = find_light(mlx);
	if (mlx->cam->ray->sphere_intersection == 1 || mlx->cam->ray->plan_intersection == 1
		|| mlx->cam->ray->cone_intersection == 1 || mlx->cam->ray->cylindre_intersection == 1)
	{
		hit_point = vector_addition(mlx->cam->ray->origin, vector_float_product(mlx->cam->ray->direction, mlx->cam->ray->length));
		normale = vector_normalize(hit_point);
		dist = vector_substraction(source->light.position, hit_point);
		length = vector_length(dist);
		length = length * length;
		
		dist = vector_normalize(dist);
		d = ft_clamp(vector_dot_product(dist, normale), 0, 1);
		view_direction = vector_normalize(vector_float_product(mlx->cam->ray->origin, -1));
		half_angle = vector_normalize(vector_addition(dist, view_direction));
		blinn_term = vector_dot_product(normale, half_angle);
		blinn_term = ft_clamp(blinn_term, 0, 1);
		if (d == 0)
			blinn_term = 0;
		if (d > 0)
		printf("%f\n", d);
		color = (source->light.color * mlx->cam->ray->hit_object_col * d);
		//color = (mlx->cam->ray->hit_object_col);
	}
	return (color);
}
