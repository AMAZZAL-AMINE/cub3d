/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/09/17 17:50:43 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

typedef struct t_textures_data
{
	float	y;
	float	x;
	float	y2;
	float	pos_tile_x;
	float	pos_tile_y;
	float	pos_txtr_y;
	float	pos_txtr_x;
	t_pixle	*img;
}	t_tex;

void	set_textures_in_correct_derection(t_tex *data, t_vars *vars)
{
	if (data->pos_tile_x > (vars->win_size - 0.001))
	{
		data->img = vars->img_pix2;
		data->pos_txtr_x = ((data->pos_tile_y) * \
			(data->img->w / vars->win_size));
	}
	else if (data->pos_tile_y > (vars->win_size - 0.001))
	{
		data->img = vars->img_pix;
		data->pos_txtr_x = ((data->pos_tile_x) * \
			(data->img->w / vars->win_size));
	}
	else if (data->pos_tile_x < 0.001)
	{
		data->img = vars->img_pix3;
		data->pos_txtr_x = ((data->pos_tile_y) * \
			(data->img->w / vars->win_size));
	}
	else if (data->pos_tile_y < 0.001)
	{
		data->img = vars->img_pix1;
		data->pos_txtr_x = ((data->pos_tile_x) * \
			(data->img->w / vars->win_size));
	}
}

void	rendring_textures_init(t_tex *data, t_vars *vars, \
	float tall, t_point p1)
{
	data->y = p1.y;
	data->y2 = 0;
	data->img = vars->img_pix;
	if (tall > vars->dis.h / 2)
		data->y2 = tall - (vars->dis.h / 2);
	data->pos_tile_y = (vars->end_y - ((int)vars->end_y / vars->win_size) \
		* (vars->win_size));
	data->pos_tile_x = (vars->end_x - ((int)vars->end_x / vars->win_size) \
		* (vars->win_size));
	set_textures_in_correct_derection(data, vars);
	if (data->pos_tile_y < 0)
		data->pos_tile_y = 0;
	if (data->pos_tile_x < 0)
		data->pos_tile_x = 0;
}

void	rendring_textures(t_vars *vars, t_point p1, \
	t_point p2, float tall)
{
	t_tex	data;

	rendring_textures_init(&data, vars, tall, p1);
	while (data.y < p2.y)
	{
		data.x = p1.x;
		data.pos_txtr_y = ((data.y2) * ((data.img->h / 2) / tall));
		while (data.x <= p2.x)
		{
			if (data.x < vars->dis.w && data.pos_txtr_x < \
				data.img->w && data.pos_txtr_y < data.img->h)
				my_mlx_pixel_put(vars, data.x, data.y, \
					gety_pix_from_img(data.img, data.pos_txtr_x, \
					data.pos_txtr_y));
			data.x++;
		}
		data.y2++;
		data.y++;
	}
}

void	put_pxl(t_vars *vars)
{
	vars->dir.x = 0;
	vars->dir.y = 0;
	rendring_rays(vars);
}
