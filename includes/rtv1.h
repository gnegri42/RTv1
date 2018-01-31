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
# define WIN_HEIGHT		800
# define true			0
# define false			-1

# define BLACK 0x000000
# define BLUE 0x0041FF
# define WHITE 0xFFFFFF
# define GREEN 0x25FF50
# define ORANGE 0x00FFA500
# define RED 0xFF0000

# define WIN 11
# define CAM 12
# define LIG 13
# define SPH 14
# define CYL 15
# define CON 16
# define PLA 17

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef	struct 		s_sphere
{
	t_vec3			position;
	float			radius;
}					t_sphere;

typedef	struct 		s_sphere
{
	t_vec3			position;
	float			radius;
}					t_sphere;

typedef	struct		s_ray
{
	t_vec3			origin;
	t_vec3			direction;
	float			length;
	int				sphere_intersection;
}					t_ray;

typedef	struct 		s_cam
{
	t_vec3			camPos;
	t_vec3			viewDir;
	float			screenDist;
	t_vec3			screenCenter;
	t_vec3			p0;
	t_vec3			p1;
	t_vec3			p2;
	t_ray			*ray;
}					t_cam;

typedef struct		s_map
{
	char			*str;
	char			**content;
	int				nb_line;
	t_sphere		*sphere;
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

int			ft_reader(int argc, char *argv, t_mlx *mlx, t_map *map);
int			init_camera(t_mlx *mlx);
t_vec3		vector_addition(t_vec3 v1, t_vec3 v2);
t_vec3 		vector_float_product(t_vec3 v1, float i);
t_vec3		vector_assign_values(float x, float y, float z);
t_vec3		vector_substraction(t_vec3 v1, t_vec3 v2);
t_vec3 		vector_int_product(t_vec3 v1, int i);
t_vec3		vector_product(t_vec3 v1, t_vec3 v2);
t_vec3		vector_normalize(t_vec3 v1);
float		vector_dot_product(t_vec3 v1, t_vec3 v2);
int			check_sphere(t_mlx *mlx, int x, int y);
int			check_cylindre(t_mlx *mlx, int x, int y);
void		draw(t_mlx *mlx , int x, int y);
int			check_errors(t_mlx *mlx, t_map *map);
int			atoi_custom(const char *str, int *i);
int			skip_space(char *str, int i);
int			read_first_letters(char *str, int i);
int			init_objects(t_mlx *mlx, int o);
int			read_objects(t_mlx *mlx, t_map *map, char *str);
int 		init_light(t_mlx *mlx, char *str);
int 		init_sphere(t_mlx *mlx, char *str);
int 		init_cylindre(t_mlx *mlx, char *str);
int 		init_cone(t_mlx *mlx, char *str);
int 		init_plan(t_mlx *mlx, char *str);
int			count_int(char *str);

#endif
