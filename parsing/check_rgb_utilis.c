/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_utilis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamazzal <mamazzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:15:33 by mamazzal          #+#    #+#             */
/*   Updated: 2023/08/18 15:18:22 by mamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_var_name(char **str, char *errmsg, t_check_rgb *data, char c)
{
	data->count = 0;
	while (str[data->count])
	{
		data->index = 0;
		while (str[data->count][data->index])
		{
			if (str[data->count][data->index] == c)
			{
				if ((str[data->count][data->index + 1] \
					&& str[data->count][data->index + 1] != ' ') \
					|| strlen_2d_array(str) != 2)
				{
					free_double(str);
					error_map(errmsg);
				}
			}
			data->index++;
		}
		data->count++;
	}
}

void	err(char **str, char *errstr)
{
	free_double(str);
	error_map(errstr);
}

void	checker(int check, char **str, char *errmsg)
{
	if (check > 1)
		err(str, errmsg);
}

void	check_none_numbers(char **str, char *errmsg, t_check_rgb *data)
{
	data->count = -1;
	data->splited = ft_split(str[1], ',');
	while (data->splited[++data->count])
	{
		data->index = -1;
		data->checker = 0;
		while (data->splited[data->count][++data->index])
		{
			if (data->splited[data->count][data->index] < '0' \
				|| data->splited[data->count][data->index] > '9')
			{
				if (data->splited[data->count][data->index] == '+')
				{
					if (ft_isdigit(data->splited[data->count][data->index - 1]) \
						|| !data->splited[data->count][data->index + 1])
						err(str, errmsg);
					data->checker++;
				}
				else
					err(str, errmsg);
			}
		}
		checker(data->checker, str, errmsg);
	}
	free_double(data->splited);
}

void	check_what_after_comma(char **str, char *errmsg, t_check_rgb *data)
{
	data->count = 0;
	while (str[1][data->count])
	{
		if ((str[1][data->count + 1] && str[1][data->count] == ',' \
			&& (!ft_isdigit(str[1][data->count + 1]) \
			&& str[1][data->count + 1] != '+')) \
			|| (str[1][data->count] == ',' && !str[1][data->count + 1]))
			error_map(errmsg);
		data->count++;
	}
}
