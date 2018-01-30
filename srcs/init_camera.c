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
#include <stdio.h>

static int	create_ray(t_mlx *mlx, t_cam *cam, int i, int j)
{
	t_ray	*ray;
	t_vec3	point_on_screen;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (-1);
	mlx->cam->ray = ray;
	point_on_screen = vector_addition(vector_addition(cam->p0, vector_int_product(vector_substraction(cam->p1, cam->p0), i)), 
		vector_int_product(vector_substraction(cam->p2, cam->p0), j));
	mlx->cam->ray->origin = vector_assign_values(mlx->cam->camPos.x, mlx->cam->camPos.y, mlx->cam->camPos.z);
	mlx->cam->ray->direction = vector_normalize(vector_substraction(point_on_screen, cam->camPos));
	mlx->cam->ray->length = 100000;
	return (0);
}

static int	ray_loop(t_mlx *mlx)
{
	int 	x;
	int 	y;
	int 	i;
	int 	j;
	

	y = 0;
	while (y < WIN_HEIGHT)
	{
		i = 0;
		j = 0;
		x = 0;
		while (x < WIN_WIDTH)
		{
			i = x / WIN_WIDTH;
			j = y / WIN_HEIGHT;
			create_ray(mlx, mlx->cam, i ,j);
			check_sphere(mlx, x, y);
			x++;
		}
		y++;
	}
	return(0);
}

int			init_camera(t_mlx *mlx)
{
	t_cam 	*cam;
	t_vec3	v1;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	mlx->cam = cam;
	cam->camPos = vector_assign_values(0, 0, -5);
	cam->viewDir = vector_assign_values(0, 0, 0);
	cam->screenDist = 100;
	v1 = vector_float_product(cam->viewDir, cam->screenDist);
	cam->screenCenter = vector_addition(cam->camPos, v1);
	v1 = vector_assign_values(-800, 800, 0);
	cam->p0 = vector_addition(cam->screenCenter, v1);
	v1 = vector_assign_values(800, 800, 0);
	cam->p1 = vector_addition(cam->screenCenter, v1);
	v1 = vector_assign_values (-800, -800, 0);
	cam->p2 = vector_addition(cam->screenCenter, v1);
	ray_loop(mlx);
	return (0);
}