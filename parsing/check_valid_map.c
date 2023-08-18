/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:53:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/18 20:18:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_first_line(char *line, char **map)
{
	int	count;
	int	index;
	int	check;

	count = 0;
	check = 0;
	while (line[count])
	{
		if (line[count] != ' ' && line[count] != '1')
			error_map("Error\nUNCLOSED WALL\n");
		else if (line[count] == ' ')
		{
			index = 1;
			while (map[index])
			{
				if (map[index][count] && map[index][count] == '1')
					check = 1;
				index++;
			}
		}
		if (!check)
			error_map("Error\nUNCLOSED WALL\n");
		count++;
	}
}

void	check_valid_map(t_data *data)
{
	int	count;
	int	index;

	count = -1;
	while (data->map[++count])
	{
		index = 0;
		if (count == 0)
			check_first_line(data->map[count], data->map);
		while (data->map[count][index])
		{
			while (data->map[count][index] && data->map[count][index] == ' ')
				index++;
			if ((data->map[count][index - 1] == ' ' \
				&& data->map[count][index] != '1'))
				error_map("Error\nUNCLOSED WALL\n");
			if (index == 0)
				if (data->map[count][index] != ' ' \
					&& data->map[count][index] != '1')
					error_map("Error\nUNCLOSED WALL\n");
			if (data->map[count][index] != '1' && !data->map[count][index + 1])
				error_map("Error\nUNCLOSED WALL\n");
			index++;
		}
	}
}
