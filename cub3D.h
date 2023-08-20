/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:27:54 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:03:34 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "./gnln/get_next_line.h"

/*PAESING STRUCTER*/
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
/*END PARSING STRUCTER*/

/*MLX UTILIS STRUCTER*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_pixle;

typedef struct s_display_win
{
	int	w;
	int	h;
}	t_dis;

typedef struct s_vars
{
	char	**map;
	void	*mlx;
	void	*win;
	t_pixle	*img;
	t_dis	dis;
	char	*add;
	int		key;
}				t_vars;

struct s_direction
{
	int	x;
	int	y;
} dir;
/*END MLX UTILIS STRUCTER*/

/* ############### cub3D.c ############### */
/* ############### ft_split.c ############### */
char	**ft_split(char const *s, char c);
char	*ft_strndup(char const *str, size_t max);
int		strlen_2d_array(char **array);
char	**read_map(char *mapfile);
int		ft_atoi(const char *str);
void	free_double(char **array);
int		ft_isdigit(int nbr);
void	check_valid_map(t_data *data);
int		str_cmp(char *s1, char *s2);
// PARSING 
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
// check MAP
int		check_south(char **sorth);
void	check_nswe(t_data *data);
int		error_fd_not_found(char *msg);
int		error_map(char *msg);
void	check_rgb(t_data *data);
void	check_content_of_map(char **map);

/* ############### draw_map.c ############### */
void	draw(t_vars *vars, int color);
void	put_pxl(t_vars *vars);

/* ############### libft_utils.c ############### */
int		ft_count(char **map);
int		f_strlen(char **map);

/* ############### hook.c ############### */
int		ft_close(void);
int		key_hook(int keycode, t_vars *vars);
void	ft_move(t_vars *vars);
void	mlx_init_func(t_vars vars, t_data *data);

#endif
