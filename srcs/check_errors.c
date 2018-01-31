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

static int	check_first_char(t_map map, int i)
{
	if (map->content[i][0] < 'A' || map->content[i][0] > 'Z')
		return (false);
	return (true);
}

static int	check_win(t_map map, t_cam *cam)

{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check_first_char(map, i) != true)
		i++;
	while (map->content[i][j] != ':')
		j++;
	j = skip_space(map->content[i], j);
	WIN_WIDTH = atoi_custom(map->content[i], &j);
	while (map->content[i][j] != ':')
		j++;
	j = skip_space(map->content[i], j);
	WIN_HEIGHT = atoi_custom(map->content[i], &j);
}

int			check_errors(t_mlx *mlx, t_map *map)
{
	if (check_win(map, mlx->cam) == false)
		return (false);
}
