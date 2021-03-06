/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:20:54 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/29 17:28:19 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <stdio.h>
static int	img_loop(t_mlx *mlx, t_img *img)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "RTv1 42");
	img->img = mlx_new_image(mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	img->str_img = (int *)mlx_get_data_addr(img->img,
		&(img->bpp), &(img->s_l), &(img->endian));
	if (init_camera(mlx) == false)
		return (-1);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L << 0, key_events, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, red_cross, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_img	*img;
	t_map	*map;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (-1);
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (-1);
	mlx->map = map;
	mlx->img = img;
	mlx->map->shadow = 0;
	if (ft_reader(argc, argv[1], map) != 0)
		return (-1);
	if (img_loop(mlx, img) == -1)
		return (-1);
	return (0);
}
