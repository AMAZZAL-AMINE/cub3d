/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:12:07 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/17 17:38:41 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int parsing_map(t_data *data, char **map) {
	int count = 0;
	t_rgb *rgb = malloc(sizeof(t_rgb));
	t_img *img = malloc(sizeof(t_img));
	data->img = img;
	data->rgb = rgb;
	int last_index = 0;
	int counter_args = 0;
	char **splited;
	int check = 0;
	int stoped = 0;
	while (map[count]) {
		int index = 0;
		while (map[count][index] && !check) {
			stoped = count;
			if (map[count][index + 1] && map[count][index] == 'N' && map[count][index + 1] == 'O') {
				data->img->no = ft_split(map[count], ' ');
				counter_args++;
				break;
			}
			else if (map[count][index + 1] && map[count][index] == 'S' && map[count][index + 1] == 'O') {
				data->img->so = ft_split(map[count], ' ');
				counter_args++;
				break;
			}
			else if (map[count][index + 1] && map[count][index] == 'W' && map[count][index + 1] == 'E') {
				data->img->we = ft_split(map[count], ' ');
				counter_args++;
				break;
			}
			else if (map[count][index + 1] && map[count][index] == 'E' && map[count][index + 1] == 'A') {
				data->img->ea = ft_split(map[count], ' ');
				counter_args++;
				break;
			}
			else if (map[count][index] == 'F') {
				data->rgb->floor = ft_split(map[count], ' ');
				counter_args++;
				break;
			}
			else if (map[count][index] == 'C') {
				data->rgb->ceil = ft_split(map[count], ' ');
				counter_args++;
				break;
			}else {
				check = 1;
				break;
			}
			index++;
		}
		if (check && counter_args < 6)
			return -1;
		count++;
	}
	data->map = map + (stoped);
	return stoped + 1;
}
