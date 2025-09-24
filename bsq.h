/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:16:39 by dnovikov          #+#    #+#             */
/*   Updated: 2025/09/24 23:06:48 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>	// malloc, free, exit
# include <unistd.h>	// read, write, close
# include <fcntl.h>		// File control (open, O_RDONLY)

//#include <stdio.h>

typedef struct s_map
{
	/* Map dimensions */
	int		rows;
	int		cols;

	/* Character definitions from map header */
	char	empty;
	char	obstacle;
	char	full;

	/* Map content */
	char	**matrix;

	/* Solution parameters (biggest square found) */
	int		square_size;
	int		square_row;
	int		square_col;
}	t_map;

/*-----------------------------------------------------------------------------
 * UTILITY FUNCTIONS
 *---------------------------------------------------------------------------*/
void	*ft_print_map_error(void);
int		ft_get_fd(char *file_name);
char	*ft_get_next_line(int fd);
int		ft_is_printable(char c);
int		ft_is_number(char *str);
int		ft_is_line_valid(char *str, t_map *map);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		**ft_allocate_tmp_matrix(int rows, int cols);
void	ft_free_tmp_matrix(int **tmp_m, int rows);
int		ft_is_eof(int file_name);
int		ft_is_digit(char c);

/*-----------------------------------------------------------------------------
 * MAP MANAGEMENT FUNCTIONS
 *---------------------------------------------------------------------------*/
t_map	*ft_create_map(char *file_name);
void	ft_free_map(t_map *map);
int		ft_parse_map_header(t_map *map, int file_name);
int		ft_parse_map(t_map *map, int file_name);
void	ft_process_map(t_map *map);
void	ft_print_map(t_map *map);
void	ft_set_min_value(t_map *map, int row, int col, int **tmp_matrix);
void	ft_set_square_parameters(
			int **tmp_matrix, int row, int col, t_map *map);
void	ft_add_square_to_map(t_map *map);
void	ft_find_max_square(t_map *map);
void	ft_set_min_value(t_map *map, int row, int col, int **tmp_matrix);

#endif
