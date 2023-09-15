/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:52:27 by mamazzal          #+#    #+#             */
/*   Updated: 2023/09/15 21:13:51 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

typedef struct mlx_textur_data
{
	int		w;
	int		h;
	int		w2;
	int		h2;
	int		w3;
	int		h3;
	int		w4;
	int		h4;
	char	*ea;
	char	*no;
	char	*so;
	char	*we;
	void	*gm;
	void	*gm2;
	void	*gm3;
	void	*gm4;
}	t_mlx_textur_data;

void	init_textures_value(t_vars *vars, t_mlx_textur_data *data)
{
	data->ea = vars->pars_data->img->ea[1];
	data->no = vars->pars_data->img->no[1];
	data->so = vars->pars_data->img->so[1];
	data->we = vars->pars_data->img->we[1];
	data->gm = mlx_xpm_file_to_image(vars->mlx, \
		data->ea, &(data->w), &(data->h));
	data->gm2 = mlx_xpm_file_to_image(vars->mlx, \
		data->no, &(data->w2), &(data->h2));
	data->gm3 = mlx_xpm_file_to_image(vars->mlx, \
		data->so, &(data->w3), &(data->h3));
	data->gm4 = mlx_xpm_file_to_image(vars->mlx, \
		data->we, &(data->w4), &(data->h4));
	vars->img_pix = malloc(sizeof(t_pixle));
	vars->img_pix1 = malloc(sizeof(t_pixle));
	vars->img_pix2 = malloc(sizeof(t_pixle));
	vars->img_pix3 = malloc(sizeof(t_pixle));
	if (!data->gm || !data->gm2 || !data->gm3 || !data->gm4)
	{
		write(1, "Error\nIMAGE STUCK, GO FIX IT\n", 30);
		exit(1);
	}
}

void	init_address_img(t_vars *vars)
{
	vars->img_pix->addr = mlx_get_data_addr(vars->img_pix->img, \
		&vars->img_pix->bits_per_pixel, &vars->img_pix->line_length, \
		&vars->img_pix->endian);
	vars->img_pix1->addr = mlx_get_data_addr(vars->img_pix1->img, \
		&vars->img_pix1->bits_per_pixel, &vars->img_pix1->line_length, \
		&vars->img_pix1->endian);
	vars->img_pix2->addr = mlx_get_data_addr(vars->img_pix2->img, \
		&vars->img_pix2->bits_per_pixel, &vars->img_pix2->line_length, \
		&vars->img_pix2->endian);
	vars->img_pix3->addr = mlx_get_data_addr(vars->img_pix3->img, \
		&vars->img_pix3->bits_per_pixel, &vars->img_pix3->line_length, \
		&vars->img_pix3->endian);
	if (!vars->img_pix->addr || !vars->img_pix1->addr || \
		!vars->img_pix2->addr || !vars->img_pix3->addr)
	{
		write(1, "Error\nIMAGE Address STUCK, GO FIX IT\n", 38);
		exit(1);
	}
}

void	init_textures(t_vars *vars)
{
	t_mlx_textur_data	data;

	init_textures_value(vars, &data);
	vars->img_pix->w = data.w;
	vars->img_pix->h = data.h;
	vars->img_pix->img = data.gm;
	vars->img_pix1->w = data.w2;
	vars->img_pix1->h = data.h2;
	vars->img_pix1->img = data.gm2;
	vars->img_pix2->w = data.w3;
	vars->img_pix2->h = data.h3;
	vars->img_pix2->img = data.gm3;
	vars->img_pix3->w = data.w4;
	vars->img_pix3->h = data.h4;
	vars->img_pix3->img = data.gm4;
	init_address_img(vars);
}
