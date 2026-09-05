/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 22:28:02 by tw3nny            #+#    #+#             */
/*   Updated: 2026/08/30 20:26:42 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *arg, char *str)
{
	write(2, "Error\n", 6);
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(str, 2);
}

void	error_sys(char *path)
{
	write(2, "Error\n", 6);
	perror(path);
}

void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_scene(t_scene *scene)
{
	free(scene->no);
	free(scene->so);
	free(scene->we);
	free(scene->ea);
	free_grid(scene->map);
}

int	check_extension(char *path, char *ext)
{
	char	*base;
	char	*slash;
	int		base_len;
	int		ext_len;

	slash = ft_strrchr(path, '/');
	if (slash)
		base = slash + 1;
	else
		base = path;
	ext_len = ft_strlen(ext);
	base_len = ft_strlen(base);
	if (base_len <= ext_len)
		return (0);
	if (ft_strncmp(base + base_len - ext_len, ext, ext_len))
		return (0);
	return (1);
}
