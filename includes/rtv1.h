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

# define FOV 2

# define CAM 12
# define LIG 13
# define SPH 14
# define CYL 15
# define CON 16
# define PLA 17

typedef struct				s_vec_color3
{
	float						r;
	float						g;
	float						b;
}							t_vec_color3;

typedef struct				s_vec3
{
	float					x;
	float					y;
	float					z;
}							t_vec3;

typedef	struct 				s_light
{
	t_vec3					position;
	t_vec3					direction;
	float					intensity;
	t_vec_color3			color;
}							t_light;

typedef	struct 				s_cone
{
	t_vec3					position;
	t_vec3					direction;
	float					radius;
	float					albedo;
	t_vec_color3			color;
}							t_cone;

typedef	struct 				s_cylindre
{
	t_vec3					position;
	t_vec3					direction;
	float					radius;
	float					albedo;
	t_vec_color3			color;
}							t_cylindre;

typedef	struct 				s_plan
{
	t_vec3					position;
	t_vec3					rotation;
	float					albedo;
	t_vec_color3			color;
}							t_plan;

typedef	struct 				s_sphere
{
	t_vec3					position;
	float					radius;
	float					albedo;
	t_vec_color3			color;
}							t_sphere;

typedef	struct				s_object_list
{
	int						object_nb;
	int						type;
	t_sphere				sphere;
	t_plan					plan;
	t_cylindre				cylindre;
	t_cone					cone;
	t_light					light;
	struct s_object_list	*next;
}							t_object_list;

typedef	struct				s_ray
{
	t_vec3					origin;
	t_vec3					direction;
	float					length;
	int						sphere_intersection;
	int						plan_intersection;
	int						cylindre_intersection;
	int						cone_intersection;
	t_vec3 					hit_object_pos;
	t_vec_color3			hit_object_col;
	float					hit_object_radius;
}							t_ray;

typedef	struct 				s_cam
{
	t_vec3					cam_pos;
	t_vec3					view_dir;
	t_ray					*ray;
	t_vec3					forward;
	t_vec3					right;
	t_vec3					up;
}							t_cam;

typedef struct				s_map
{
	char					*str;
	char					**content;
	int						nb_line;
	t_object_list			*list;
	t_object_list			*begin_list;
	t_plan					*plan;
}							t_map;

typedef struct				s_img
{
	void					*img;
	int						*str_img;
	int						bpp;
	int						s_l;
	int						endian;
}							t_img;

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	t_img					*img;
	t_map					*map;
	t_cam					*cam;
}							t_mlx;

int				ft_reader(int argc, char *argv, t_map *map);
int				init_camera(t_mlx *mlx);
int				ray_loop(t_mlx *mlx);
int				light_ray(t_mlx *mlx);
int				init_data(t_mlx *mlx, t_map *map);
int 			init_object(t_object_list *new_elem, char *str, int o);
int 			init_light(t_object_list *new_elem, char *str);
t_vec3			vector_addition(t_vec3 v1, t_vec3 v2);
t_vec3 			vector_float_product(t_vec3 v1, float i);
t_vec3			vector_assign_values(float x, float y, float z);
t_vec3			vector_substraction(t_vec3 v1, t_vec3 v2);
t_vec3 			vector_int_product(t_vec3 v1, int i);
t_vec3			vector_product(t_vec3 v1, t_vec3 v2);
t_vec3			vector_normalize(t_vec3 v1);
float			vector_length(t_vec3 v1);
t_vec3 			vector_float_substraction(t_vec3 v1, float i);
t_vec3			vector_cross(t_vec3 v1, t_vec3 v2);
t_vec3			assign_vectors(char *str, int *j, t_vec3 vec);
t_vec_color3 	color_float_product(t_vec_color3 v1, float i);
t_vec_color3	vector_assign_colors(int r, int g, int b);
t_vec_color3	assign_colors(char *str, int *j, t_vec_color3 col);
t_vec_color3	color_product(t_vec_color3 v1, t_vec_color3 v2);
t_vec_color3	color_addition(t_vec_color3 v1, t_vec_color3 v2);
float			vector_dot_product(t_vec3 v1, t_vec3 v2);
int				sphere_intersection_init(t_mlx *mlx, int x, int y);
int				plan_intersection_init(t_mlx *mlx, float x, float y);
int				cylindre_intersection_init(t_mlx *mlx, float x, float y);
int				cone_intersection_init(t_mlx *mlx, float x, float y);
int				check_sphere(t_object_list *new_elem, char *str);
int				check_plan(t_object_list *new_elem, char *str);
int				check_cylindre(t_object_list *new_elem, char *str);
int				check_cone(t_object_list *new_elem, char *str);
void			draw(t_mlx *mlx , float x, float y);
void			redraw(t_mlx *mlx);
float			atoi_custom(const char *str, int *i);
int				atoi_color(const char *str, int *i);
int				skip_space(char *str, int i);
int				read_first_letters(char *str, int i);
int				count_int(char *str);
int				key_events(int keycode, t_mlx *mlx);
int				exit_properly(t_mlx *mlx);
int				red_cross(t_mlx *mlx);
int				rgb_to_hex(int r, int g, int b);
void			transformations(t_vec3 *position, char *str, int *j);
void			loop(char *str, int *j);


#endif
