/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 22:27:47 by rouali            #+#    #+#             */
/*   Updated: 2023/08/18 22:37:56 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	mlx_init_func(t_vars vars, t_data *data)
{
	vars.map = data->map;
	vars.mlx = mlx_init();
	vars.dis.w = ft_count(data->map) * 10;
	vars.dis.h = f_strlen(data->map) * 10;
	vars.win = mlx_new_window(vars.mlx, vars.dis.w, \
		vars.dis.h, "33-34 hakma l3alam");
	vars.img = mlx_new_image(vars.mlx, vars.dis.w, vars.dis.h);
	vars.add = mlx_get_data_addr(vars.img, &vars.img->bits_per_pixel, \
		&vars.img->line_length, &vars.img->endian);
	put_pxl(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, \
		vars.img, vars.dis.w, vars.dis.h);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_loop(vars.mlx);
}