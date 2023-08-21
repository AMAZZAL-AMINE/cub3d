/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:22:17 by rouali            #+#    #+#             */
/*   Updated: 2023/08/21 17:37:49 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* ############# close WIN with X ############# */
int ft_close(void)
{
	printf("\033[1;35m========================\n");
	printf("     \033[37mClose with \033[1;31mX\n");
	printf("\033[1;35m========================\n");
	exit(1);
}

/* ############### Move Up ############### */
void move_up(t_vars *vars)
{
	if (vars->key == 13 || vars->key == 126)
	{
		vars->p_pos_y = vars->p_pos_y - 0.5;
		dir.x = vars->p_pos_x;
		dir.y = vars->p_pos_y;
		printf("POSITION X => %d\n", dir.x);
		printf("POSITION Y => %d\n", dir.y);
	}
}

void ft_move(t_vars *vars)
{
	move_up(vars);
}

/* ############# Key_hook ############# */
int key_hook(int keycode, t_vars *vars)
{
	vars->key = keycode;
	if (vars->key == 53)
	{
		printf("\033[1;35m========================\n");
		printf("     \033[37mClose with \033[1;31mESC\n");
		printf("\033[1;35m========================\n");
		exit(1);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img->img, 0, 0);
	ft_move(vars);
	put_pxl(vars);
	return (0);
}
