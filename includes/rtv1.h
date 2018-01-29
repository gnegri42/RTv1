/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmuselet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:15:36 by bmuselet          #+#    #+#             */
/*   Updated: 2018/01/29 12:15:38 by bmuselet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

# define WIN_WIDTH		800
# define WIN_HEIGHT		600

# define BLACK 0x000000
# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500
# define RED 0xFF0000

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

typedef	struct 		s_sphere
{
	t_vec3			*position;
	double			rayon;
}					t_sphere;

typedef	struct 		s_cam
{
	t_vec3			*camPos;
	t_vec3			*viewDir;
	double			screenDist;
	t_vec3			screenCenter;
}					t_cam;

typedef	struct		s_ray
{
	t_vec3			*origin;
	t_vec3			*destination;
	double			length;
}					t_ray;

typedef struct		s_map
{
	char			*str;
	char			**content;
	int				nb_line;
}					t_map;

typedef struct		s_img
{
	void			*img;
	int				*str_img;
	int				bpp;
	int				s_l;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_map			*map;
	t_cam			*cam;
}					t_mlx;

int			ft_reader(int argc, char *argv, t_map *map);
int			ft_init_camera(t_mlx *mlx);


#endif
