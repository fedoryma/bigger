/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:04:12 by dnovikov          #+#    #+#             */
/*   Updated: 2025/09/24 23:08:42 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Main processing function - orchestrates the complete BSQ solution
void	ft_process_map(t_map *map)
{
	ft_find_max_square(map);
	if (map->square_size)
		ft_add_square_to_map(map);
	ft_print_map(map);
	ft_free_map(map);
}

int	main(int ac, char **av)
{
	t_map	*map;
	int		i;

	if (ac < 2)
	{
		map = ft_create_map(NULL);
		if (map)
			ft_process_map(map);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		map = ft_create_map(av[i]);
		if (map)
			ft_process_map(map);
		i++;
		if (i < ac)
			write(1, "\n", 1);
	}
	return (0);
}
