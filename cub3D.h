/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:27:54 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/17 12:55:42 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "./gnln/get_next_line.h"
# include <math.h>

# define MOVE_SPEED 20
# define ROTATE_SPEED 8
# define RADIAN 0.0174533
# define PI 3.14
# define ZOOM 2
# define FOV 60
# define W_WIDTH 1560
# define W_HEIGHT 1050
# define PIXEL_SIZE 50

typedef struct t_check_rgb
{
	char	**splited;
	int		count;
	int		index;
	int		checker;
}	t_check_rgb;

typedef struct t_img
{
	char	**no;
	char	**so;
	char	**we;
	char	**ea;
}	t_img;

typedef struct map_color_rgb
{
	char	**floor;
	char	**ceil;
}	t_rgb;

typedef struct map_data
{
	t_img	*img;
	t_rgb	*rgb;
	char	**map;
}	t_data;

typedef struct t_pars
{
	int		count;
	t_rgb	*rgb;
	t_img	*img;
	int		last_index;
	int		counter_args;
	int		check;
	int		stoped;
	int		index;
}	t_pars;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	w;
	float	h;
}	t_pixle;

typedef struct s_display_win
{
	int	w;
	int	h;
}	t_dis;

typedef struct s_direction
{
	float	x;
	float	y;
}	t_dir;

typedef struct t_point
{
	float	x;
	float	y;
}	t_point;

typedef struct t_rays_point
{
	float	x;
	float	y;
	float	dis;
}	t_rays_point;

typedef struct t_rays
{
	float	pos_x;
	float	pos_y;
	float	step_x;
	float	step_y;
	int		count;
}	t_ray;

typedef struct s_vars
{
	float				p_pos_x;
	float				p_pos_y;
	float				p_rotat;
	char				**map;
	void				*mlx;
	void				*win;
	t_pixle				*img;
	t_pixle				*img_pix;
	t_pixle				*img_pix1;
	t_pixle				*img_pix2;
	t_pixle				*img_pix3;
	t_rays_point		rays_point;
	t_ray				ray;
	t_dis				dis;
	t_point				p1;
	t_data				*pars_data;
	char				*add;
	int					key;
	int					win_size;
	float				fov;
	float				end_h_x;
	float				end_h_y;
	float				end_v_x;
	float				end_v_y;
	float				end_x;
	float				end_y;
	t_dir				dir;
}				t_vars;
void	check_horizontal(t_vars *vars, float engl);
void	check_vertical(t_vars *vars, float engl);
int		check_is_wall(t_vars *vars, float x, float y);
int		count_biggest_line(char **map);
int		create_trgb(int r, int g, int b);
char	**ft_split(char const *s, char c);
char	*ft_strndup(char const *str, size_t max);
int		strlen_2d_array(char **array);
char	**read_map(char *mapfile);
int		ft_atoi(const char *str);
void	free_double(char **array);
int		ft_isdigit(int nbr);
void	check_valid_map(t_data *data);
int		str_cmp(char *s1, char *s2);
int		parsing_map(t_data *data, char **map);
void	check_var_name(char **str, char *errmsg, t_check_rgb *data, char c);
void	err(char **str, char *errstr);
void	checker(int check, char **str, char *errmsg);
void	check_none_numbers(char **str, char *errmsg, t_check_rgb *data);
void	check_what_after_comma(char **str, char *errmsg, t_check_rgb *data);
void	check_range(char **str, char *errmsg, t_check_rgb *data);
void	split_map_line_redirection(char *line, t_data *data, \
	t_pars *pars, char *type);
void	split_map_line_floor(char *line, t_data *data, t_pars *pars);
void	split_map_line_ceil(char *line, t_data *data, t_pars *pars);
int		is_it_rgb(char c1, t_pars *pars, char **map);
char	**duplcate_map(char **oldmap);
void	print_map(t_data *data, char **map);
void	ft_move(t_vars *vars);
void	draw_floor(t_vars *vars);
void	draw_ceil(t_vars *vars);
int		check_south(char **sorth);
void	check_nswe(t_data *data);
int		error_fd_not_found(char *msg);
int		error_map(char *msg);
void	check_rgb(t_data *data);
void	check_content_of_map(char **map);
void	draw(t_vars *vars, int color);
void	put_pxl(t_vars *vars);
int		ft_count(char **map);
int		f_strlen(char **map);
int		ft_close(void);
int		key_hook(int keycode, t_vars *vars);
void	ft_move(t_vars *vars);
void	mlx_init_func(t_vars *vars, t_data *data);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	put_pxl_mini_map(t_vars *vars);
void	raycasting(t_vars *f, float engl);
void	draw_player_line_ray(t_point p1, t_point p2, t_vars *vars);
int		gety_pix_from_img(t_pixle *img_pix, int x, int y);
void	rendring_rays(t_vars *vars);
void	rendring_textures(t_vars *vars, t_point p1, \
	t_point p2, float tall);
void	init_textures(t_vars *vars);

#endif
