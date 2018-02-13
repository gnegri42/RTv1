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

static int	check_ray_objects(t_mlx *mlx, float x, float y)
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

static int	create_ray(t_cam *cam, float i, float j)
{

	cam->ray->origin = vector_assign_values(cam->cam_pos.x, cam->cam_pos.y, cam->cam_pos.z);
	cam->forward = vector_substraction(cam->view_dir, cam->cam_pos);
	cam->forward = vector_normalize(cam->forward);
	cam->right = vector_cross((t_vec3){0.0, 1.0, 0.0}, cam->forward);
	cam->right = vector_normalize(cam->right);
	cam->up = vector_cross(cam->forward, cam->right);
	cam->ray->direction = (t_vec3){i * cam->right.x + j * cam->up.x + FOV * cam->forward.x, i * cam->right.y + j * cam->up.y
		+ FOV * cam->forward.y, i * cam->right.z + j * cam->up.z + FOV * cam->forward.z};
	cam->ray->direction = vector_normalize(cam->ray->direction);
	cam->ray->length = 1000000000000;
	return (0);
}

int	ray_loop(t_mlx *mlx)
{
	float 	x;
	float 	y;
	float 	i;
	float	j;
	t_ray	*ray;

	y = 0;
	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (-1);
	mlx->cam->ray = ray;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (x == 0 && y ==0.25f * WIN_HEIGHT)
                ft_putstr("25 percent completed !\n");

            if (x == 0 && y ==0.5f * WIN_HEIGHT)
                ft_putstr("50 percent completed !\n");

            if (x == 0 && y ==0.75f * WIN_HEIGHT)
                ft_putstr("75 percent completed !\n");

            if (x == 0 && y == WIN_HEIGHT - 1)
                ft_putstr("100 percent completed !\n");
			i = (2 * (x + 0.5) / (float)WIN_WIDTH - 1);
			j = (1 - 2 * (y + 0.5) / (float)WIN_HEIGHT);
			create_ray(mlx->cam, i ,j);
			check_ray_objects(mlx, x, y);
			x++;
		}
		y++;
	}
	return(0);
}

int			init_camera(t_mlx *mlx)
{
	t_cam 	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	mlx->cam = cam;
	if (init_data(mlx, mlx->map) == false)
	{
		ft_putstr("Error : cannot load image from this config file.\n");
		return(false);
	}
	mlx->map->begin_list = mlx->map->list;
	ray_loop(mlx);
	return (0);
}
