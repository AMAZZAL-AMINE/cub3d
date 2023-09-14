/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical_and_herozintal.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:20:44 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/13 22:51:46 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int check_is_wall(t_vars *vars, float x, float y)
{
	if (y / vars->win_size <= f_strlen(vars->map) && y / vars->win_size >= 0 
		&& x / vars->win_size <= ft_strlen(vars->map[(int)y / vars->win_size]) && x / vars->win_size >= 0
		&& vars->map[(int)(y / vars->win_size)][(int)(x / vars->win_size)] != 0 
		&& (vars->map[(int)(y / vars->win_size)][(int)(x / vars->win_size)] == '1' 
		|| vars->map[(int)(y / vars->win_size)][(int)(x / vars->win_size)] == ' ' 
		|| !vars->map[(int)(y / vars->win_size)][(int)(x / vars->win_size)]))
			return (1);
	return (0);
}
void check_horizontal(t_vars *vars, float engl)
{
	if (engl > 0 && engl < 180)
	{
		vars->ray.pos_y = ((int)vars->p_pos_y / vars->win_size) * vars->win_size + vars->win_size;
		vars->ray.step_y = vars->win_size;
	}
	else if (engl > 180 && engl < 360)
	{
		vars->ray.pos_y = ((int)vars->p_pos_y / vars->win_size) * vars->win_size - 0.0005;
		vars->ray.step_y = -(vars->win_size);
	}
	else
		vars->ray.count = 0;
	vars->ray.pos_x = (vars->ray.pos_y - vars->p_pos_y) / tanf(engl * (PI / 180)) + vars->p_pos_x;
	vars->ray.step_x = vars->ray.step_y / tanf(engl * (PI / 180));
	while (vars->ray.count)
	{
		if (check_is_wall(vars, vars->ray.pos_x, vars->ray.pos_y))
			break ;
		vars->ray.count--;
		vars->ray.pos_x += vars->ray.step_x;
		vars->ray.pos_y += vars->ray.step_y;
	}
	vars->end_h_x = vars->ray.pos_x;
	vars->end_h_y = vars->ray.pos_y;
}

void check_vertical(t_vars *vars, float engl)
{
	//Vertical
	if (engl < 90 || engl > 270)
	{
		vars->ray.pos_x = ((int)vars->p_pos_x / vars->win_size) * vars->win_size + vars->win_size;
		vars->ray.step_x = vars->win_size;
	}
	else if (engl > 90 && engl < 270)
	{
		vars->ray.pos_x = ((int)vars->p_pos_x / vars->win_size) * vars->win_size - 0.0005;
		vars->ray.step_x = -(vars->win_size);
	}
	else
		vars->ray.count = 0;
	vars->ray.pos_y = (vars->ray.pos_x - vars->p_pos_x) * tanf(engl * (PI / 180)) + vars->p_pos_y;
	vars->ray.step_y = vars->ray.step_x * tanf(engl * (PI / 180));
	while (vars->ray.count)
	{
		if (check_is_wall(vars, vars->ray.pos_x, vars->ray.pos_y))
			break ;
		vars->ray.count--;
		vars->ray.pos_x += vars->ray.step_x;
		vars->ray.pos_y += vars->ray.step_y;
	}
	vars->end_v_x = vars->ray.pos_x;
	vars->end_v_y = vars->ray.pos_y;
}
