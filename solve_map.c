/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:55:58 by dnovikov          #+#    #+#             */
/*   Updated: 2025/09/24 22:23:53 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// Fill the biggest square found on the map with the 'full' character
void	ft_add_square_to_map(t_map *map)
{
	int	row;
	int	col;

	row = map->square_row;
	while (row < map->square_row + map->square_size)
	{
		col = map->square_col;
		while (col < map->square_col + map->square_size)
		{
			map->matrix[row][col] = map->full;
			col++;
		}
		row++;
	}
}

// Find the maximum square that can be placed on the map
void	ft_find_max_square(t_map *map)
{
	int	row;
	int	col;
	int	**tmp_matrix;

	tmp_matrix = ft_allocate_tmp_matrix(map->rows, map->cols);
	if (!tmp_matrix)
		return ;
	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			ft_set_min_value(map, row, col, tmp_matrix);
			ft_set_square_parameters(tmp_matrix, row, col, map);
			col++;
		}
		row++;
	}
	ft_free_tmp_matrix(tmp_matrix, map->rows);
}

// Update square parameters if a larger square is found
void	ft_set_square_parameters(int **tmp_matrix, int row, int col, t_map *map)
{
	if (tmp_matrix[row][col] > map->square_size)
	{
		map->square_size = tmp_matrix[row][col];
		map->square_row = row - tmp_matrix[row][col] + 1;
		map->square_col = col - tmp_matrix[row][col] + 1;
	}
}

// Calculate the maximum square size ending at position (row, col)
void	ft_set_min_value(t_map *map, int row, int col, int **tmp_matrix)
{
	int	min_val;

	if (map->matrix[row][col] == map->obstacle)
		tmp_matrix[row][col] = 0;
	else if (row == 0 || col == 0)
		tmp_matrix[row][col] = 1;
	else
	{
		min_val = tmp_matrix[row - 1][col - 1];
		if (tmp_matrix[row - 1][col] < min_val)
			min_val = tmp_matrix[row - 1][col];
		if (tmp_matrix[row][col - 1] < min_val)
			min_val = tmp_matrix[row][col - 1];
		tmp_matrix[row][col] = min_val + 1;
	}
}

// Print the map to standard output
void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(1, map->matrix[i], map->cols);
		write(1, "\n", 1);
		i++;
	}
}
