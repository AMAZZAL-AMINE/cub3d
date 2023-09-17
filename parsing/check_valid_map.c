/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:53:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/16 22:46:36 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_it_player_or_space(char c)
{
	if (c == '0' || c == 'N' \
			|| c == 'S' || c == 'E')
		return (1);
	return (0);
}

int	check_first_and_last_line(char *line)
{
	int	count;

	count = 0;
	while (line[count])
	{
		if (count == 0)
			while (line[count] && line[count] == ' ')
				count++;
		if (line[count] && (line[count] == 'E' \
			|| line[count] == 'S' \
			|| line[count] == 'N' \
			|| line[count] == 'W' \
			|| line[count] == '0'))
			return (1);
		else if (!line[count])
			break ;
		count++;
	}
	return (0);
}

int	check_unclosed_wall(char **map, int count, int i)
{
	if ((i - 1 > 0 && map[count][i - 1] == ' ') || i == 0)
		return (1);
	else if (map[count][i + 1] == ' ' || !map[count][i + 1])
		return (1);
	else if ((count - 1 >= 0 && ft_strlen(map[count - 1]) > 0 \
		&& (map[count - 1][i] == ' ' \
		|| !map[count - 1][i])) || ft_strlen(map[count - 1]) == 0)
		return (1);
	else if (map[count + 1] && (map[count + 1][i] == ' ' \
		|| !map[count + 1][i]))
		return (1);
	return (0);
}

int	check_middle_lines(char **map)
{
	int	count;
	int	i;

	count = 0;
	while (map[count + 1])
	{
		i = -1;
		while (map[count][++i])
		{
			if (is_it_player_or_space(map[count][i]))
				if (check_unclosed_wall(map, count, i))
					return (1);
		}
		count++;
	}
	return (0);
}

void	check_valid_map(t_data *data)
{
	char	**map;
	int		count;

	map = data->map;
	count = 0;
	while (map[count])
	{
		if (count == 0 && check_first_and_last_line(map[count]))
			error_map("Error\nMAP NOT VALID PATH\n");
		else if (!map[count + 1] && check_first_and_last_line(map[count]))
			error_map("Error\nMAP NOT VALID PATH\n");
		else if (check_middle_lines(&map[count]))
			error_map("Error\nMAP NOT VALID PATH\n");
		count++;
	}
}
