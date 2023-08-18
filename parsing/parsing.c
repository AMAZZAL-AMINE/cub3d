/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:12:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/18 20:11:11 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	init_data_pars(t_pars *pars, t_data *data)
{
	pars->count = 0;
	pars->rgb = malloc(sizeof(t_rgb));
	if (!pars->rgb)
		return (0);
	pars->img = malloc(sizeof(t_img));
	if (!pars->img)
		return (0);
	data->img = pars->img;
	data->rgb = pars->rgb;
	pars->last_index = 0;
	pars->counter_args = 0;
	pars->check = 0;
	pars->stoped = 0;
	return (1);
}

void	set_cehker(t_pars *pars)
{
	pars->check = 1;
}

int	is_it_swen(char c1, char c2, t_pars *pars, char **map)
{
	if (map[pars->count][pars->index + 1] \
		&& map[pars->count][pars->index] == c1 \
		&& map[pars->count][pars->index + 1] == c2)
		return (1);
	return (0);
}

void	check_line_by_line(t_pars	*pars, t_data *data, char **map)
{
	while (map[pars->count][pars->index] && !pars->check)
	{
		pars->stoped = pars->count;
		if (is_it_swen('N', 'O', pars, map))
			return (split_map_line_redirection(map[pars->count], \
				data, pars, "north"));
		else if (is_it_swen('S', 'O', pars, map))
			return (split_map_line_redirection(map[pars->count], \
				data, pars, "south"));
		else if (is_it_swen('W', 'E', pars, map))
			return (split_map_line_redirection(map[pars->count], \
				data, pars, "west"));
		else if (is_it_swen('E', 'A', pars, map))
			return (split_map_line_redirection(map[pars->count], \
				data, pars, "east"));
		else if (is_it_rgb('F', pars, map))
			return (split_map_line_floor(map[pars->count], data, pars));
		else if (is_it_rgb('C', pars, map))
			return (split_map_line_ceil(map[pars->count], data, pars));
		else
			return (set_cehker(pars));
		pars->index++;
	}
}

int	parsing_map(t_data *data, char **map)
{
	t_pars	pars;

	init_data_pars(&pars, data);
	while (map[pars.count])
	{
		pars.index = 0;
		check_line_by_line(&pars, data, map);
		if (pars.check && pars.counter_args != 6)
			return (-1);
		pars.count++;
	}
	data->map = map + (pars.stoped);
	return (pars.stoped + 1);
}
