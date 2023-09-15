/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:15:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/15 22:46:42 by mamazzal         ###   ########.fr       */
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
				my_mlx_pixel_put(vars, (vars->p_pos_x + x) / ZOOM, \
				(vars->p_pos_y + y) / ZOOM, color);
			y++;
		}
		x++;
	}
}

typedef struct t_utilis_vars
{
	float	draw_x;
	float	draw_y;
	float	steps;
	float	dst_x;
	float	dst_y;
	int		i;
}	t_utilis;

void	draw_player_line_ray_mini_map(t_point p1, t_point p2, t_vars *vars)
{
	t_utilis	ut;

	ut.dst_x = (p2.x - p1.x);
	ut.dst_y = (p2.y - p1.y);
	ut.draw_x = p1.x;
	ut.draw_y = p1.y;
	if (fabs(ut.dst_y) > fabs(ut.dst_x))
		ut.steps = fabs(ut.dst_y);
	else
		ut.steps = fabs(ut.dst_x);
	ut.dst_x = (ut.dst_x / ut.steps);
	ut.dst_y = (ut.dst_y / ut.steps);
	ut.i = 0;
	while (ut.i <= ut.steps)
	{
		if (ut.draw_x / ZOOM > 0 && ut.draw_x / ZOOM < vars->dis.w \
			&& ut.draw_y / ZOOM > 0 && ut.draw_y / ZOOM < vars->dis.h)
			my_mlx_pixel_put(vars, (int)ut.draw_x / ZOOM, \
			(int)ut.draw_y / ZOOM, \
			create_trgb(255, 255, 0));
		ut.draw_y += ut.dst_y;
		ut.draw_x += ut.dst_x;
		ut.i++;
	}
}

void	rendring_rays_mini_map(t_vars *vars, t_point p1, t_point p2)
{
	float	eng;
	int		rays;

	eng = vars->p_rotat - (vars->fov / 2);
	if (eng > 360)
		eng -= 360;
	else if (eng < 0)
		eng += 360;
	rays = 0;
	while (rays < vars->dis.w / 2)
	{
		raycasting(vars, eng);
		p1.x = vars->p_pos_x;
		p1.y = vars->p_pos_y;
		p2.x = vars->end_x;
		p2.y = vars->end_y;
		draw_player_line_ray_mini_map(p1, p2, vars);
		eng += 0.1;
		if (eng > 360)
			eng -= 360;
		else if (eng < 0)
			eng += 360;
		rays++;
	}
}

void	put_player_pixel_mini_map(t_vars *vars)
{
	t_point	p1;
	t_point	p2;

	p1.x = 0;
	p1.y = 0;
	p2.x = 0;
	p2.y = 0;
	while (vars->map[(int)vars->dir.y])
	{
		vars->dir.x = 0;
		while (vars->map[(int)vars->dir.y][(int)vars->dir.x])
		{
			if (vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'N' \
				|| vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'E' \
				|| vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'W' \
				|| vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'S')
			{
				draw(vars, create_trgb(119, 136, 153));
				draw_player(vars, create_trgb(0, 0, 0));
			}
			vars->dir.x++;
		}
		vars->dir.y++;
	}
	rendring_rays_mini_map(vars, p1, p2);
}

void	put_pxl_mini_map(t_vars *vars)
{
	vars->dir.y = 0;
	while (vars->map[(int)vars->dir.y])
	{
		vars->dir.x = 0;
		while (vars->map[(int)vars->dir.y][(int)vars->dir.x])
		{
			if (vars->map[(int)vars->dir.y][(int)vars->dir.x] == '1')
				draw(vars, create_trgb(0, 0, 0));
			else if (vars->map[(int)vars->dir.y][(int)vars->dir.x] == '0')
				draw(vars, create_trgb(119, 136, 153));
			vars->dir.x++;
		}
		vars->dir.y++;
	}
	vars->dir.x = 0;
	vars->dir.y = 0;
	put_player_pixel_mini_map(vars);
}
