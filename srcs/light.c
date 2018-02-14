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
	if ((c = count_int(str)) != 7)
		return (false);
	new_elem->light.position = assign_vectors(str, &j, new_elem->light.position);
	while (str[j] < '0' || str[j] > '9')
		j++;
	new_elem->light.intensity = ft_clamp(atoi_custom(str, &j), 0, 1);
	while (str[j] < '0' || str[j] > '9')
		j++;
	col = (t_vec_color3){0, 0, 0};
	col = assign_colors(str, &j, col);
	new_elem->light.color = col;
	new_elem->light.hit_point = (t_vec3){0, 0, 0};
	new_elem->light.dist = (t_vec3){0, 0, 0};
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

static t_vec_color3	specular_light(t_mlx *mlx, t_vec3 light_ray, t_vec3 normale, t_vec3 hit_point, t_object_list *source)
{

	t_vec3			reflection;
	t_vec_color3	specular;
	t_vec_color3	specular_color;
	float			max_calc;
	float			shininess;

	shininess = 100;
	specular_color = (t_vec_color3){255, 255, 255};
	reflection = vector_normalize(vector_substraction(vector_float_product(normale, (vector_dot_product(light_ray, normale))
	 * 2.0f), light_ray));
	max_calc = vector_dot_product(reflection, vector_normalize(vector_substraction(mlx->cam->ray->origin, hit_point)));
	if (max_calc < 0)
		max_calc = 0;
	specular = color_float_product(specular_color, source->light.intensity); 
	specular = color_float_product(specular, pow(max_calc, shininess));
	return (specular);
}

int	light_ray(t_mlx *mlx)
{
	t_object_list	*source;
	t_vec3			normale;
	float 			d;
	int			color;
	t_vec_color3	vec_color;
	t_vec_color3	vec_specular;
	t_vec_color3	ambient;


	color = BLACK;
	source = find_light(mlx);
	if (mlx->cam->ray->sphere_intersection == 1 || mlx->cam->ray->plan_intersection == 1
		|| mlx->cam->ray->cone_intersection == 1 || mlx->cam->ray->cylindre_intersection == 1)
	{
		source->light.hit_point = vector_addition(mlx->cam->ray->origin, vector_float_product(mlx->cam->ray->direction, mlx->cam->ray->length));
		source->light.dist = vector_substraction(source->light.position, source->light.hit_point);
		source->light.dist = vector_normalize(source->light.dist);
		normale = vector_substraction(source->light.hit_point, mlx->cam->ray->hit_object_pos);
		normale = vector_normalize(normale); 
		d = ft_clamp(vector_dot_product(source->light.dist, normale), 0.0, 1.0);
		if (d < 0)
			d = 0.0f;
		vec_color = (t_vec_color3){0, 0, 0};
		vec_color = color_mix(mlx->cam->ray->hit_object_col, source->light.color);
		ambient = color_float_product((t_vec_color3){0.2, 0.2, 0.2}, source->light.intensity);
		ambient = color_product(vec_color, ambient);
		vec_color = color_float_product(vec_color, source->light.intensity);
		vec_color = color_float_product(vec_color, d);
		vec_specular = specular_light(mlx, source->light.dist, normale, source->light.hit_point, source);
		vec_color = color_mix(vec_color, vec_specular);
	//	if (light_hit(mlx, source) == 1)
	//		vec_color = ambient;
	//	vec_color = color_mix(vec_color, ambient);
		color = rgb_to_hex(vec_color.r, vec_color.g, vec_color.b);
	}
	return (color);
}
