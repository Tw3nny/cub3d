/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 22:12:32 by tw3nny            #+#    #+#             */
/*   Updated: 2026/09/03 23:52:31 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

/* ========================= */
/*         Structures        */
/* ========================= */

typedef struct s_scene
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	unsigned int	f_color;
	unsigned int	c_color;
	char			**map;
	int				map_width;
	int				map_height;
	int				spawn_y;
	int				spawn_x;
	char			spawn_dir;
}	t_scene;

/* ========================= */
/*          Fonctions        */
/* ========================= */

void	error(char *arg, char *str);
void	error_sys(char *path);
void	free_grid(char **grid);
char	**read_file(char *path);
void	free_scene(t_scene *scene);
int		parse_scene(char *path, t_scene *scene);
int		parse_color(char *str, unsigned int *color);
int		parse_header(char **lines, int *i, t_scene *scene);
int		parse_map(char **lines, int i, t_scene *scene);
int		check_map(t_scene *scene);
int		check_extension(char *path, char *ext);
int		check_texture(char *path);

#endif
