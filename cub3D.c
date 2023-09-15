/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:32:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/15 21:30:24 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	strlen_2d_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int	get_direction_type(char **map)
{
	int	count;
	int	index;

	count = 0;
	while (map[count])
	{
		index = 0;
		while (map[count][index])
		{
			if (map[count][index] == 'S')
				return ('S');
			else if (map[count][index] == 'W')
				return ('W');
			else if (map[count][index] == 'N')
				return ('N');
			else if (map[count][index] == 'E')
				return ('E');
			index++;
		}
		count++;
	}
	return (0);
}

void	set_rotation(t_vars *vars, char **map)
{
	int			rotate_type;

	vars->p_rotat = 0;
	rotate_type = get_direction_type(map);
	if (rotate_type == 'S')
		vars->p_rotat = 90;
	else if (rotate_type == 'W')
		vars->p_rotat = 180;
	else if (rotate_type == 'E')
		vars->p_rotat = 0;
	else if (rotate_type == 'N')
		vars->p_rotat = 270;
}

int	main(int __unused argc, char __unused **argv)
{
	char	**map;
	t_vars	*vars;
	t_data	*data;
	int		last_index;

	if (argc != 2)
		error_map("Error\nARGMENTS : [PROTGRAM_NAME] [MAP_FILE]");
	map = read_map(argv[1]);
	data = malloc(sizeof(t_data));
	last_index = parsing_map(data, map);
	if (last_index == -1)
	{
		write(2, "Error\n", 7);
		return (1);
	}
	check_content_of_map(data->map);
	check_valid_map(data);
	check_nswe(data);
	check_rgb(data);
	vars = malloc(sizeof(t_vars));
	set_rotation(vars, data->map);
	mlx_init_func(vars, data);
	return (0);
}
