/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:16:40 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/15 19:09:19 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

typedef struct t_data
{
	int	r;
	int	g;
	int	b;
}	t_data_rgb;

void	draw_ceil(t_vars *vars)
{
	t_data_rgb	data;
	int			count;
	char		**splite;
	int			index;

	splite = ft_split(vars->pars_data->rgb->ceil[1], ',');
	data.r = ft_atoi(splite[0]);
	data.g = ft_atoi(splite[1]);
	data.b = ft_atoi(splite[2]);
	count = 0;
	free_double(splite);
	while (count < vars->dis.h / 2)
	{
		index = 0;
		while (index < vars->dis.w)
		{
			my_mlx_pixel_put(vars, index, count, \
				create_trgb(data.r, data.g, data.b));
			index++;
		}
		count++;
	}
}

void	draw_floor(t_vars *vars)
{
	t_data_rgb	data;
	int			index;
	int			count;
	char		**splite;

	count = vars->dis.h / 2;
	splite = ft_split(vars->pars_data->rgb->floor[1], ',');
	data.r = ft_atoi(splite[0]);
	data.g = ft_atoi(splite[1]);
	data.b = ft_atoi(splite[2]);
	free_double(splite);
	while (count < vars->dis.h)
	{
		index = 0;
		while (index < vars->dis.w)
		{
			my_mlx_pixel_put(vars, index, count, \
				create_trgb(data.r, data.g, data.b));
			index++;
		}
		count++;
	}
}
