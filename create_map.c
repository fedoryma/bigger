/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:42:43 by dnovikov          #+#    #+#             */
/*   Updated: 2025/09/24 23:06:40 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Check if a header is valid
static int	ft_is_header_valid(t_map *map)
{
	return (map->rows <= 0
		|| ft_is_digit(map->full)
		|| !ft_is_printable(map->empty)
		|| !ft_is_printable(map->obstacle)
		|| !ft_is_printable(map->full)
		|| map->empty == map->obstacle
		|| map->empty == map->full
		|| map->obstacle == map->full);
}

// Parse map header from file
int	ft_parse_map_header(t_map *map, int file_name)
{
	char	*header;
	int		len;

	header = ft_get_next_line(file_name);
	if (!header)
		return (1);
	len = 0;
	while (header[len] != '\0')
		len++;
	if (len < 4)
	{
		free(header);
		return (1);
	}
	map->full = header[len - 1];
	map->obstacle = header[len - 2];
	map->empty = header[len - 3];
	header[len - 3] = '\0';
	if (ft_is_number(header))
		map->rows = ft_atoi(header);
	free(header);
	if (map->rows <= 0)
		return (1);
	return (ft_is_header_valid(map));
}

// Parse the actual map content (grid) from the input
int	ft_parse_map(t_map *map, int file_name)
{
	char	*line;
	int		i;

	map->matrix = (char **)malloc(sizeof(char *) * map->rows);
	i = 0;
	line = ft_get_next_line(file_name);
	if (!line)
		return (1);
	map->cols = ft_strlen(line);
	if (map->cols == 0)
		return (1);
	while (line && ft_strlen(line) == map->cols && i < map->rows)
	{
		if (ft_is_line_valid(line, map))
			return (1);
		map->matrix[i] = line;
		line = ft_get_next_line(file_name);
		i++;
	}
	if (i != map->rows || ft_strlen(line) || ft_is_eof(file_name))
		return (1);
	return (0);
}

// Create a map structure from a file or standard input
t_map	*ft_create_map(char *file_name)
{
	t_map	*map;
	int		fd;

	fd = ft_get_fd(file_name);
	if (fd == -1)
		return (ft_print_map_error());
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		return (ft_print_map_error());
	}
	map->matrix = NULL;
	if (ft_parse_map_header(map, fd) || ft_parse_map(map, fd))
	{
		close(fd);
		free(map);
		return (ft_print_map_error());
	}
	close(fd);
	map->square_size = 0;
	return (map);
}

// Free all memory allocated for the map structure
void	ft_free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->matrix)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->matrix[i])
				free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	free(map);
}
