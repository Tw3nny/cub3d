/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 22:12:32 by tw3nny            #+#    #+#             */
/*   Updated: 2026/10/31 03:15:21 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "../minilibx-linux/mlx.h"

# define HEIGHT 600
# define WIDTH 800

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

typedef struct s_display
{
	void *init;
	void *window;
}	t_display;

typedef struct s_image
{
	void *img;
	int bits_per_pixel;
	int size_line;
	int endian;
	char *start_pixel;
}	t_image;

typedef struct s_player
{
	double pos_x;
	double pos_y;
	double eyes_x;
	double eyes_y;
	double fov_x;
	double fov_y;
} t_player;

typedef struct s_cam
{
	double camera_x;
    double rayon_x;
    double rayon_y;
} t_cam;

typedef struct s_all
{
	struct s_scene *scene;
	struct s_display display;
	struct s_image image;
	struct s_player player;
} t_all;

/* ========================= */
/*          Parsing          */
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

/* ========================= */
/*          Exec             */
/* ========================= */

int cross_close_event(t_all *all);
int esc_close_event(int keycode, t_all *all);
void free_everything(t_all *all);
void calcul_pos(t_scene *scene, t_player *player);
void calcul_fov_eyes(t_scene *scene, t_player *player);
void sky_ground(t_all *all);
void draw_s_g(t_all *all, int y, unsigned int color_to_draw);
void calcul_camera(t_scene *scene, t_player *player);

#endif
