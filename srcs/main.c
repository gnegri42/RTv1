/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:20:54 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/29 12:26:22 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int	main(int argc, char **argv)
{
	t_img	img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (-1);
	mlx->img = img;
	if (ft_reader(argc, argv[1], map) != 0)
		return (-1);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolf3d 42");
	return (0);
}
