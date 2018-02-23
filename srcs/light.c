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
	t_object_list	*light_source;

	light_source = NULL;
	while (mlx->map->light_list->next != NULL)
	{
		if (mlx->map->light_list->type == 13)
		{
			light_source = mlx->map->light_list;
			mlx->map->light_list = mlx->map->light_list->next;
			return (light_source);
		}
		else 
			mlx->map->light_list = mlx->map->light_list->next;
	}
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
	double			max_calc;
	double			shininess;

	shininess = 200;
	specular_color = (t_vec_color3){255, 255, 255};
	reflection = vector_normalize(vector_substraction(vector_double_product(normale, (vector_dot_product(light_ray, normale))
	 * 2.0f), light_ray));
	max_calc = vector_dot_product(reflection, vector_normalize(vector_substraction(mlx->cam->ray[mlx->map->light_count_2]->origin, hit_point)));
	if (max_calc < 0)
		max_calc = 0;
	specular = color_double_product(specular_color, source->light.intensity); 
	specular = color_double_product(specular, pow(max_calc, shininess));
	return (specular);
}

int	light_ray(t_mlx *mlx)
{
	t_object_list	*source;
	t_vec3			normale;
	double 			d;
	t_vec_color3	tmp_color;
	t_vec_color3	vec_color;
	t_vec_color3	vec_specular;
	t_vec_color3	ambient;

	mlx->map->light_list = mlx->map->begin_list;
	tmp_color = (t_vec_color3){0, 0, 0};
	mlx->map->light_count_2 = 0;
	while (mlx->map->light_count_2 < mlx->map->nb_light)
	{	
		source = find_light(mlx);
		if (mlx->cam->ray[0]->sphere_intersection == 1 || mlx->cam->ray[0]->plan_intersection == 1
			|| mlx->cam->ray[0]->cone_intersection == 1 || mlx->cam->ray[0]->cylindre_intersection == 1)
		{
			/*
			////////METHODE N.2 DE GEOF POUR TESTER UN CALCUL DIFFERENT

			source->light.hit_point = vector_addition(mlx->cam->ray[mlx->map->light_count_2]->origin, 
				vector_float_product(mlx->cam->ray[mlx->map->light_count_2]->direction, mlx->cam->ray[mlx->map->light_count_2]->length));
			normale = vector_substraction(source->light.hit_point, mlx->cam->ray[mlx->map->light_count_2]->hit_object_pos);
			normale = vector_normalize(normale);
			source->light.dist = vector_substraction(source->light.position, source->light.hit_point);
			source->light.dist = vector_normalize(source->light.dist);
			d = ft_clamp(vector_dot_product(source->light.dist, normale), 0.0, 1.0);
			if (d < 0)
				d = 0.0f;
			vec_color = color_mix(mlx->cam->ray[mlx->map->light_count_2]->hit_object_col, source->light.color);
			vec_specular = specular_light(mlx, source->light.dist, normale, source->light.hit_point, source);
			vec_color = color_mix(vec_color, vec_specular);
			ambient = color_float_product((t_vec_color3){0.5, 0.5, 0.5}, source->light.intensity);
			ambient = color_product(vec_color, ambient);
			if (light_hit(mlx, source) == 1)
				vec_color = (t_vec_color3){0, 0, 0};
			tmp_color =	color_mix(vec_color, color_float_product(color_float_product(source->light.color, source->light.intensity), d));
			mlx->map->final_color = rgb_to_hex(tmp_color.r, tmp_color.g, tmp_color.b);
			*/

			// CALCUL DE LA DIFFUSE LIGHT //

			source->light.hit_point = vector_addition(mlx->cam->ray[mlx->map->light_count_2]->origin, 
				vector_double_product(mlx->cam->ray[mlx->map->light_count_2]->direction, mlx->cam->ray[mlx->map->light_count_2]->length));
			source->light.dist = vector_substraction(source->light.position, source->light.hit_point);
			source->light.length = sqrt(vector_dot_product(source->light.dist, source->light.dist));
			source->light.dist = vector_normalize(source->light.dist);
			normale = vector_substraction(source->light.hit_point, mlx->cam->ray[mlx->map->light_count_2]->hit_object_pos);
			normale = vector_normalize(normale); 
			d = ft_clamp(vector_dot_product(source->light.dist, normale), 0.0, 1.0);

			///////////////////////////////

			vec_color = mlx->cam->ray[mlx->map->light_count_2]->hit_object_col;
			vec_color = color_mix(mlx->cam->ray[mlx->map->light_count_2]->hit_object_col, source->light.color);
			ambient = color_double_product((t_vec_color3){0.5, 0.5, 0.5}, source->light.intensity);
			ambient = color_product(vec_color, ambient);
			vec_color = color_double_product(vec_color, source->light.intensity);
			vec_color = color_double_product(vec_color, d);
			vec_specular = specular_light(mlx, source->light.dist, normale, source->light.hit_point, source);
			vec_color = color_mix(vec_color, vec_specular);
			//if (light_hit(mlx, source, normale) == 1)
			//{
				//printf("d\n");
			//	vec_color = (t_vec_color3){255, 255, 255};
			//	//vec_color = ambient;
			//}
			vec_color = color_mix(vec_color, ambient);
			if (tmp_color.r == 0 && tmp_color.g == 0 && tmp_color.b == 0)
				tmp_color = vec_color;
			tmp_color = color_mix(tmp_color, vec_color);
			mlx->map->final_color = rgb_to_hex(tmp_color.r, tmp_color.g, tmp_color.b);
		}
		mlx->map->light_count_2++;
	}
	return (mlx->map->final_color);
}
