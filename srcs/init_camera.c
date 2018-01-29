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

int	ft_init_camera(t_mlx *mlx)
{
	t_cam *cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	mlx->cam = cam;
	cam->camPos = (1, 2, 3);
	cam->viewDir = (4, 5, 6);
	cam->screenDist = 100;
	cam->screenCenter = (cam->camPos + cam->viewDir * cam->screenDist);
	printf("%f\n", cam->screenCenter.x);
	printf("%f\n", cam->screenCenter.y);
	printf("%f\n", cam->screenCenter.z);
	return (0);
}