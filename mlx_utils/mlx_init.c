/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:27:47 by rouali            #+#    #+#             */
/*   Updated: 2023/09/13 12:34:15 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_player_position(t_vars *vars)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (vars->map[count])
	{
		index = 0;
		while (vars->map[count][index])
		{
			if (vars->map[count][index] == 'N' || vars->map[count][index] == 'S' \
				|| vars->map[count][index] == 'E' || vars->map[count][index] == 'W')
			{
				vars->p_pos_y = count * vars->win_size;
				vars->p_pos_x = index * vars->win_size;
				return ;
			}
			index++;
		}
		count++;
	}	
	return ;
}

int	count_biggest_line(char **map)
{
	int	count;
	int	size;

	count = 0;
	size = ft_strlen(map[0]);
	while (map[count])
	{
		if (ft_strlen(map[count]) > size) {
			size = ft_strlen(map[count]);
		}
		count++;
	}	
	return size;
}

void init_textrs(t_vars *vars)
{
	int __unused w,h,w2,h2,w3,h3,w4,h4;
	char __unused *img1 = vars->pars_data->img->ea[1];
	char __unused *img2 = vars->pars_data->img->no[1];
	char __unused *img3 = vars->pars_data->img->so[1];
	char __unused *img4 = vars->pars_data->img->we[1];
	void __unused *gm = mlx_xpm_file_to_image(vars->mlx, img1, &w, &h);
	void __unused *gm2 = mlx_xpm_file_to_image(vars->mlx, img2, &w2, &h2);
	void __unused *gm3 = mlx_xpm_file_to_image(vars->mlx, img3, &w3, &h3);
	void __unused *gm4 = mlx_xpm_file_to_image(vars->mlx, img4, &w4, &h4);
	vars->img_pix = malloc(sizeof(t_pixle));
	vars->img_pix1 = malloc(sizeof(t_pixle));
	vars->img_pix2 = malloc(sizeof(t_pixle));
	vars->img_pix3 = malloc(sizeof(t_pixle));
		if (!gm || !gm2 || !gm3 || !gm4) { 
		printf("IM STUCK DADY, YOU CANT`T FIX ME  %p💔\n", gm);
		exit(0);
	}
	vars->img_pix->w = w;
	vars->img_pix->h = h;
	vars->img_pix->img = gm;
	vars->img_pix->addr = mlx_get_data_addr(vars->img_pix->img, &vars->img_pix->bits_per_pixel, &vars->img_pix->line_length, &vars->img_pix->endian);

	vars->img_pix1->w = w2;
	vars->img_pix1->h = h2;
	vars->img_pix1->img = gm2;
	vars->img_pix1->addr = mlx_get_data_addr(vars->img_pix1->img, &vars->img_pix1->bits_per_pixel, &vars->img_pix1->line_length, &vars->img_pix1->endian);

	vars->img_pix2->w = w3;
	vars->img_pix2->h = h3;
	vars->img_pix2->img = gm3;
	vars->img_pix2->addr = mlx_get_data_addr(vars->img_pix2->img, &vars->img_pix2->bits_per_pixel, &vars->img_pix2->line_length, &vars->img_pix2->endian);

	vars->img_pix3->w = w4;
	vars->img_pix3->h = h4;
	vars->img_pix3->img = gm4;
	vars->img_pix3->addr = mlx_get_data_addr(vars->img_pix3->img, &vars->img_pix3->bits_per_pixel, &vars->img_pix3->line_length, &vars->img_pix3->endian);
}

void	mlx_init_func(t_vars *vars, t_data *data)
{
	vars->pars_data = data;
	vars->map = data->map;
	vars->win_size = 50;
	get_player_position(vars);
	vars->img = malloc(sizeof(t_pixle));
	vars->mlx = mlx_init();
	vars->dis.w = W_WIDTH;
	vars->dis.h = W_HEIGHT;
	init_textrs(vars);
	vars->fov = FOV;
	vars->win = mlx_new_window(vars->mlx, vars->dis.w, \
		vars->dis.h, "33-34 hakma l3alam");
	vars->img->img = mlx_new_image(vars->mlx, vars->dis.w, vars->dis.h);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, \
		&vars->img->line_length, &vars->img->endian);
	draw_ceil(vars);
	draw_floor(vars);
	put_pxl(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img->img, 0, 0);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_loop(vars->mlx);
}
