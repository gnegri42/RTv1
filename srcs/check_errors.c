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

static int	check_first_char(t_map *map, int i)
{
	if (map->content[i][0] < 'A' || map->content[i][0] > 'Z')
		return (false);
	return (true);
}

static int	check_cam(t_cam *cam, char *str)
{
	int		j;
	int		c;
	float		x;
	float		y;
	float		z;

	j = 0;
	c = 0;
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	x = atoi_custom(str, &j);
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	y = atoi_custom(str, &j);
	while (str[j] >= '0' && str[j] <= '9')
		j++;
	z = atoi_custom(str, &j);
	cam->cam_pos = vector_assign_values(x, y, z);
	return (0);
}

int			check_errors(t_mlx *mlx, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check_first_char(map, i) != true)
	{
		j = 0;
		j = skip_space(map->content[i], j);
		if (check_first_char(map, i) == true)
		{
			if (read_first_letters(map->content[i], j) == CAM)
			{
				if (check_cam(mlx->cam, map->content[i]) == false)
					return (false);
			}
			else if (read_first_letters(map->content[i], j) != 0)
			{
				if (read_objects(mlx, map, map->content[i]) == false)
					return (false);
			}
		}
		i++;
	}
	return (true);
}
