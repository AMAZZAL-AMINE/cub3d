/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:20:46 by rouali            #+#    #+#             */
/*   Updated: 2023/08/18 22:09:20 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* ############# Draw ############# */
void	draw(t_vars *vars, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(vars->mlx, vars->win, dir.x \
			* 10 + i, dir.y * 10 + j, color);
			j++;
		}
		i++;
	}
}

/* ############# Put_pxl ############# */
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
			if (vars->map[dir.y][dir.x] == '0')
				draw (vars, 0x00808080);
			if (vars->map[dir.y][dir.x] == 'N')
				draw (vars, 0x00FF0000);
			if (vars->map[dir.y][dir.x] == 'S')
				draw (vars, 0x00FFFF00);
			if (vars->map[dir.y][dir.x] == 'E')
				draw (vars, 0x0000FFFF);
			printf("%c", vars->map[dir.y][dir.x]);
			dir.x++;
		}
		printf("\n");
		dir.y++;
	}
}