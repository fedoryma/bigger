/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 22:12:10 by dnovikov          #+#    #+#             */
/*   Updated: 2025/09/24 22:50:31 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Check if a character is printable
int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

// Check if a string contains only numeric digits
int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[i])
		return (0);
	while (str && str[i])
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_digit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

// Check if a string contains only allowed symbols
int	ft_is_line_valid(char *str, t_map *map)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != map->empty && str[i] != map->obstacle)
			return (1);
		i++;
	}
	return (0);
}

// Check if EOF reached
int	ft_is_eof(int file_name)
{
	int	i;

	i = 0;
	while (ft_get_next_line(file_name))
		i++;
	return (i);
}
