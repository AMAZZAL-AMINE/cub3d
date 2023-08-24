/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/24 16:08:54 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

#define MOVE_SPEED 0.05

void move_up(t_vars *vars)
{
	if (vars->key == 13 || vars->key == 126)
	{
		vars->p_pos_y = vars->p_pos_y - MOVE_SPEED;
		printf("POSITION X => %f\n", vars->p_pos_x);
		printf("POSITION Y => %f\n", vars->p_pos_y);
	}
}

void move_lef(t_vars *vars)
{
	if (vars->key == 0 || vars->key == 123)
	{
		vars->p_pos_x = vars->p_pos_x - MOVE_SPEED;
		printf("POSITION X => %f\n", vars->p_pos_x);
		printf("POSITION Y => %f\n", vars->p_pos_y);
	}
}

void move_down(t_vars *vars)
{
	if (vars->key == 1 || vars->key == 125)
	{
		vars->p_pos_y = vars->p_pos_y + MOVE_SPEED;
		printf("POSITION X => %f\n", vars->p_pos_x);
		printf("POSITION Y => %f\n", vars->p_pos_y);
	}
}

void move_right(t_vars *vars)
{
	if (vars->key == 2 || vars->key == 124)
	{
		vars->p_pos_x = vars->p_pos_x + MOVE_SPEED;
		printf("POSITION X => %f\n", vars->p_pos_x);
		printf("POSITION Y => %f\n", vars->p_pos_y);
	}
}

void ft_move(t_vars *vars)
{
	if (vars->p_pos_x < 0)
		vars->p_pos_x = 0;
	if (vars->p_pos_y < 0)
		vars->p_pos_y = 0;
	move_up(vars);
  move_down(vars);
	move_lef(vars);
  move_right(vars);
}
