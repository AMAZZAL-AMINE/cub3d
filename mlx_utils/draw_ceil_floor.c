/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:16:40 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/02 19:23:26 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_ceil(t_vars *vars)
{
	int count = 0;
	while (count < vars->dis.h / 2) {
		int index = 0;
		while (index < vars->dis.w) {
			my_mlx_pixel_put(vars, index, count, create_trgb(25, 126, 255));
			index++;
		}
		count++;
	}
}

void	draw_floor(t_vars *vars)
{
	int count = vars->dis.h / 2;
	while (count < vars->dis.h) {
		int index = 0;
		while (index < vars->dis.w) {
			my_mlx_pixel_put(vars, index, count, create_trgb(20, 200, 42));
			index++;
		}
		count++;
	}
}
