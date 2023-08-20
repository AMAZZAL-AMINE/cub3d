/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupl_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 11:02:42 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:33:29 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*str_copy(char *str)
{
	int		count;
	char	*dst;

	count = 0;
	dst = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[count])
	{
		dst[count] = str[count];
		count++;
	}
	dst[count] = '\0';
	return (dst);
}

char	**duplcate_map(char **oldmap)
{
	int		count;
	int		size;
	char	**dst;

	size = strlen_2d_array(oldmap);
	dst = malloc(sizeof(char *) * (size + 1));
	count = 0;
	while (oldmap[count])
	{
		dst[count] = str_copy(oldmap[count]);
		count++;
	}
	dst[count] = 0;
	return (dst);
}
