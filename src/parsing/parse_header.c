/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:54:07 by matisgutier       #+#    #+#             */
/*   Updated: 2026/09/03 23:54:36 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//globale autorise si static + const
static const char	*g_ids[6] = {"NO", "SO", "WE", "EA", "F", "C"};

static int	find_id(char *line)
{
	int	j;
	int	len;

	j = 0;
	while (j < 6)
	{
		len = ft_strlen(g_ids[j]);
		if (!ft_strncmp(g_ids[j], line, len) && line[len] == ' ')
			return (j);
		j++;
	}
	return (-1);
}

static void	set_texture(int j, t_scene *scene, char *value)
{
	if (j == 0)
		scene->no = value;
	else if (j == 1)
		scene->so = value;
	else if (j == 2)
		scene->we = value;
	else
		scene->ea = value;
}

static int	store_value(char *line, int j, t_scene *scene)
{
	char	*value;
	int		ok;

	value = ft_strtrim(line + ft_strlen(g_ids[j]), " ");
	if (!value)
		return (error(line, "allocation failed"), 0);
	if (!value[0])
		return (free(value), error(line, "element without value"), 0);
	if (ft_strchr(value, ' '))
		return (free(value), error(line, "element has more than one value"), 0);
	if (j >= 4)
	{
		if (j == 4)
			ok = parse_color(value, &scene->f_color);
		else
			ok = parse_color(value, &scene->c_color);
		free(value);
		if (!ok)
			return (error (line, "invalid color"), 0);
		return (1);
	}
	if (!check_texture(value))
		return (free(value), 0);
	set_texture(j, scene, value);
	return (1);
}


static int	handle_line(char *line, int *found, t_scene *scene)
{
	int	j;

	j = find_id(line);
	if (j < 0)
		return (error(line, "unknow identifier"), 0);
	if (found[j])
		return (error(line, "duplicate identifier"), 0);
	if (!store_value(line, j, scene))
		return (0);
	found[j] = 1;
	return (1);
}

int	parse_header(char **lines, int *i, t_scene *scene)
{
	int	found[6];
	int	count;

	ft_bzero(found, sizeof(found));
	count = 0;
	while (lines[*i] && count < 6)
	{
		if (lines[*i][0])
		{
			if (!handle_line(lines[*i], found, scene))
				return (0);
			count++;
		}
		(*i)++;
	}
	if (count < 6)
		return (error(NULL, "missing element in header"), 0);
	while (lines[*i] && !lines[*i][0])
		(*i)++;
	return (1);
}

