/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:55:49 by matisgutier       #+#    #+#             */
/*   Updated: 2026/09/04 22:03:04 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	scan_row(t_scene *scene, int y, int *spawns)
{
	int		x;
	char	c;

	x = 0;
	while (x < scene->map_width)
	{
		c = scene->map[y][x];
		if (!ft_strchr("01 NSEW", c))
			return (error(NULL, "illegal character in the map"), 0);
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		{
			scene->spawn_y = y;
			scene->spawn_x = x;
			scene->spawn_dir = c;
			(*spawns)++;
		}
		x++;
	}
	return (1);
}

static int	check_chars(t_scene *scene)
{
	int	y;
	int	spawns;

	spawns = 0;
	y = 0;
	while (y < scene->map_height)
	{
		if (!scan_row(scene, y, &spawns))
			return (0);
		y++;
	}
	if (spawns == 0)
		return (error(NULL, "no player start position"), 0);
	if (spawns > 1)
		return (error(NULL, "more than 1 player start position"), 0);
	return (1);
}

static int	flood(char **g, int y, int x)
{
	if (g[y][x] == ' ')
		return (0);
	if (g[y][x] == '1' || g[y][x] == 'v')
		return (1);
	g[y][x] = 'v';
	return (flood(g, y - 1, x) && flood(g, y + 1, x)
		&& flood(g, y, x - 1) && flood(g, y, x + 1));
}

static void	close_grid(t_scene *scene)
{
	int	y;
	int	x;
	
	y = 0;
	while (y < scene->map_height)
	{
		x = 0;
		while (x < scene->map_width)
		{
			if (scene->map[y][x] == 'v')
				scene->map[y][x] = '0';
			else if (scene->map[y][x] == ' ')
				scene->map[y][x] = '1';
			x++;
		}
		y++;
	}
}

int	check_map(t_scene *scene)
{
	if (!check_chars(scene))
		return (0);
	if (!flood(scene->map, scene->spawn_y, scene->spawn_x))
		return (error(NULL, "the map is not closed"), 0);
	close_grid(scene);
	return (1);
}
