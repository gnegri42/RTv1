/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:30:54 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/30 14:30:56 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
static int	translation_objects(int keycode, t_mlx *mlx)
{
	t_vec3	tmp_pos;

	if (keycode == 0)
		tmp_pos->pos = (t_vec3){mlx->cam->cam_pos_pos->pos.x + 10.0 * mlx->cam->right.x,
			mlx->cam->cam_pos->pos.y + 10.0 * mlx->cam->right.y, mlx->cam->cam_pos->pos.z + 10.0 * mlx->cam->right.z};
	else if (keycode == 2)
		mlx->cam->cam_pos->pos = (t_vec3){mlx->cam->cam_pos->pos.x - 10.0 * mlx->cam->right.x,
			mlx->cam->cam_pos->pos.y - 10.0 * mlx->cam->right.y, mlx->cam->cam_pos->pos.z - 10.0 * mlx->cam->right.z};
	else if (keycode == 1)
		mlx->cam->cam_pos->pos = (t_vec3){mlx->cam->cam_pos->pos.x - 10.0 * mlx->cam->up.x,
			mlx->cam->cam_pos->pos.y - 10.0 * mlx->cam->up.y, mlx->cam->cam_pos->pos.z - 10.0 * mlx->cam->up.z};
	else if (keycode == 13)
		mlx->cam->cam_pos->pos = (t_vec3){mlx->cam->cam_pos->pos.x + 10.0 * mlx->cam->up.x,
			mlx->cam->cam_pos->pos.y + 10.0 * mlx->cam->up.y, mlx->cam->cam_pos->pos.z + 10.0 * mlx->cam->up.z};
}*/
/*
static int	translation_camera_2(int keycode, t_mlx *mlx)
{
	if (keycode == 1)
	{
		mlx->cam->view_dir = (t_vec3){mlx->cam->view_dir.x - 10.0 * mlx->cam->up.x,
			mlx->cam->view_dir.y - 10.0 * mlx->cam->up.y, mlx->cam->view_dir.z - 10.0 * mlx->cam->up.z};
		mlx->cam->cam_pos = (t_vec3){mlx->cam->cam_pos.x - 10.0 * mlx->cam->up.x,
			mlx->cam->cam_pos.y - 10.0 * mlx->cam->up.y, mlx->cam->cam_pos.z - 10.0 * mlx->cam->up.z};
	}
	else if (keycode == 13)
	{
		mlx->cam->view_dir = (t_vec3){mlx->cam->view_dir.x + 10.0 * mlx->cam->up.x,
			mlx->cam->view_dir.y + 10.0 * mlx->cam->up.y, mlx->cam->view_dir.z + 10.0 * mlx->cam->up.z};
		mlx->cam->cam_pos = (t_vec3){mlx->cam->cam_pos.x + 10.0 * mlx->cam->up.x,
			mlx->cam->cam_pos.y + 10.0 * mlx->cam->up.y, mlx->cam->cam_pos.z - 10.0 * mlx->cam->up.z};
	}
	return (0);
}

static int	translation_camera(int keycode, t_mlx *mlx)
{
	mlx->cam->forward = vector_substraction(mlx->cam->view_dir, mlx->cam->cam_pos);
	vector_normalize(mlx->cam->forward);
	mlx->cam->right = vector_cross(mlx->cam->forward, (t_vec3){0.0, 1.0, 0.0});
	vector_normalize(mlx->cam->right);
	mlx->cam->up = vector_cross(mlx->cam->right, mlx->cam->forward);
	if (keycode == 0)
	{
		mlx->cam->view_dir = (t_vec3){mlx->cam->view_dir.x + 10.0 * mlx->cam->right.x,
			mlx->cam->view_dir.y + 10.0 * mlx->cam->right.y, mlx->cam->view_dir.z + 10.0 * mlx->cam->right.z};
		mlx->cam->cam_pos = (t_vec3){mlx->cam->cam_pos.x + 10.0 * mlx->cam->right.x,
			mlx->cam->cam_pos.y + 10.0 * mlx->cam->right.y, mlx->cam->cam_pos.z + 10.0 * mlx->cam->right.z};
	}
	else if (keycode == 2)
	{
		mlx->cam->view_dir = (t_vec3){mlx->cam->view_dir.x - 10.0 * mlx->cam->right.x,
			mlx->cam->view_dir.y - 10.0 * mlx->cam->right.y, mlx->cam->view_dir.z - 10.0 * mlx->cam->right.z};
		mlx->cam->cam_pos = (t_vec3){mlx->cam->cam_pos.x - 10.0 * mlx->cam->right.x,
			mlx->cam->cam_pos.y - 10.0 * mlx->cam->right.y, mlx->cam->cam_pos.z - 10.0 * mlx->cam->right.z};
	}
	translation_camera_2(keycode, mlx);
	return (0);
}*/

int			key_events(int keycode, t_mlx *mlx)
{
//	double	tmp_pos;

	if (keycode == 53)
		exit_properly(mlx);
//	translation_camera_objects(keycode, mlx);
	/*if (keycode == 123)
	{
		tmp_pos = mlx->cam->cam_pos.x;
		mlx->cam->cam_pos.x = mlx->cam->cam_pos.x * cosf(0.05) + mlx->cam->cam_pos.z * sinf(0.05);
		mlx->cam->cam_pos.z = tmp_pos * (-sinf(0.05)) + mlx->cam->cam_pos.z * cosf(0.05);
	}
	else if (keycode == 124)
	{
		tmp_pos = mlx->cam->cam_pos.x;
		mlx->cam->cam_pos.x = mlx->cam->cam_pos.x * cosf(-0.05) + mlx->cam->cam_pos.z * sinf(-0.05);
		mlx->cam->cam_pos.z = tmp_pos * (-sinf(-0.05)) + mlx->cam->cam_pos.z * cosf(-0.05);
	}
	else if (keycode == 125)
	{
		tmp_pos = mlx->cam->cam_pos.y;
		mlx->cam->cam_pos.y = mlx->cam->cam_pos.y * cosf(-0.05) + mlx->cam->cam_pos.z * (-sinf(-0.05));
		mlx->cam->cam_pos.z = tmp_pos * sinf(-0.05) + mlx->cam->cam_pos.z * cosf(-0.05);
	}
	else if (keycode == 126)
	{
		tmp_pos = mlx->cam->cam_pos.y;
		mlx->cam->cam_pos.y = mlx->cam->cam_pos.y * cosf(0.05) + mlx->cam->cam_pos.z * (-sinf(0.05));
		mlx->cam->cam_pos.z = tmp_pos * sinf(0.05) + mlx->cam->cam_pos.z * cosf(0.05);
	}
	translation_camera(keycode, mlx);
	redraw(mlx);*/
	return (0);
}
