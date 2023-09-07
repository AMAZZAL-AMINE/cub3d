/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/09/07 13:39:36 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char *dst;
	int offset;

	offset = ((y * vars->img->line_length) +
						(x * (vars->img->bits_per_pixel / 8)));
	dst = vars->img->addr + offset;
	*(unsigned int *)dst = color;
}

void draw(t_vars *vars, int __unused color)
{
	float i;
	float j;

	i = 0;
	while (i < vars->win_size)
	{
		j = 0;
		while (j < vars->win_size)
		{
			my_mlx_pixel_put(vars, (dir.x * vars->win_size + i) / ZOOM, (dir.y * vars->win_size + j) / ZOOM, color);
			j++;
		}
		i++;
	}
}

int gety_pix_from_img(t_pixle *img_pix, int x, int y)
{
	char *dst;
	int offset;

	offset = ((y * img_pix->line_length) +
						(x * (img_pix->bits_per_pixel / 8)));
	dst = img_pix->addr + offset;
	return *(unsigned int *)dst;
}

void draw_cub_3d(t_vars *vars, t_point p1, t_point p2, __unused float tall)
{
	float x, y;
	float x2, y2;
	float pos_tile_x, pos_tile_y;
	float pos_txtr_x = 0.0, pos_txtr_y= 0.0;
	t_pixle *img;

	y = p1.y;
	y2 =  0;
	img = vars->img_pix;
	if (tall > vars->dis.h / 2)
		y2 = tall - (vars->dis.h / 2);
	pos_tile_y = (vars->end_y - ((int)vars->end_y / vars->win_size) * vars->win_size);
	pos_tile_x = (vars->end_x - ((int)vars->end_x / vars->win_size) * vars->win_size);
	printf("x = %f , y = %f\n", pos_tile_x, pos_tile_y);
	if (pos_tile_x >= 49.9) {
		img = vars->img_pix2;
		pos_txtr_x = ((pos_tile_y) * (img->h / vars->win_size));
	}
	else if (pos_tile_y >= 49.9)
	{
		img = vars->img_pix;
		pos_txtr_x = ((pos_tile_x) * (img->w / vars->win_size));
	}
	else if (pos_tile_x < 0.1) {
		img = vars->img_pix3;
		pos_txtr_x = ((pos_tile_y) * (img->h / vars->win_size));
	}
	else if (pos_tile_y <= 0.1) {
		img = vars->img_pix1;
		pos_txtr_x = ((pos_tile_x) * (img->w / vars->win_size));
		printf("DDDDD = %f\n", pos_txtr_x);
	}
	if (pos_tile_y < 0)
		pos_tile_y = 0;
	if (pos_tile_x < 0)
		pos_tile_x = 0;
	while (y < p2.y)
	{
		x2 = 0;
		x = p1.x;
		pos_txtr_y = ((y2) * ((img->h / 2) / tall));
		while (x <= p2.x)
		{
			if (x < vars->dis.w 
			&& pos_txtr_x <= img->w && pos_txtr_y < img->h)
				my_mlx_pixel_put(vars, x, y, gety_pix_from_img(img, pos_txtr_x, pos_txtr_y));
			x2++;
			x++;
		}
		y2++;
		y++;
	}
}

void draw_player_line_ray(t_point p1, t_point p2, t_vars *vars)
{
	float draw_x;
	float draw_y;
	float steps;
	float dst_x; // destance x
	float dst_y; // destance y

	dst_x = (p2.x - p1.x);
	dst_y = (p2.y - p1.y);
	draw_x = p1.x;
	draw_y = p1.y;
	vars->end_x = 0;
	vars->end_y = 0;
	if (fabs(dst_y) > fabs(dst_x))
		steps = fabs(dst_y);
	else
		steps = fabs(dst_x);
	dst_x = (dst_x / steps) * 0.1;
	dst_y = (dst_y / steps) * 0.1;
	int i = 0;
	while (i <= steps)
	{
		if ((vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)] != 0 && (vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)] == '1' || vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)] == ' ')) || !vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)])
		{
			vars->end_x = (draw_x - dst_x);
			vars->end_y = (draw_y - dst_y);
			break;
		}
		// float x = (draw_x + 1) / vars->win_size;
		// float y = (draw_y + 1) / vars->win_size;
		// if (vars->map[(int)y][(int)draw_x / vars->win_size] && \
		// 	((vars->map[(int)y][(int)draw_x / vars->win_size] == '1' && vars->map[(int)draw_y / vars->win_size][(int)x] == '1') || \
		// 	(vars->map[(int)y - 1][(int)draw_x / vars->win_size] == '1' && vars->map[(int)draw_y / vars->win_size][(int)x] == '1')))
		// {
		// 	vars->end_x = draw_x + dst_x + 50;
		// 	vars->end_y = draw_y + dst_y + 50;
		// 	break;
		// }
		draw_y += dst_y;
		draw_x += dst_x;
		i++;
	}
	vars->rays_point.dis = sqrtf(powf((vars->end_x - p1.x), 2) + powf((vars->end_y - p1.y), 2));
}

void draw_walls_3d(t_vars *vars, int rays, __unused float eng, float dis)
{
	t_point p1, p2;
	float tail, tall;

	tail = vars->dis.w / (vars->fov * 10) + 1;
	p1.x = rays * tail;
	p2.x = p1.x + tail;

	dis = dis * cosf((eng - vars->p_rotat) * (PI / 180));
	tall = (vars->dis.h * vars->win_size) / dis;
	p1.y = (vars->dis.h / 2) - tall;
	if (p1.y < 0)
		p1.y = 0;
	p2.y = (vars->dis.h / 2) + tall;
	if (p2.y >= vars->dis.h)
		p2.y = vars->dis.h;
	draw_cub_3d(vars, p1, p2, tall);
}

void steps_line_player(t_point p1, t_point p2, t_vars *vars)
{
	float eng;
	int rays;

	eng = vars->p_rotat - (vars->fov / 2);
	rays = 0;
	while (eng < vars->p_rotat + (vars->fov / 2))
	{
		p1.x = vars->p_pos_x * vars->win_size;
		p1.y = vars->p_pos_y * vars->win_size;
		p2.x = p1.x + (cos(eng * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
		p2.y = p1.y + (sin(eng * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
		draw_player_line_ray(p1, p2, vars);
		draw_walls_3d(vars, rays, eng, vars->rays_point.dis);
		eng += 0.1;
		rays++;
	}
}

void put_player_pixel(t_vars *vars)
{
	t_point p1;
	t_point p2;

	p1.x = vars->p_pos_x * vars->win_size;
	p1.y = vars->p_pos_y * vars->win_size;
	p2.x = p1.x + (cos(vars->p_rotat * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
	p2.y = p1.y + (sin(vars->p_rotat * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
	vars->p1 = p1;
	steps_line_player(p1, p2, vars);
}

void put_pxl(t_vars *vars)
{
	dir.x = 0;
	dir.y = 0;
	put_player_pixel(vars);
	// put_pxl_mini_map(vars);
}
