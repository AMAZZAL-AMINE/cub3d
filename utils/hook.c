/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:22:17 by rouali            #+#    #+#             */
/*   Updated: 2023/08/18 20:55:26 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* ############# close WIN with X ############# */
int	ft_close(void)
{
	printf("\033[1;35m========================\n");
	printf("     \033[37mClose with \033[1;31mX\n");
	printf("\033[1;35m========================\n");
	exit(1);
}

/* ############### Move Up ############### */
void	move_up(t_vars *vars, int y, int x)
{
	if (vars->map[y][x] == 'N')
	{
		if (vars->key == 13 || vars->key == 126)
		{
			if (vars->map[y - 1][x] == '0')
			{
				vars->map[y][x] = '0';
				vars->map[y - 1][x] = 'N';
				put_pxl(vars);
				return ;
			}
		}
	}
}

void ft_move(t_vars *vars)
{
	int		y;
	int		x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'N')
			{
				move_up(&vars[0], y, x);
				return ;
			}
			x++;
		}
		y++;
	}
}

/* ############# Key_hook ############# */
int	key_hook(int keycode, t_vars *vars)
{
	vars->key = keycode;
	if (vars->key == 53)
	{
		printf("\033[1;35m========================\n");
		printf("     \033[37mClose with \033[1;31mESC\n");
		printf("\033[1;35m========================\n");
		exit(1);
	}
	printf("%d\n", vars->key);
	ft_move(vars);
	return (0);
}
