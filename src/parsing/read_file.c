/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 21:22:55 by tw3nny            #+#    #+#             */
/*   Updated: 2026/08/02 19:56:40 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	fill_grid(char **grid, char *path, int height)
{
	int	i;
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		error_sys(path);
		return (0);
	}
	i = 0;
	while (i < height)
	{
		grid[i] = get_next_line(fd);
		if (grid[i] == NULL)
		{
			close(fd);
			return (error(path, "read failed"), 0);
		}
		if (grid[i][ft_strlen(grid[i]) - 1] == '\n')
			grid[i][ft_strlen(grid[i]) - 1] = '\0';
		i++;
	}
	close(fd);
	return (1);
}

char	**read_file(char *path)
{
	char	**grid;
	int		fd;
	int		height;

	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (error(path, "is a directory"), NULL);
	}
	height = count_lines(path);
	if (height == 0)
		return (error(path, "empty file"), NULL);
	if (height < 0)
		return (error_sys(path), NULL);
	grid = ft_calloc(height + 1, sizeof(char *));
	if (!grid)
		return (error_sys(path), NULL);
	if (!fill_grid(grid, path, height))
		return (free_grid(grid), NULL);
	return (grid);
}
