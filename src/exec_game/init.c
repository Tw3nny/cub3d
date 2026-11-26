/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 07:23:22 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/26 21:53:11 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_mlx(t_all *all)
{
	all->display.init = mlx_init();
	if(!all->display.init)
		return (error(NULL, "mlx_init failed"), free_everything(all), 1);
	all->display.window = mlx_new_window(all->display.init, WIDTH, HEIGHT, "cub3D");
	if(!all->display.window)
		return (error(NULL, "mlx_new_window failed"),free_everything(all), 1);
	all->image.img = mlx_new_image(all->display.init, WIDTH, HEIGHT);
	if(!all->image.img)
		return (error(NULL, "mlx_new_image failed"), free_everything(all), 1);
	all->image.start_pixel = mlx_get_data_addr(all->image.img, &all->image.bits_per_pixel, &all->image.size_line, &all->image.endian);
	if(!all->image.start_pixel)
		return (error(NULL, "mlx_get_data_addr failed"), free_everything(all), 1);
	return(0);
}
int load_textures(t_all *all, t_scene *scene)
{
	int i;

	i = 0;
	all->texture[0].path = scene->no;
	all->texture[1].path = scene->so;
	all->texture[2].path = scene->we;
	all->texture[3].path = scene->ea;
	while(i < 4)
	{
		all->texture[i].image.img = mlx_xpm_file_to_image(all->display.init, all->texture[i].path, &all->texture[i].width, &all->texture[i].height);
		if (!all->texture[i].image.img)
			return (error(all->texture[i].path, "broken file"), free_everything(all), 1);
		all->texture[i].image.start_pixel = mlx_get_data_addr(all->texture[i].image.img, &all->texture[i].image.bits_per_pixel, &all->texture[i].image.size_line, &all->texture[i].image.endian);
		if (!all->texture[i].image.start_pixel)
			return (error(NULL, "mlx_get_data_addr failed"), free_everything(all), 1);
		i++;
	}
	return(0);
}
void calcul_pos(t_scene *scene, t_player *player)
{
    player->pos_x = scene->spawn_x + 0.5;
    player->pos_y = scene->spawn_y + 0.5;
}

void calcul_fov_eyes(t_scene *scene, t_player *player)
{
    player->eyes_x = 0;
    player->eyes_y = 0;
    if (scene->spawn_dir == 'N')
        player->eyes_y = -1;
    else if (scene->spawn_dir == 'S')
        player->eyes_y = 1;
    else if (scene->spawn_dir == 'E')
        player->eyes_x = 1;
    else
        player->eyes_x = -1;
    player->fov_x = -player->eyes_y * 0.66;
    player->fov_y = player->eyes_x * 0.66;
}
