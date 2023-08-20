/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:32:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:33:13 by mamazzal         ###   ########.fr       */
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

void	print_map(t_data *data, char **map)
{
	int	count;

	count = 0;
	printf("NORTH => %s\n", data->img->no[1]);
	printf("SOUTH => %s\n", data->img->so[1]);
	printf("WEST  => %s\n", data->img->we[1]);
	printf("EAST  => %s\n", data->img->ea[1]);
	printf("-----------------------------\n");
	printf("CEIL  => %s\n", data->rgb->ceil[1]);
	printf("FLOOR  => %s\n", data->rgb->floor[1]);
	printf("-----------------------------\n");
	while (data->map[count])
	{
		printf("MAP => %s\n", data->map[count]);
		count++;
	}
}

int	main(int __unused argc, char __unused **argv)
{
	char	**map;
	t_data	*data;
	int		count;
	int		last_index;
	t_vars	vars;

	if (argc != 2)
		error_map("Error\nARGMENTS : [PROTGRAM_NAME] [MAP_FILE]");
	map = read_map(argv[1]);
	data = malloc(sizeof(t_data));
	count = 0;
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
	print_map(data, map);
	mlx_init_func(vars, data);
	return (0);
}
