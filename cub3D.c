/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:32:34 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/18 20:40:27 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **read_map(char *mapfile) {
	int		count;
	int		fd;
	char	*line;
	char	**dst;

	fd = open(mapfile, O_RDONLY);
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

void parsing_map(t_data *data, char **map) {
	int count = 0;
	t_rgb *rgb = malloc(sizeof(t_rgb));
	t_img *img = malloc(sizeof(t_img));
	data->img = img;
	data->rgb = rgb;
	char **splited;
	while (map[count]) {
		int index = 0;
		while (map[count][index]) {
			if (map[count][index + 1] && map[count][index] == 'N' && map[count][index + 1] == 'O')
					data->img->no = ft_split(map[count], ' ');
			else if (map[count][index + 1] && map[count][index] == 'S' && map[count][index + 1] == 'O')
					data->img->so = ft_split(map[count], ' ');
			else if (map[count][index + 1] && map[count][index] == 'W' && map[count][index + 1] == 'E')
				data->img->we = ft_split(map[count], ' ');
			else if (map[count][index + 1] && map[count][index] == 'E' && map[count][index + 1] == 'A')
				data->img->ea = ft_split(map[count], ' ');
			else if (map[count][index] == 'F')
				data->rgb->floor = ft_split(map[count], ' ');
			else if (map[count][index] == 'C')
				data->rgb->ceil = ft_split(map[count], ' ');
			index++;
		}
		count++;
	}
}



int	main(int __unused argc, char __unused **argv)
{
	t_data	*data = malloc(sizeof(t_data));
	t_vars	vars;
	t_dis	dis;

	if (argc != 2)
	{
		printf("Error\n");
		return (0);
	}
	vars.map = read_map(argv[1]);
	parsing_map(data, vars.map);

	// Initialize Minilibx
    vars.mlx = mlx_init();
	// Create a window
	dis.w = ft_count(vars.map) * 10;
	dis.h = f_strlen(vars.map) * 10;
	vars.win = mlx_new_window(vars.mlx, dis.w, dis.h, "33-34 hakma l3alam");
	vars.img = mlx_new_image(vars.mlx, dis.w, dis.h);
	vars.add = mlx_get_data_addr(vars.img, &vars.img->bits_per_pixel, &vars.img->line_length, &vars.img->endian);
	put_pxl(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, dis.w, dis.h);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
