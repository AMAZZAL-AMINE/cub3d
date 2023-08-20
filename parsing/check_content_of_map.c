/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content_of_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:53:16 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:32:06 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_duplicate_character(char	**map)
{
	int	count_red;
	int	index;
	int	count;

	count = -1;
	count_red = 0;
	while (map[++count])
	{
		index = -1;
		while (map[count][++index])
		{
			if (map[count][index] == 'E')
				count_red++;
			else if (map[count][index] == 'N')
				count_red++;
			else if (map[count][index] == 'W')
				count_red++;
			else if (map[count][index] == 'S')
				count_red++;
		}
	}
	if (count_red != 1)
		error_map("Error\nDuplicated : Use Only one from [E, N, W, S]");
}

void	check_content_of_map(char **map)
{
	int	count;
	int	index;

	count = 0;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] != '0' \
				&& map[count][index] != '1' \
				&& map[count][index] != 'E' \
				&& map[count][index] != 'N' \
				&& map[count][index] != 'W' \
				&& map[count][index] != 'S' \
				&& map[count][index] != ' ')
				error_map("Error\nUse Only : [0, 1, E, N, W, S]");
			index++;
		}
		count++;
	}
	check_duplicate_character(map);
}
