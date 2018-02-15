/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:41:49 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/29 17:42:35 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int	check_ray_objects(t_mlx *mlx, t_vec3 origin, t_vec3 direction)
{
	t_object_list *tmp;

	tmp = mlx->map->list;
	while (mlx->map->list != NULL)
	{
		if (mlx->map->list->type == 14)
			sphere_intersection_init(mlx, origin, direction);
		if (mlx->map->list->type == 15)
			cylindre_intersection_init(mlx, origin, direction);
		if (mlx->map->list->type == 16)
			cone_intersection_init(mlx, origin, direction);
		if (mlx->map->list->type == 17)
			plan_intersection_init(mlx, origin, direction);
		mlx->map->list = mlx->map->list->next;
	}
	mlx->map->list = tmp;
	return(0);
}

static int	create_ray(t_mlx *mlx, t_cam *cam, float i, float j)
{

	cam->ray[mlx->map->light_count]->origin = vector_assign_values(cam->cam_pos.x, cam->cam_pos.y, cam->cam_pos.z);
	cam->forward = vector_substraction(cam->view_dir, cam->cam_pos);
	cam->forward = vector_normalize(cam->forward);
	cam->right = vector_cross((t_vec3){0.0, 1.0, 0.0}, cam->forward);
	cam->right = vector_normalize(cam->right);
	cam->up = vector_cross(cam->forward, cam->right);
	cam->ray[mlx->map->light_count]->direction = (t_vec3){i * cam->right.x + j * cam->up.x + FOV * cam->forward.x, i * cam->right.y + j * cam->up.y
		+ FOV * cam->forward.y, i * cam->right.z + j * cam->up.z + FOV * cam->forward.z};
	cam->ray[mlx->map->light_count]->direction = vector_normalize(cam->ray[mlx->map->light_count]->direction);
	cam->ray[mlx->map->light_count]->length = 1000000000000;
	return (0);
}

int	ray_loop(t_mlx *mlx)
{
	float 	i;
	float	j;
	t_vec3	origin;
	t_vec3	direction;
	
	mlx->y = 0;
	while (mlx->y < WIN_HEIGHT)
	{
		mlx->x = 0;
		while (mlx->x < WIN_WIDTH)
		{
			i = (2 * (mlx->x + 0.5) / (float)WIN_WIDTH - 1);
			j = (1 - 2 * (mlx->y + 0.5) / (float)WIN_HEIGHT);
			while (mlx->map->light_count < mlx->map->nb_light)
			{
				create_ray(mlx, mlx->cam, i ,j);
				origin = mlx->cam->ray[mlx->map->light_count]->origin;
				direction = mlx->cam->ray[mlx->map->light_count]->direction;
				check_ray_objects(mlx, origin, direction);
				mlx->map->light_count++;
			}
			mlx->map->light_count = 0;
			mlx->x++;
		}
		mlx->y++;
	}
	return (0);
}

int			init_camera(t_mlx *mlx)
{
	t_cam 	*cam;
	t_ray	**ray_source;
	int		i;

	i = 0;
	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	mlx->cam = cam;
	if (init_data(mlx, mlx->map) == false)
	{
		ft_putstr("Error : cannot load image from this config file.\n");
		return(false);
	}
	mlx->map->begin_list = mlx->map->list;
	mlx->map->light_list = mlx->map->begin_list;
	if (!(ray_source = (t_ray **)malloc(sizeof(t_ray *) * mlx->map->nb_light)))
		return (-1);
	while (i < (mlx->map->nb_light))
	{
		if(!(ray_source[i] = (t_ray *)malloc(sizeof(t_ray))))
			return (-1);
		i++;
	}
	mlx->cam->ray = ray_source;
	mlx->map->light_count = 0;
	ray_loop(mlx);
	return (0);
}
