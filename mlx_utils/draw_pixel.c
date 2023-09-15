/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:42:28 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/15 20:47:20 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw(t_vars *vars, int __unused color)
{
	float	i;
	float	j;

	i = 0;
	while (i < vars->win_size)
	{
		j = 0;
		while (j < vars->win_size)
		{
			my_mlx_pixel_put(vars, (vars->dir.x * vars->win_size + i) / ZOOM, \
				(vars->dir.y * vars->win_size + j) / ZOOM, color);
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = ((y * vars->img->line_length) + \
		(x * (vars->img->bits_per_pixel / 8)));
	dst = vars->img->addr + offset;
	*(unsigned int *)dst = color;
}

int	gety_pix_from_img(t_pixle *img_pix, int x, int y)
{
	char	*dst;
	int		offset;

	offset = (((int)y * img_pix->line_length) + \
		((int)x * (img_pix->bits_per_pixel / 8)));
	dst = img_pix->addr + offset;
	return (*(unsigned int *)dst);
}
