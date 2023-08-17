/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:32:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/17 20:05:50 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int strlen_2d_array(char **array) {
	int count = 0;
	while (array[count])
		count++;
	return count;
}

void print_map(t_data *data, char **map) {
	int count = 0;
	printf("NORTH => %s\n", data->img->no[1]);
	printf("SOUTH => %s\n", data->img->so[1]);
	printf("WEST  => %s\n", data->img->we[1]);
	printf("EAST  => %s\n", data->img->ea[1]);
	printf("-----------------------------\n");
	printf("CEIL  => %s\n", data->rgb->ceil[1]);
	printf("FLOOR  => %s\n", data->rgb->floor[1]);
	printf("-----------------------------\n");
	while (data->map[count]) {
		printf("MAP => %s\n", data->map[count]);
		count++;
	}
}

int main(int __unused argc, char __unused **argv) {
	char **map = read_map(argv[1]);
	t_data *data = malloc(sizeof(t_data));
	int count = 0;
	int last_index = parsing_map(data, map);
	if (last_index == -1) {
		write(2, "Error\n", 7);
		return 1;
	}
	check_valid_map(data);
	check_nswe(data);
	check_rgb(data);
	print_map(data, map);
	return 0;
}
