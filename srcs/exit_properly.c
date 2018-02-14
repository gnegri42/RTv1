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

/*static void	rtv1_free_list(t_object_list *list)
{
	t_object_list	*tmp;

	tmp = list;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}*/

int			exit_properly(t_mlx *mlx)
{
	free(mlx->map->str);
//	mlx->map->list ? rtv1_free_list(mlx->map->list) : (0); /// ca fait segfault mais on en a besoin
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	// tableau de ray a free
}

int			red_cross(t_mlx *mlx)
{
	exit_properly(mlx);
	exit(0);
	return (0);
}
