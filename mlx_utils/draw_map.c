/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/08/25 10:53:22 by mamazzal         ###   ########.fr       */
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
	int	i;
	int	j;

	i = 0;
	while (i < vars->win_size)
	{
		j = 0;
		while (j < vars->win_size)
		{
			my_mlx_pixel_put(vars, dir.x * vars->win_size + i, dir.y * vars->win_size + j, color);
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

// /* ############# Put_pxl ############# */

void	put_player_pixel(t_vars *vars) {
	int	tmp_x;
	int	tmp_y;
	while (vars->map[(int)dir.y])
	{
		dir.x = 0;
		while (vars->map[(int)dir.y][(int)dir.x])
		{
			if (vars->map[(int)dir.y][(int)dir.x] == 'N')
			{
				tmp_x = dir.x;
				tmp_y = dir.y;
				draw (vars, 0x00808080);
				dir.x = vars->p_pos_x;
				dir.y = vars->p_pos_y;
				draw_player (vars, 0x0000FF00);
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
				draw (vars, 0x000000FF);
			else if (vars->map[(int)dir.y][(int)dir.x] == '0')
				draw (vars, 0x00808080);
			dir.x++;
		}
		dir.y++;
	}
	dir.x = 0;
	dir.y = 0;
	put_player_pixel(vars);
}
