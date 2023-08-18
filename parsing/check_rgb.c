/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:09:28 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/18 19:31:43 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_range(char **str, char *errmsg, t_check_rgb *data)
{
	data->splited = ft_split(str[1], ',');
	if (strlen_2d_array(data->splited) != 3)
	{
		free_double(data->splited);
		error_map(errmsg);
	}
	data->count = 0;
	while (data->splited[data->count])
	{
		if (ft_atoi(data->splited[data->count]) > 225 \
			|| ft_atoi(data->splited[data->count]) < 0)
		{
			free_double(data->splited);
			error_map(errmsg);
		}
		data->count++;
	}
	free_double(data->splited);
}

void	check_floor(char **floor)
{
	t_check_rgb	data;

	check_var_name(floor, "Error\nFLOOR ERROR\n", &data, 'F');
	check_none_numbers(floor, "Error\nFLOOR ERROR\n", &data);
	check_what_after_comma(floor, "Error\nFLOOR ERROR\n", &data);
	check_range(floor, "Error\nFLOOR ERROR\n", &data);
}

void	check_ceil(char **ceil)
{
	t_check_rgb	data;

	check_var_name(ceil, "Error\nCEIL ERROR\n", &data, 'C');
	check_none_numbers(ceil, "Error\nCEIL ERROR\n", &data);
	check_what_after_comma(ceil, "Error\nCEIL ERROR\n", &data);
	check_range(ceil, "Error\nCEIL ERROR\n", &data);
}

void	check_rgb(t_data *data)
{
	check_floor(data->rgb->floor);
	check_ceil(data->rgb->ceil);
}

int	is_it_rgb(char c1, t_pars *pars, char **map)
{
	if (map[pars->count][pars->index] == c1)
		return (1);
	return (0);
}
