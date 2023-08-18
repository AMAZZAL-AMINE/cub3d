/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:25:35 by rouali            #+#    #+#             */
/*   Updated: 2023/08/18 20:55:45 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "./gnln/get_next_line.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_pixle;

typedef struct s_vars
{
	char	**map;
	void	*mlx;
	void	*win;
	t_pixle	*img;
	char	*add;
	int		key;
}				t_vars;

/* ############### Display W & H ############### */
typedef struct s_display_win
{
	int	w;
	int	h;

}	t_dis;

/* ############### Direction X & Y ############### */
struct s_direction
{
	int	x;
	int	y;
} dir;

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

/* ############### cub3D.c ############### */
/* ############### ft_split.c ############### */
char	**ft_split(char const *s, char c);

/* ############### draw_map.c ############### */
void	draw(t_vars *vars, int color);
void	put_pxl(t_vars *vars);

/* ############### libft_utils.c ############### */
int		ft_count(char **map);
int		f_strlen(char **map);

/* ############### hook.c ############### */
int		ft_close(void);
int		key_hook(int keycode, 	t_vars *vars);
void	ft_move(t_vars *vars);

#endif
