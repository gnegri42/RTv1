/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnegri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 11:07:35 by gnegri            #+#    #+#             */
/*   Updated: 2018/01/31 11:07:37 by gnegri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static int	check_window(t_mlx *mlx, t_map *map)
{
	int		i;

	i = 0;
	while (map->content[1][i] != ':')
		i++;
	i = skip_space(map->content[1], i);
	if (map->content[1][i] < '0' || map->content[1][i] > '9' || map->content[1][i] == '\0')
		return (0);
	WIN_WIDTH = ft_atoi_custom(map->content[1], &i);
	i = 0;
	while (map->content[2][i] != ':')
		i++;
	i = skip_space(map->content[1], i);
	if (map->content[2][i] < '0' || map->content[2][i] > '9' || map->content[2][i] == '\0')
		return (0);
	WIN_HEIGHT = ft_atoi_custom(map->content[2], &i);
}

int			check_errors(t_mlx *mlx, t_map *map)
{
	if (check_window(mlx, map) == 0)
		return (0);
}
