/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:27:47 by rouali            #+#    #+#             */
/*   Updated: 2023/08/26 17:49:34 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	get_player_position(t_vars *vars)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (vars->map[count])
	{
		index = 0;
		while (vars->map[count][index])
		{
			if (vars->map[count][index] == 'N' || vars->map[count][index] == 'S' \
				|| vars->map[count][index] == 'E' || vars->map[count][index] == 'W')
			{
				vars->p_pos_y = (int)count;
				vars->p_pos_x = (int)index;
				return ;
			}
			index++;
		}
		count++;
	}	
	return ;
}

int	count_biggest_line(char **map)
{
	int	count;
	int	size;

	count = 0;
	size = ft_strlen(map[0]);
	while (map[count])
	{
		if (ft_strlen(map[count]) > size) {
			size = ft_strlen(map[count]);
		}
		count++;
	}	
	return size;
}

void	mlx_init_func(t_vars *vars, t_data *data)
{
	vars->map = data->map;
	get_player_position(vars);
	vars->img = malloc(sizeof(t_pixle));
	vars->mlx = mlx_init();
	vars->win_size = 50;
	vars->dis.w = count_biggest_line(data->map) * vars->win_size;
	vars->dis.h = f_strlen(data->map) * vars->win_size;
	vars->win = mlx_new_window(vars->mlx, vars->dis.w, \
		vars->dis.h, "33-34 hakma l3alam");
	vars->img->img = mlx_new_image(vars->mlx, vars->dis.w, vars->dis.h);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, \
		&vars->img->line_length, &vars->img->endian);
	put_pxl(vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	mlx_hook(vars->win, 3, 0, key_hook, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img->img, 0, 0);
	mlx_loop(vars->mlx);
}
