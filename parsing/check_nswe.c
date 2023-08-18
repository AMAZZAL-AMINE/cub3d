/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nswe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:38:21 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/18 15:30:05 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	check_south(char **sorth)
{
	int	count;
	int	index;

	count = 0;
	while (sorth[count])
	{
		index = 0;
		while (sorth[count][index])
		{
			if (sorth[count][index + 1] &&
				(sorth[count][index] == 'S' && sorth[count][index + 1] == 'O'))
			{
				if ((sorth[count][index + 2] && sorth[count][index + 2] != ' ') \
					|| strlen_2d_array(sorth) != 2)
				{
					free_double(sorth);
					error_map("Error\nMAP ERROR\n");
				}
			}
			index++;
		}
		count++;
	}
	return (0);
}

int	check_west(char **west)
{
	int	count;
	int	index;

	count = 0;
	while (west[count])
	{
		index = 0;
		while (west[count][index])
		{
			if (west[count][index + 1] &&
				(west[count][index] == 'W' && west[count][index + 1] == 'E'))
			{
				if ((west[count][index + 2] && west[count][index + 2] != ' ') \
					|| strlen_2d_array(west) != 2)
				{
					free_double(west);
					error_map("Error\nMAP ERROR\n");
				}
			}
			index++;
		}
		count++;
	}
	return (0);
}

int	check_east(char **east)
{
	int	index;
	int	count;

	count = 0;
	while (east[count])
	{
		index = 0;
		while (east[count][index])
		{
			if (east[count][index + 1] &&
				(east[count][index] == 'E' && east[count][index + 1] == 'A'))
			{
				if ((east[count][index + 2] && east[count][index + 2] != ' ') \
					|| strlen_2d_array(east) != 2)
				{
					free_double(east);
					error_map("Error\nMAP ERROR\n");
				}
			}
			index++;
		}
		count++;
	}
	return (0);
}

int	check_north(char **north)
{
	int	count;
	int	index;

	count = 0;
	while (north[count])
	{
		index = 0;
		while (north[count][index])
		{
			if (north[count][index + 1] &&
				(north[count][index] == 'N' && north[count][index + 1] == 'O'))
			{
				if ((north[count][index + 2] && north[count][index + 2] != ' ') \
					|| strlen_2d_array(north) != 2)
				{
					free_double(north);
					error_map("Error\nMAP ERROR\n");
				}
			}
			index++;
		}
		count++;
	}
	return (0);
}

void	check_nswe(t_data *data)
{
	check_south(data->img->so);
	check_west(data->img->we);
	check_east(data->img->ea);
	check_north(data->img->no);
}
