/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:17:02 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/17 19:22:50 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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