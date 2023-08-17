/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:14:05 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/17 18:19:05 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **read_map(char *mapfile) {
	int		count;
	int		fd;
	char	*line;
	char	**dst;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0) {
		error_fd_not_found("Error\nFILE NOT FOUND\n");
	}
	count = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	close(fd);
	dst = malloc(sizeof(char *) * (count + 1));
	count = 0;
	fd = open(mapfile, O_RDONLY);
	if (fd < 0) {
		error_fd_not_found("Error\nFILE NOT FOUND\n");
	}
	line = get_next_line(fd);
	while (line)
	{
		dst[count] = line;
		line = get_next_line(fd);
		count++;
	}
	dst[count] = 0;
	return dst;
}
