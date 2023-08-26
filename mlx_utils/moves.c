/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/26 18:03:39 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void move_up(t_vars *vars)
{
	if (vars->key == 13 || vars->key == 126)
	{
		vars->p_pos_x = vars->p_pos_x + (cosf(vars->p_rotat * (PI/180)) / vars->win_size);
		vars->p_pos_y = vars->p_pos_y + (sinf(vars->p_rotat * (PI/180)) / vars->win_size);
	}
}

void move_lef(t_vars *vars)
{
	if (vars->key == 0)
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
		vars->p_pos_x = vars->p_pos_x - (cosf(vars->p_rotat * (PI/180)) / vars->win_size);
		vars->p_pos_y = vars->p_pos_y - (sinf(vars->p_rotat * (PI/180)) / vars->win_size);
	}
}

void move_right(t_vars *vars)
{
	if (vars->key == 2)
	{
		vars->p_pos_x = vars->p_pos_x + MOVE_SPEED;
		printf("POSITION X => %f\n", vars->p_pos_x);
		printf("POSITION Y => %f\n", vars->p_pos_y);
	}
}
//addddddddddd
void	player_right_maze(t_vars *vars) {
	if (vars->key == 124) {
		vars->p_rotat += 1;
	}
}
//addddddddddd
void	player_left_maze(t_vars *vars) {
	if (vars->key == 123) {
		vars->p_rotat -= 1;
	}
}

void ft_move(t_vars *vars)
{
	if (vars->p_pos_x < 0)
		vars->p_pos_x = 0;
	if (vars->p_pos_y < 0)
		vars->p_pos_y = 0;
	player_right_maze(vars);
	player_left_maze(vars);
	move_up(vars);
  move_down(vars);
	move_lef(vars);
  move_right(vars);
}
