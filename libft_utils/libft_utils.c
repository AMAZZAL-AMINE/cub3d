/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouali <rouali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 10:19:15 by rouali            #+#    #+#             */
/*   Updated: 2023/08/18 22:36:39 by rouali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_isdigit(int nbr)
{
	if (nbr < '0' || nbr > '9')
		return (0);
	return (1);
}

/* ############### Count Char ############### */
int	ft_count(char **map)
{
	int	x;

	x = 0;
	while (map[0][x])
		x++;
	return (x);
}

/* ############# Count Line ###################### */
int	f_strlen(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	ft_atoi(const char *str)
{
	int	ci;
	int	fr;
	int	isminus;

	ci = 0;
	isminus = 1;
	fr = 0;
	while ((str[ci] >= '\t' && str[ci] <= '\r') || str[ci] == ' ')
	{
		ci++;
	}
	if (str[ci] == '-' || str[ci] == '+')
	{
		if (str[ci] == '-')
		{
			isminus = -1;
		}
		ci++;
	}
	while (str[ci] >= '0' && str[ci] <= '9')
	{
		fr = (fr * 10) + (str[ci] - '0');
		ci++;
	}
	return (fr * isminus);
}
