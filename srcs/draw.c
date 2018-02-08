/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:11:50 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/30 14:11:51 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	redraw(t_mlx *mlx)
{
/*	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->str_img = (int *)mlx_get_data_addr(mlx->img->img,
		&(mlx->img->bpp), &(mlx->img->s_l), &(mlx->img->endian));*/
	ray_loop(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

void	draw(t_mlx *mlx , float x, float y, int color)
{
	int i;

	i = x + (y * WIN_WIDTH);
	mlx->img->str_img[i] = color;
}