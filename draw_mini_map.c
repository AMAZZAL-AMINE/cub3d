/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:15:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/13 11:45:23 by mamazzal         ###   ########.fr       */
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
				my_mlx_pixel_put(vars, (vars->p_pos_x + x) / ZOOM, (vars->p_pos_y + y) / ZOOM, color);
			y++;
		}
		x++;
	}
}
void draw_player_line_ray_mini_map(t_point p1, t_point p2, t_vars *vars)
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
	if (fabs(dst_y) > fabs(dst_x))
		steps = fabs(dst_y);
	else
		steps = fabs(dst_x);
	dst_x = (dst_x / steps);
	dst_y = (dst_y / steps);
	int i = 0;
	while (i <= steps)
	{
		if ( draw_x / ZOOM > 0 && draw_x / ZOOM < vars->dis.w && draw_y / ZOOM > 0 && draw_y / ZOOM < vars->dis.h)
			my_mlx_pixel_put(vars, (int)draw_x / ZOOM, (int)draw_y / ZOOM, create_trgb(255, 255, 0));
		draw_y += dst_y;
		draw_x += dst_x;
		i++;
	}
}


void rendring_rays_mini_map(t_vars *vars)
{
	float eng;
	int rays;
	t_point p1;
	t_point p2;

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
	while (vars->map[(int)vars->dir.y])
	{
		vars->dir.x = 0;
		while (vars->map[(int)vars->dir.y][(int)vars->dir.x])
		{
			if (vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'N' || vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'E' \
				|| vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'W' || vars->map[(int)vars->dir.y][(int)vars->dir.x] == 'S')
			{
				draw (vars, create_trgb(119,136,153));
				draw_player (vars, create_trgb(0,0,0));
			}
			vars->dir.x++;
		}
		vars->dir.y++;
	}
	rendring_rays_mini_map(vars);
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
				draw (vars, create_trgb(0,0,0));
			else if (vars->map[(int)vars->dir.y][(int)vars->dir.x] == '0')
				draw (vars, create_trgb(119,136,153)); 
			vars->dir.x++;
		}
		vars->dir.y++;
	}
	vars->dir.x = 0;
	vars->dir.y = 0;
	put_player_pixel_mini_map(vars);
}
