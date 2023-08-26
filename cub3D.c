/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:32:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/26 15:31:28 by mamazzal         ###   ########.fr       */
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

int	main(int __unused argc, char __unused **argv)
{
	char	**map;
	t_data	*data;
	int		count;
	int		last_index;
	t_vars	*vars;
	
	if (argc != 2)
		error_map("Error\nARGMENTS : [PROTGRAM_NAME] [MAP_FILE]");
	vars = malloc(sizeof(t_vars));
	map = read_map(argv[1]);
	vars->p_rotat  = 180;
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
	mlx_init_func(vars, data);
	return (0);
}
