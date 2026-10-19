/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 07:23:22 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/10/19 08:05:45 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void calcul_pos(t_scene *scene, t_player *player)
{
    player->pos_x = scene->spawn_x + 0.5;
    player->pos_y = scene->spawn_y + 0.5;
}

void calcul_fov_eyes(t_scene *scene, t_player *player)
{
    if (scene->spawn_dir == 'N')
    {
        player->eyes_x = 0;
        player->eyes_y = -1;
        player->fov_x = 0.66;
        player->fov_y = 0;
    }
    else if (scene->spawn_dir == 'S')
    {
        player->eyes_x = 0;
        player->eyes_y = 1;
        player->fov_x = -0.66;
        player->fov_y = 0;
    }
    else if (scene->spawn_dir == 'E')
    {
        player->eyes_x = 1;
        player->eyes_y = 0;
        player->fov_x = 0;
        player->fov_y = 0.66;
    }
    else
    {
        player->eyes_x = -1;
        player->eyes_y = 0;
        player->fov_x = 0;
        player->fov_y = -0.66;
    }
}
