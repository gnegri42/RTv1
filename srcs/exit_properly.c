/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_properly.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:20:47 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/31 17:20:50 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	rtv1_free_map(t_mlx *mlx)
{
	int				x;

	x = 0;
	while (x < mlx->map->nb_line)
		free(mlx->map->content[x++]);
	mlx->map->sphere ? free(mlx->map->sphere) : (0);
//	mlx->map->cylindre ? free(mlx->map->cylindre ) : (0);
	free(mlx->map->str);
}

int			exit_properly(t_mlx *mlx)
{
	mlx->map->content ? rtv1_free_map(mlx) : (0);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}
