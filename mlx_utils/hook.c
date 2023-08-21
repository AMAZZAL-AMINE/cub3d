/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:22:17 by rouali            #+#    #+#             */
/*   Updated: 2023/08/21 14:55:23 by mamazzal         ###   ########.fr       */
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
void	move_up(t_vars *vars)
{
		if (vars->key == 13 || vars->key == 126)
		{
				// mlx_pixel_put(vars->img, vars->win, vars->p_pos_y, vars->p_pos_x, 0x00808080);
				dir.x = vars->p_pos_x;
				dir.y = vars->p_pos_y;
				if (vars->p_pos_x > 0)
					vars->p_pos_y = vars->p_pos_y - 0.1;
				dir.x = vars->p_pos_x;
				dir.y = vars->p_pos_y;
				// put_pxl(vars);
				int	i;
				int	j;

				i = 0;
				while (i < vars->win_size)
				{
					j = 0;
					while (j < vars->win_size)
					{
						mlx_pixel_put(vars->img, vars->win, (vars->p_pos_x * (vars->win_size) + i) / 3, \
							((vars->p_pos_y) * vars->win_size + j)/ 3, 0x0000FF00);
						j++;
					}
					i++;
				}
				draw (vars, 0x0000FF00);
				printf("POSITION X => %d\n", dir.x);
				printf("POSITION Y => %d\n", dir.y);
				return ;
		}
}

void	ft_move(t_vars *vars)
{
	move_up(vars);
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
