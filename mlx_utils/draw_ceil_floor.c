/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:16:40 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/13 12:57:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_ceil(t_vars *vars)
{
	int count = 0;
	char **splite = ft_split(vars->pars_data->rgb->ceil[1], ',');
	int r = ft_atoi(splite[0]);
	int g = ft_atoi(splite[1]);
	int b = ft_atoi(splite[2]);
	free_double(splite);
	while (count < vars->dis.h / 2) {
		int index = 0;
		while (index < vars->dis.w) {
			my_mlx_pixel_put(vars, index, count, create_trgb(r,g,b));
			index++;
		}
		count++;
	}
}

void	draw_floor(t_vars *vars)
{
	int count = vars->dis.h / 2;
	char **splite = ft_split(vars->pars_data->rgb->floor[1], ',');
	int r = ft_atoi(splite[0]);
	int g = ft_atoi(splite[1]);
	int b = ft_atoi(splite[2]);
	free_double(splite);
	while (count < vars->dis.h) {
		int index = 0;
		while (index < vars->dis.w) {
			my_mlx_pixel_put(vars, index, count, create_trgb(r,g,b));
			index++;
		}
		count++;
	}
}
