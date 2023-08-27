/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/27 09:28:57 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void move_up(t_vars *vars)
{
	if (vars->key == 13 || vars->key == 126)
	{
		float x =  vars->p_pos_x + (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		float y = vars->p_pos_y + (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		if (vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1')
			return;
		vars->p_pos_x = x;
		vars->p_pos_y = y;
	}
}

void move_down(t_vars *vars)
{
	if (vars->key == 1 || vars->key == 125)
	{
		float x = vars->p_pos_x - (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		float y = vars->p_pos_y - (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		if (vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1')
			return;
		vars->p_pos_x = x;
		vars->p_pos_y = y;
	}
}

void move_lef(t_vars *vars)
{
	if (vars->key == 0)
	{
		float x = vars->p_pos_x + (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		float y = vars->p_pos_y - (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		if (vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1')
			return;
		vars->p_pos_x = vars->p_pos_x + (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		vars->p_pos_y = vars->p_pos_y - (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
	}
}

void move_right(t_vars *vars)
{
	if (vars->key == 2)
	{
		float x = vars->p_pos_x - (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		float y = vars->p_pos_y + (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		if (vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1')
			return;
		vars->p_pos_x = x;
		vars->p_pos_y = y;
	}
}

void	player_right_maze(t_vars *vars) {
	if (vars->key == 124) {
		vars->p_rotat += ROTATE_SPEED;
	}
}

void	player_left_maze(t_vars *vars) {
	if (vars->key == 123) {
		vars->p_rotat -= ROTATE_SPEED;
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
