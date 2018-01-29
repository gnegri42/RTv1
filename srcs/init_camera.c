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

int	init_camera(t_mlx *mlx)
{
	t_cam 	*cam;
	t_vec3	v1;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	mlx->cam = cam;
	cam->camPos = vector_assign_values(1.0, 2.0, 3.0);
	cam->viewDir = vector_assign_values(4.0, 5.0, 6.0);
	cam->screenDist = 10;
	//cam->screenCenter = (cam->camPos + cam->viewDir * cam->screenDist);
	v1 = vector_float_multiplication(cam->viewDir, cam->screenDist);
	cam->screenCenter = vector_addition(cam->camPos, v1);
	return (0);
}