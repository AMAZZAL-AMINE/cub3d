/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/08/28 17:14:26 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = ((y * vars->img->line_length) + \
		(x * (vars->img->bits_per_pixel / 8)));
	dst = vars->img->addr + offset;
	*(unsigned int *)dst = color;
}

void	draw(t_vars *vars, int color)
{
	float	i;
	float	j;

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

void	draw_cub_3d(t_vars *vars, t_point p1, t_point p2, int color)
{
	float	i;
	float	j;

	i = p1.y;
	while (i < p2.y)
	{
		j = p1.x;
		while (j < p2.x)
		{
			my_mlx_pixel_put(vars, j, i, color);
			j++;
		}
		i++;
	}
}

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

float	draw_player_line_derection(t_point p1, t_point p2, t_vars *vars)
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
					 || !vars->map[(int)(draw_y / vars->win_size)][(int)(draw_x / vars->win_size)]) {
			end_x = draw_x;
			end_y = draw_y;
			break;
		}
		my_mlx_pixel_put(vars, (int)draw_x / ZOOM, (int)draw_y / ZOOM, create_trgb(255, 0, 0));
		draw_y += dst_y;
		draw_x += dst_x;
		i++;
	}
	return (float)(sqrt((p1.x - end_x) * (p1.x - end_x) + (p1.y - end_y) * (p1.y - end_y)));
}

void	draw_walls_3d(t_vars __unused *vars, int __unused rays, float dis)
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
	printf("y1 = %f, y2 = %f\n", p1.y , p2.y);
	draw_cub_3d(vars, p1, p2, create_trgb(72, 35, 32));
}

void steps_line_player(t_point p1, t_point p2, t_vars *vars)
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
		float __unused dis = draw_player_line_derection(p1, p2, vars);
		draw_walls_3d(vars, rays, dis);
		eng += 0.1;
		rays++;
	}
}


void	put_player_pixel(t_vars *vars)
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
				draw (vars, create_trgb(255, 255, 255));
				dir.x = vars->p_pos_x;
				dir.y = vars->p_pos_y;
				draw_player (vars, create_trgb(0,0,0));
				draw_player_line_derection(p1,p2,vars);
				dir.x = tmp_x;
				dir.y = tmp_y;
			}
			dir.x++;
		}
		dir.y++;
	}
	steps_line_player(p1, p2, vars);
}

void	put_pxl(t_vars *vars)
{
	dir.y = 0;
	while (vars->map[(int)dir.y])
	{
		dir.x = 0;
		while (vars->map[(int)dir.y][(int)dir.x])
		{
			if (vars->map[(int)dir.y][(int)dir.x] == '1')
				draw (vars, create_trgb(140, 136, 247));
			else if (vars->map[(int)dir.y][(int)dir.x] == '0')
				draw (vars, create_trgb(255, 255, 255));
			dir.x++;
		}
		dir.y++;
	}
	dir.x = 0;
	dir.y = 0;
	put_player_pixel(vars);
}
