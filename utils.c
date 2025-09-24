/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnovikov <dnovikov@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:43:55 by dnovikov          #+#    #+#             */
/*   Updated: 2025/09/24 20:32:37 by dnovikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

//Print error message for map-related errors
void	*ft_print_map_error(void)
{
	write(1, "map error\n", 10);
	return (NULL);
}

//Get file descriptor for input source
int	ft_get_fd(char *file_name)
{
	int	fd;

	if (!file_name)
		fd = 0;
	else
		fd = open(file_name, O_RDONLY);
	return (fd);
}

// Read one line from a file descriptor
char	*ft_get_next_line(int fd)
{
	char	*line;
	char	buffer;
	int		bytes_read;
	int		i;

	line = (char *)malloc(1000 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0 && buffer != '\n')
	{
		line[i++] = buffer;
		bytes_read = read(fd, &buffer, 1);
	}
	if (bytes_read == -1 || (bytes_read == 0 && i == 0))
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

// Allocate a 2D integer matrix for dynamic programming
int	**ft_allocate_tmp_matrix(int rows, int cols)
{
	int	**tmp_m;
	int	i;

	tmp_m = (int **)malloc(sizeof(int *) * rows);
	if (!tmp_m)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		tmp_m[i] = (int *)malloc(sizeof(int) * cols);
		if (!tmp_m[i])
		{
			while (i > 0)
			{
				free(tmp_m[i - 1]);
				i--;
			}
			free(tmp_m);
			return (NULL);
		}
		i++;
	}
	return (tmp_m);
}

// Free a 2D integer matrix allocated by ft_allocate_tmp_matrix
void	ft_free_tmp_matrix(int **tmp_m, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(tmp_m[i]);
		i++;
	}
	free(tmp_m);
}
