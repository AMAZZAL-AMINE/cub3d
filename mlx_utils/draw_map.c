/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/08/25 18:22:11 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include <math.h>

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	int offset = ((y * vars->img->line_length) + (x * (vars->img->bits_per_pixel / 8)));
	dst = vars->img->addr + offset;
	*(unsigned int*)dst = color;
}

void	draw(t_vars *vars, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->win_size)
	{
		j = 0;
		while (j < vars->win_size)
		{
			my_mlx_pixel_put(vars, (dir.x * vars->win_size) + 0, (dir.y * vars->win_size)  +j, create_trgb(255,255,255));
			my_mlx_pixel_put(vars, dir.x * vars->win_size + i, dir.y * vars->win_size + j, color);
			j++;
		}
		my_mlx_pixel_put(vars, (dir.x * vars->win_size) + i, (dir.y * vars->win_size)  + 0, create_trgb(255,255,255));
		i++;
	}
}


void	draw_direction(float x, float y, t_vars *vars, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->win_size)
	{
		j = 0;
		while (j < vars->win_size)
		{
			my_mlx_pixel_put(vars, x * vars->win_size + i, y * vars->win_size + j, color);
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
				my_mlx_pixel_put(vars, dir.x * vars->win_size + x, dir.y * vars->win_size + y, color);
			y++;
		}
		x++;
	}
}

//addddddddddd
void	draw_player_line_derection(t_point p1, t_point p2, t_vars *vars)
{
	float draw_x, draw_y;
	float dst_x, dst_y;
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
	int	tmp_x;
	int	tmp_y;
	t_point p1;
	t_point p2;

	//addddddddddd
	p1.x = vars->p_pos_x * vars->win_size;
	p1.y = vars->p_pos_y * vars->win_size;
	p2.x = (vars->p_pos_x * vars->win_size) + (cos(vars->p_rotat * MOVE_SPEED) * vars->win_size) ;
	p2.y = (vars->p_pos_y* vars->win_size) + (sin(vars->p_rotat * MOVE_SPEED) * vars->win_size);
	while (vars->map[(int)dir.y])
	{
		dir.x = 0;
		while (vars->map[(int)dir.y][(int)dir.x])
		{
			if (vars->map[(int)dir.y][(int)dir.x] == 'N')
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
	int	tmp_x;
	int	tmp_y;
	dir.y = 0;
	while (vars->map[(int)dir.y])
	{
		dir.x = 0;
		while (vars->map[(int)dir.y][(int)dir.x])
		{
			if (vars->map[(int)dir.y][(int)dir.x] == '1')
				draw (vars, create_trgb(181, 166, 166));
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
