/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:45:29 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/15 18:53:31 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_varsiables(t_vars *vars)
{
	vars->ray.pos_x = vars->p_pos_x;
	vars->ray.pos_y = vars->p_pos_y;
	vars->ray.step_x = 0;
	vars->ray.step_y = 0;
	vars->end_v_x = vars->dis.h * vars->dis.w;
	vars->end_v_y = vars->dis.h * vars->dis.w;
	vars->end_h_x = vars->dis.h * vars->dis.w;
	vars->end_h_y = vars->dis.h * vars->dis.w;
}

void	raycasting(t_vars *vars, float engl)
{
	float	dis_hor;
	float	dis_vert;

	init_varsiables(vars);
	vars->ray.count = count_biggest_line(vars->map) * f_strlen(vars->map);
	check_horizontal(vars, engl);
	dis_hor = sqrtf(powf((vars->end_h_x - vars->p_pos_x), 2) + \
		powf((vars->end_h_y - vars->p_pos_y), 2));
	vars->ray.count = count_biggest_line(vars->map) * f_strlen(vars->map);
	check_vertical(vars, engl);
	dis_vert = sqrtf(powf((vars->end_v_x - vars->p_pos_x), 2) + \
		powf((vars->end_v_y - vars->p_pos_y), 2));
	if (dis_hor < dis_vert)
	{
		vars->rays_point.dis = dis_hor;
		vars->end_x = vars->end_h_x;
		vars->end_y = vars->end_h_y;
	}
	else
	{
		vars->rays_point.dis = dis_vert;
		vars->end_x = vars->end_v_x;
		vars->end_y = vars->end_v_y;
	}
}
