/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 07:23:22 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/13 09:26:05 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void calcul_camera(t_all *all)
{
    t_cam cam;
    t_draw draw;
    double x;
    int y;

    x = 0;
    while(x < WIDTH)
    {
        player_setup(all, &cam, x);
        rayon_cam(all, &cam);
        cam_view(all, &cam);
        draw.line_height = HEIGHT / cam.distance;
        draw.draw_start = HEIGHT / 2 - draw.line_height / 2;
        draw.draw_end = HEIGHT / 2 + draw.line_height / 2;
        if(draw.draw_start < 0)
            draw.draw_start = 0;
        if(draw.draw_end >= HEIGHT)
            draw.draw_end = HEIGHT - 1;
        y = draw.draw_start;
        while (y <= draw.draw_end)
        {
            draw_pixel(all, x, y, 0xFF0000);
            y++;
        }
        x++;
    }
}

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
