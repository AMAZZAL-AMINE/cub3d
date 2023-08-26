/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/08/26 17:47:36 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	int offset = ((y * vars->img->line_length) + (x * (vars->img->bits_per_pixel / 8)));
	dst = vars->img->addr + offset;
	*(unsigned int*)dst = color;
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
			// my_mlx_pixel_put(vars, ((dir.x * vars->win_size) + 0) / 3, ((dir.y * vars->win_size)  +j) / 3, create_trgb(0,0,0));
			my_mlx_pixel_put(vars, (dir.x * vars->win_size + i), (dir.y * vars->win_size + j), color);
			j++;
		}
		// my_mlx_pixel_put(vars, ((dir.x * vars->win_size) + i) / 3, ((dir.y * vars->win_size)  + 0) / 3, create_trgb(0,0,0));
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
				my_mlx_pixel_put(vars, (dir.x * vars->win_size + x), (dir.y * vars->win_size + y), color);
			y++;
		}
		x++;
	}
}


void	draw_player_line_derection(t_point p1, t_point p2, t_vars *vars)
{
	float draw_x;
	float draw_y;
	
	float dst_x; //destance x
	float dst_y; //destance y

	float	steps; 
	
	dst_x = p2.x - p1.x; 
	dst_y = p2.y - p1.y;
	draw_x = p1.x;
	draw_y = p1.y;
	if (fabs(dst_y) > fabs(dst_x))
		steps = fabs(dst_y);
	else
		steps = fabs(dst_x);
	dst_x = dst_x / steps;
	dst_y = dst_y / steps;
	int i = 0;
	while (i < steps) {
		my_mlx_pixel_put(vars, draw_x, draw_y, create_trgb(255, 0, 0));
		draw_y += dst_y;
		draw_x += dst_x;
		i++;
	}
}

void	put_player_pixel(t_vars *vars) {
	float	tmp_x;
	float	tmp_y;
	t_point p1;
	t_point p2;

	p1.x = vars->p_pos_x * vars->win_size;
	p1.y = vars->p_pos_y * vars->win_size;
	p2.x = fabs(p1.x + (cos(vars->p_rotat * (PI / 180)) * vars->win_size));
	p2.y = fabs(p1.y + (sin(vars->p_rotat * (PI / 180)) * vars->win_size));
	vars->p1 = p1;
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
