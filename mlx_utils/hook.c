/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:22:17 by rouali            #+#    #+#             */
/*   Updated: 2023/09/15 20:49:15 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_close(void)
{
	write(1, "good bye\n", 9);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->key = keycode;
	if (vars->key == 53)
	{
		write(1, "good bye\n", 9);
		exit(0);
	}
	ft_move(vars);
	draw_floor(vars);
	draw_ceil(vars);
	put_pxl(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->img->img, 0, 0);
	return (0);
}
