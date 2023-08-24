/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:22:17 by rouali            #+#    #+#             */
/*   Updated: 2023/08/24 16:00:37 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

/* ############# close WIN with X ############# */
int ft_close(void)
{
	printf("\033[1;35m========================\n");
	printf("     \033[37mClose with \033[1;31mX\n");
	printf("\033[1;35m========================\n");
	exit(1);
}

/* ############# Key_hook ############# */
int key_hook(int keycode, t_vars *vars)
{
	vars->key = keycode;
	if (vars->key == 53)
	{
		printf("\033[1;35m========================\n");
		printf("     \033[37mClose with \033[1;31mESC\n");
		printf("\033[1;35m========================\n");
		exit(1);
	}
	mlx_destroy_image(vars->mlx, vars->img->img);
	vars->img->img = mlx_new_image(vars->mlx, vars->dis.w, vars->dis.h);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bits_per_pixel, \
		&vars->img->line_length, &vars->img->endian);
	ft_move(vars);
	put_pxl(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img->img, 0, 0);
	return (0);
}
