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
	check_sphere(mlx, x, y);
	//check_cylindre(mlx, x, y);
	return(0);
}

static int	create_ray(t_cam *cam, float i, float j)
{
	t_vec3	point_on_screen;
	
	point_on_screen = vector_addition(cam->p0, vector_addition(vector_float_product(vector_substraction(cam->p1, cam->p0), i), 
		vector_float_product(vector_substraction(cam->p2, cam->p0), j)));
	cam->ray->origin = vector_assign_values(cam->cam_pos.x, cam->cam_pos.y, cam->cam_pos.z);
	cam->ray->direction = vector_normalize(vector_substraction(point_on_screen, cam->cam_pos));
	cam->ray->length = 1000000000;
	return (0);
}

static int	ray_loop(t_mlx *mlx)
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
			i = x / WIN_WIDTH;
			j = y / WIN_HEIGHT;
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
	t_vec3	v1;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	mlx->cam = cam;
	/*cam->cam_pos = vector_assign_values(0, 0, 0);
	cam->view_dir = vector_assign_values(0, 0, 20);
	cam->screen_dist = 100;*/
	if (init_data(mlx, mlx->map) == false)
	{
		ft_putstr("Error : unable to read data from file");
		return(false);
	}
	v1 = vector_float_product(cam->view_dir, cam->screen_dist);
	cam->screen_center = vector_addition(cam->cam_pos, v1);
	v1 = vector_assign_values(-WIN_WIDTH, WIN_HEIGHT, 0);
	cam->p0 = vector_addition(cam->screen_center, v1);
	v1 = vector_assign_values(WIN_WIDTH, WIN_HEIGHT, 0);
	cam->p1 = vector_addition(cam->screen_center, v1);
	v1 = vector_assign_values (-WIN_WIDTH, -WIN_HEIGHT, 0);
	cam->p2 = vector_addition(cam->screen_center, v1);
	ray_loop(mlx);
	return (0);
}