/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:42:16 by tw3nny            #+#    #+#             */
/*   Updated: 2026/09/03 23:57:58 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(char *path)
{
	int	fd;

	if (!check_extension(path, ".xpm"))
		return (error(path, "texture is not a .xpm file"), 0);
	fd = open(path, O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), error(path, "texture is a directory"), 0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (error_sys(path), 0);
	close(fd);
	return (1);
}

int	parse_scene(char *path, t_scene *scene)
{
	char	**lines;
	int		i;

	if (!check_extension(path, ".cub"))
		return (error(path, "invalid file extension"), 0);
	lines = read_file(path);
	if (!lines)
		return (0);
	i = 0;
	if (!parse_header(lines, &i, scene) || !parse_map(lines, i, scene))
	{
		free_grid(lines);
		return (0);
	}
	free_grid(lines);
	if (!check_map(scene))
		return (0);
	return (1);
}
