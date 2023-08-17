/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:09:28 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/17 23:40:02 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void check_floor(char **floor) {
  int count = 0;
  while (floor[count]) {
      int index = 0;
      while (floor[count][index]) {
        if (floor[count][index] == 'F') {
          if ((floor[count][index + 1] && floor[count][index + 1] != ' ') \
            || strlen_2d_array(floor) != 2) {
            error_map("Error\nMAP ERROR\n");
          }
        }
        index++;
      }
      count++;
  }
  count = 0;
  while (floor[1][count]) {
    if ((floor[1][count + 1] && floor[1][count] == ',' \
      && !ft_isdigit(floor[1][count + 1])) \
      || (floor[1][count] == ',' && !floor[1][count + 1]))
        error_map("Error\nMAP : FLOOR TGB");
      count++;
  }
  char **splited = ft_split(floor[1], ',');
  if (strlen_2d_array(splited) != 3) {
    error_map("Error\nMAP : FLOOR RGB");
  }
  count = 0;
  while (splited[count]) {
    if (ft_atoi(splited[count]) > 225 || ft_atoi(splited[count]) < 0)
      error_map("Error\nMAP : FLOOR TGB");
    count++;
  }
  free_double(splited);
}

void check_ceil(char **ceil) {
  int count = 0;
  while (ceil[count]) {
      int index = 0;
      while (ceil[count][index]) {
        if (ceil[count][index] == 'C') {
          if ((ceil[count][index + 1] && ceil[count][index + 1] != ' ') \
            || strlen_2d_array(ceil) != 2) {
            error_map("Error\nMAP ERROR\n");
          }
        }
        index++;
      }
      count++;
  }
  count = 0;
  while (ceil[1][count]) {
    if ((ceil[1][count + 1] && ceil[1][count] == ',' \
      && !ft_isdigit(ceil[1][count + 1])) || (ceil[1][count] == ',' && !ceil[1][count + 1]))
        error_map("Error\nMAP : CEIL TGB");
      count++;
  }
    char **splited = ft_split(ceil[1], ',');
  if (strlen_2d_array(splited) != 3) {
    error_map("Error\nMAP : CEIL TGB");
  }
  count = 0;
  while (splited[count]) {
    if (ft_atoi(splited[count]) > 225 || ft_atoi(splited[count]) < 0)
      error_map("Error\nMAP : CEIL RGB");
    count++;
  }
  free_double(splited);
}

void check_rgb(t_data *data) {
  check_floor(data->rgb->floor);
  check_ceil(data->rgb->ceil);
}
