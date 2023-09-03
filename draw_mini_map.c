/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:15:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/03 18:45:15 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	draw_player(t_vars *vars, int color)
{
	int	radius;
	int	x;
	int	y;

	radius = 10;
	x = -radius;
	while (x < radius)
	{
		y = -radius;
		while (y < radius)
		{
			if ((x * x) + (y * y) < (radius * radius))
				my_mlx_pixel_put(vars, (dir.x * vars->win_size + x) / ZOOM, (dir.y * vars->win_size + y) / ZOOM, color);
			y++;
		}
		x++;
	}
}

void	draw_player_line_ray_mini_map(t_point p1, t_point p2, t_vars *vars)
{
	float	draw_x;
	float	draw_y;
	float	end_x;
	float	end_y;
	float	steps;
	float dst_x; //destance x
	float dst_y; //destance y

	dst_x = p2.x - p1.x; 
	dst_y = p2.y - p1.y;
	draw_x = p1.x;
	draw_y = p1.y;
	end_x = 0;
	end_y = 0;
	if (fabs(dst_y) > fabs(dst_x))
		steps = fabs(dst_y);
	else
		steps = fabs(dst_x);
	dst_x = dst_x / steps;
	dst_y = dst_y / steps;
	int i = 0;
	while (i < steps)
	{
		if ((vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)] != 0 \
			&& (vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)] == '1' \
			|| vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)] == ' '))
			|| !vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)])
		{
			vars->end_x = draw_x;
			vars->end_y = draw_y;
			break;
		}
		float x = (draw_x + 1) / vars->win_size;
		float y = (draw_y + 1) / vars->win_size;
		if (vars->map[(int)y][(int)draw_x / vars->win_size] && \
			((vars->map[(int)y][(int)draw_x / vars->win_size] == '1' && vars->map[(int)draw_y / vars->win_size][(int)x] == '1') || \
			(vars->map[(int)y - 1][(int)draw_x / vars->win_size] == '1' && vars->map[(int)draw_y / vars->win_size][(int)x] == '1')))
		{
			vars->end_x = draw_x;
			vars->end_y = draw_y;
			break;
		}
		my_mlx_pixel_put(vars, (int)draw_x / ZOOM, (int)draw_y / ZOOM, create_trgb(255, 255, 0));
		draw_y += dst_y;
		draw_x += dst_x;
		i++;
	}
	vars->rays_point.dis =  sqrt((p1.x - end_x) * (p1.x - end_x) + (p1.y - end_y) * (p1.y - end_y)) + vars->win_size;
}

void	draw_walls_3d_mini_map(t_vars __unused *vars, int __unused rays, float dis)
{
	t_point __unused	p1;
	t_point __unused	p2;
	float 			tail;
	float			tall;
	tail = vars->dis.w / (vars->fov * 10);
	p1.x = rays * tail;
	p2.x = p1.x + tail;
	tall = (vars->dis.h * vars->win_size) / dis;
	p1.y = (vars->dis.h / 2) - tall;
	if (p1.y < 0)
		p1.y = 0;
	p2.y = (vars->dis.h / 2) + tall;
	if (p2.y >= vars->dis.h)
		p2.y = vars->dis.h - 1;
}

void steps_line_player_mini_map(t_point p1, t_point p2, t_vars *vars)
{
	float eng;
	int		rays;
	
	vars->fov = 60;
	eng = vars->p_rotat - (vars->fov / 2);
	rays = 0;
	while(eng <= vars->p_rotat + (vars->fov / 2))
	{
		p1.x = vars->p_pos_x * vars->win_size;
		p1.y = vars->p_pos_y * vars->win_size;
		p2.x = p1.x + (cos(eng * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
		p2.y = p1.y + (sin(eng * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
		draw_player_line_ray_mini_map(p1, p2, vars);
		eng += 0.1;
		rays++;
	}
}

void	put_player_pixel_mini_map(t_vars *vars)
{
	float	tmp_x;
	float	tmp_y;
	t_point p1;
	t_point p2;

	p1.x = vars->p_pos_x * vars->win_size;
	p1.y = vars->p_pos_y * vars->win_size;
	p2.x = p1.x + (cos(vars->p_rotat * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
	p2.y = p1.y + (sin(vars->p_rotat * (PI / 180)) * vars->win_size * (vars->dis.w + vars->dis.h));
	vars->p1 = p1;
	//draw  player derection ras
	while (vars->map[(int)dir.y])
	{
		dir.x = 0;
		while (vars->map[(int)dir.y][(int)dir.x])
		{
			if (vars->map[(int)dir.y][(int)dir.x] == 'N' || vars->map[(int)dir.y][(int)dir.x] == 'E' \
				|| vars->map[(int)dir.y][(int)dir.x] == 'W' || vars->map[(int)dir.y][(int)dir.x] == 'S')
			{
				tmp_x = dir.x;
				tmp_y = dir.y;
				draw (vars, create_trgb(119,136,153));
				dir.x = vars->p_pos_x;
				dir.y = vars->p_pos_y;
				draw_player (vars, create_trgb(0,0,0));
				dir.x = tmp_x;
				dir.y = tmp_y;
			}
			dir.x++;
		}
		dir.y++;
	}
	steps_line_player_mini_map(p1, p2, vars);
}

void	put_pxl_mini_map(t_vars *vars)
{
	dir.y = 0;
	while (vars->map[(int)dir.y])
	{
		dir.x = 0;
		while (vars->map[(int)dir.y][(int)dir.x])
		{
			if (vars->map[(int)dir.y][(int)dir.x] == '1')
				draw (vars, create_trgb(0,0,0));
			else if (vars->map[(int)dir.y][(int)dir.x] == '0')
				draw (vars, create_trgb(119,136,153)); 
			dir.x++;
		}
		dir.y++;
	}
	dir.x = 0;
	dir.y = 0;
	put_player_pixel_mini_map(vars);
}
