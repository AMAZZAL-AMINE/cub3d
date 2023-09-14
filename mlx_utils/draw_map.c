/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/09/14 16:15:21 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

//textures
void rendring_textures(t_vars *vars, t_point p1, t_point p2, __unused float tall, __unused float eng)
{
	float x, y;
	float y2;
	float pos_tile_x, pos_tile_y;
	float pos_txtr_x, pos_txtr_y;
	t_pixle *img;

  y = p1.y;
	y2 =  0;
	img = vars->img_pix;
	if (tall > vars->dis.h / 2)
		y2 = tall - (vars->dis.h / 2);
	pos_tile_y = (vars->end_y - ((int)vars->end_y / vars->win_size) * (vars->win_size));
	pos_tile_x = (vars->end_x - ((int)vars->end_x / vars->win_size) * (vars->win_size));
	if (pos_tile_x > (vars->win_size - 0.001)) {
		img = vars->img_pix2;
		pos_txtr_x = ((pos_tile_y) * (img->h / vars->win_size));
	}
	else if (pos_tile_y > (vars->win_size- 0.001))
	{
		img = vars->img_pix;
		pos_txtr_x = ((pos_tile_x) * (img->w / vars->win_size));
	}
	else if (pos_tile_x < 0.001) {
		img = vars->img_pix3;
		pos_txtr_x = ((pos_tile_y) * (img->h / vars->win_size));
	}
	else if (pos_tile_y < 0.001) {
		img = vars->img_pix1;
		pos_txtr_x = ((pos_tile_x) * (img->w / vars->win_size));
	}
	if (pos_tile_y < 0)
		pos_tile_y = 0;
	if (pos_tile_x < 0)
		pos_tile_x = 0;
	while (y < p2.y)
	{
		x = p1.x;
		pos_txtr_y = ((y2) * ((img->h / 2) / tall));
		// printf("x = %f y = %f\n", pos_txtr_x, pos_txtr_y);
		while (x <= p2.x)
		{
			if (x < vars->dis.w
			&& pos_txtr_x < img->w && pos_txtr_y < img->h)
				my_mlx_pixel_put(vars, x, y, gety_pix_from_img(img , pos_txtr_x, pos_txtr_y));
			x++;
		}
		y2++;
		y++;
	}
}


void draw_walls_3d(t_vars *vars, int rays, __unused float eng, float dis)
{
	t_point p1, p2;
	float tail, tall;

	tail = 1;
	p1.x = rays;
	p2.x = p1.x + tail;

	dis = dis * cosf((eng - vars->p_rotat) * (PI / 180));
	tall = (vars->dis.h * vars->win_size) / dis;
	p1.y = (vars->dis.h / 2) - tall;
	if (p1.y < 0)
		p1.y = 0;
	p2.y = (vars->dis.h / 2) + tall;
	if (p2.y >= vars->dis.h)
		p2.y = vars->dis.h;
	rendring_textures(vars, p1, p2, tall, eng);
}

void rendring_rays(t_vars *vars)
{
	float eng;
	float rays;

	eng = vars->p_rotat - (vars->fov / 2);
	if (eng > 360)
		eng -= 360;
	else if (eng < 0)
		eng += 360;
	rays = 0;
	while (rays < vars->dis.w)
	{
		eng += vars->fov / vars->dis.w;
		if (eng > 360)
			eng -= 360;
		else if (eng < 0)
			eng += 360;
		raycasting(vars, eng);
		draw_walls_3d(vars, rays, eng, vars->rays_point.dis);
		rays++;
	}
}

void put_pxl(t_vars *vars)
{
	vars->dir.x = 0;
	vars->dir.y = 0;
	rendring_rays(vars);
	// put_pxl_mini_map(vars);
}
