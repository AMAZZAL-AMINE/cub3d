/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/08/21 11:18:53 by mamazzal         ###   ########.fr       */
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
/* ############# Draw ############# */
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
			my_mlx_pixel_put(vars, (dir.x * vars->win_size + i) / 3, (dir.y * vars->win_size + j) / 3, color);
			j++;
		}
		i++;
	}
}

// /* ############# Put_pxl ############# */
void	put_pxl(t_vars *vars)
{
	dir.y = 0;
	while (vars->map[dir.y])
	{
		dir.x = 0;
		while (vars->map[dir.y][dir.x])
		{
			if (vars->map[dir.y][dir.x] == '1')
				draw (vars, 0x000000FF);
			else if (vars->map[dir.y][dir.x] == '0')
				draw (vars, 0x00808080);
			else if (vars->map[dir.y][dir.x] == 'N')
				draw (vars, 0x00FF0000);
			else if (vars->map[dir.y][dir.x] == 'S')
				draw (vars, 0x00FFFF00);
			else if (vars->map[dir.y][dir.x] == 'E')
				draw (vars, 0x0000FFFF);
			printf("%c", vars->map[dir.y][dir.x]);
			dir.x++;
		}
		printf("\n");
		dir.y++;
	}
}
