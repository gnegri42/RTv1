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

int 	rgb_to_hex(int r, int g, int b)
{
    int rgb_num = ((r & 0xff) << 16)
        + ((g & 0xff) << 8)
        + (b & 0xff);
     return (rgb_num);
}

void	redraw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	ray_loop(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}

void	draw(t_mlx *mlx , double x, double y)
{
	int i;
	int color;
	
	color = light_ray(mlx);
	i = x + (y * WIN_WIDTH);
	mlx->img->str_img[i] = color;
}
