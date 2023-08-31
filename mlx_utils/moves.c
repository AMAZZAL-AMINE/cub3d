/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:29:49 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/30 12:29:47 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	move_up(t_vars *vars)
{
	float	x;
	float	y;

	if (vars->key == 13 || vars->key == 126)
	{
		x = vars->p_pos_x + (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		y = vars->p_pos_y + (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		if (vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1')
			return ;
		if (vars->map[(int)vars->p_pos_y][(int)vars->p_pos_x] \
			&& vars->map[(int)y][(int)vars->p_pos_x] == '1' \
			&& vars->map[(int)vars->p_pos_y][(int)x] == '1')
			return ;
		vars->p_pos_x = x;
		vars->p_pos_y = y;
	}
}

void	move_down(t_vars *vars)
{
	float	x;
	float	y;

	if (vars->key == 1 || vars->key == 125)
	{
		x = vars->p_pos_x - (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		y = vars->p_pos_y - (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		if ((vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1'))
			return ;
		if (vars->map[(int)vars->p_pos_y][(int)vars->p_pos_x] \
			&& vars->map[(int)y][(int)vars->p_pos_x] == '1' \
			&& vars->map[(int)vars->p_pos_y][(int)x] == '1')
			return ;
		vars->p_pos_x = x;
		vars->p_pos_y = y;
	}
}

void	move_lef(t_vars *vars)
{
	float	x;
	float	y;

	if (vars->key == 0)
	{
		x = vars->p_pos_x + (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		y = vars->p_pos_y - (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		if (vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1')
			return ;
		if (vars->map[(int)vars->p_pos_y][(int)vars->p_pos_x] \
			&& vars->map[(int)y][(int)vars->p_pos_x] == '1' \
			&& vars->map[(int)vars->p_pos_y][(int)x] == '1')
			return ;
		vars->p_pos_x = x;
		vars->p_pos_y = y;
	}
}

void	move_right(t_vars *vars)
{
	float	x;
	float	y;

	if (vars->key == 2)
	{
		x = vars->p_pos_x - (MOVE_SPEED * sinf(vars->p_rotat * PI / 180));
		y = vars->p_pos_y + (MOVE_SPEED * cosf(vars->p_rotat * PI / 180));
		if (vars->map[(int)y][(int)x] && vars->map[(int)y][(int)x] == '1')
			return ;
		if (vars->map[(int)vars->p_pos_y][(int)vars->p_pos_x] \
			&& vars->map[(int)y][(int)vars->p_pos_x] == '1' \
			&& vars->map[(int)vars->p_pos_y][(int)x] == '1')
			return ;
		vars->p_pos_x = x;
		vars->p_pos_y = y;
	}
}

void	ft_move(t_vars *vars)
{
	if (vars->p_pos_x < 0)
		vars->p_pos_x = 0;
	if (vars->p_pos_y < 0)
		vars->p_pos_y = 0;
	if (vars->key == 124)
		vars->p_rotat += ROTATE_SPEED;
	if (vars->key == 123)
		vars->p_rotat -= ROTATE_SPEED;
	move_up(vars);
	move_down(vars);
	move_lef(vars);
	move_right(vars);
}
