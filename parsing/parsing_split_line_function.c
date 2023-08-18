/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split_line_function.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:50:22 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/18 20:10:40 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	split_map_line_redirection(char *line, t_data *data, \
	t_pars *pars, char *type)
{
	if (str_cmp(type, "south"))
	{
		data->img->so = ft_split(line, ' ');
		pars->counter_args++;
	}
	else if (str_cmp(type, "north"))
	{
		data->img->no = ft_split(line, ' ');
		pars->counter_args++;
	}
	else if (str_cmp(type, "west"))
	{
		data->img->we = ft_split(line, ' ');
		pars->counter_args++;
	}
	else if (str_cmp(type, "east"))
	{
		data->img->ea = ft_split(line, ' ');
		pars->counter_args++;
	}
}

void	split_map_line_floor(char *line, t_data *data, t_pars *pars)
{
	data->rgb->floor = ft_split(line, ' ');
	pars->counter_args++;
}

void	split_map_line_ceil(char *line, t_data *data, t_pars *pars)
{
	data->rgb->ceil = ft_split(line, ' ');
	pars->counter_args++;
}
