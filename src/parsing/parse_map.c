/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:54:43 by matisgutier       #+#    #+#             */
/*   Updated: 2026/09/04 23:08:41 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_rows(char **lines, int i)
{
	int	rows;

	rows = 0;
	while (lines[i + rows])
	{
		if ((!lines[i + rows][0]))
			return (-1);
		rows++;
	}
	return (rows);
}

static int	longest_row(char **lines, int i, int rows)
{
	int	w;
	int	len;
	int	k;

	w = 0;
	k = 0;
	while (k < rows)
	{
		len = ft_strlen(lines[i + k]);
		if (len > w)
			w = len;
		k++;
	}
	return (w);
}

static char	**alloc_grid(int h, int w)
{
	char	**g;
	int		y;

	g = ft_calloc(h + 1, sizeof(char *));
	if (!g)
		return (NULL);
	y = 0;
	while (y < h)
	{
		g[y] = malloc(w + 1);
		if (!g[y])
			return (free_grid(g), NULL);
		ft_memset(g[y], ' ', w);
		g[y][w] = '\0';
		y++;
	}
	return (g);
}

static void	copy_rows(char **g, char **lines, int i, int rows)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (lines[i + y][x])
		{
			g[y + 1][x + 1] = lines[i + y][x];
			x++;
		}
		y++;
	}
}

int	parse_map(char **lines, int i, t_scene *scene)
{
	int	rows;
	int	cols;

	rows = count_rows(lines, i);
	if (rows < 0)
		return (error(NULL, "empty line inside the map"), 0);
	if (rows == 0)
		return (error(NULL, "no map found"), 0);
	cols = longest_row(lines, i, rows);
	scene->map_height = rows + 2;
	scene->map_width = cols + 2;
	scene->map = alloc_grid(scene->map_height, scene->map_width);
	if(!scene->map)
		return (error(NULL, "allocation failed"), 0);
	copy_rows(scene->map, lines, i, rows);
	return (1);
}
