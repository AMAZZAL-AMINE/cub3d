/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:15:10 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:32:30 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	error_fd_not_found(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	error_map(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}
