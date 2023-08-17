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
		line = get_next_line(fd);
		free(line);
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
			if (map[count][index + 1] && map[count][index] == 'N' && map[count][index + 1] == 'O') {
					data->img->no = ft_split(map[count], ' ');
			}else if (map[count][index + 1] && map[count][index] == 'S' && map[count][index + 1] == 'O') {
					data->img->so = ft_split(map[count], ' ');
			}else if (map[count][index + 1] && map[count][index] == 'W' && map[count][index + 1] == 'E') {
				data->img->we = ft_split(map[count], ' ');
			}else if (map[count][index + 1] && map[count][index] == 'E' && map[count][index + 1] == 'A') {
				data->img->ea = ft_split(map[count], ' ');
			}else if (map[count][index] == 'F') {
				data->rgb->floor = ft_split(map[count], ' ');
			}else if (map[count][index] == 'C') {
				data->rgb->ceil = ft_split(map[count], ' ');
			}
			index++;
		}
		count++;
	}
}

int main(int __unused argc, char __unused **argv) {
	char **map = read_map(argv[1]);
	t_data *data = malloc(sizeof(t_data));
	int count = 0;
	parsing_map(data, map);
	printf("NORTH => %s\n", data->img->no[1]);
	printf("SOUTH => %s\n", data->img->so[1]);
	printf("WEST  => %s\n", data->img->we[1]);
	printf("EAST  => %s\n", data->img->ea[1]);
	printf("______________________________\n");
	printf("CEIL  => %s\n", data->rgb->ceil[1]);
	printf("FLOOR  => %s\n", data->rgb->floor[1]);
	return 0;
}