/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:32:15 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/15 20:33:25 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_walls_3d(t_vars *vars, int rays, float eng, float dis)
{
	t_point	p2;
	t_point	p1;
	float	tall;
	float	tail;

	tail = 1;
	p1.x = rays;
	p2.x = p1.x + tail;
	dis = dis * cosf((eng - vars->p_rotat) * (PI / 180));
	tall = ((vars->dis.h * vars->win_size) / dis) / 2;
	p1.y = (vars->dis.h / 2) - tall;
	if (p1.y < 0)
		p1.y = 0;
	p2.y = (vars->dis.h / 2) + tall;
	if (p2.y >= vars->dis.h)
		p2.y = vars->dis.h;
	rendring_textures(vars, p1, p2, tall);
}

void	rendring_rays(t_vars *vars)
{
	float	eng;
	float	rays;

	eng = vars->p_rotat - (vars->fov / 2);
	if (eng > 360)
		eng -= 360;
	else if (eng < 0)
		eng += 360;
	rays = 0;
	while (rays < vars->dis.w)
	{
		eng += vars->fov / vars->dis.w;
		if (eng > 360)
			eng -= 360;
		else if (eng < 0)
			eng += 360;
		raycasting(vars, eng);
		draw_walls_3d(vars, rays, eng, vars->rays_point.dis);
		rays++;
	}
}
