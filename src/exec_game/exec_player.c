/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 07:23:22 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/10/31 14:56:54 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void calcul_camera(t_scene *scene, t_player *player)
{
    t_cam cam;
    double x;
    double delta_dist_x;
    double delta_dist_y;
    int step_x;
    int step_y;
    double side_dist_x;
    double side_dist_y;
    int posmap_x;
    int posmap_y;
    int wall_touched;
    int step;
    double distance;
    int line_height;
    int draw_start;
    int draw_end;

    x = 0;
    step = 0; 
    while(x < WIDTH)
    {
        wall_touched = 0;
        posmap_x = (int)player->pos_x;
        posmap_y = (int)player->pos_y;
        cam.camera_x = 2 * x / WIDTH - 1;
        cam.rayon_x = player->eyes_x + player->fov_x * cam.camera_x;
        cam.rayon_y = player->eyes_y + player->fov_y * cam.camera_x;
        delta_dist_x = fabs(1 / cam.rayon_x);
        delta_dist_y = fabs(1 / cam.rayon_y);
        if(cam.rayon_x < 0)
        {
            step_x = -1;
            side_dist_x = (player->pos_x - posmap_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (posmap_x + 1.0 - player->pos_x) * delta_dist_x;
        }
        if(cam.rayon_y < 0)
        {
            step_y = -1;
            side_dist_y = (player->pos_y - posmap_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (posmap_y + 1.0 - player->pos_y) * delta_dist_y;
        }
        while(wall_touched == 0)
        {
            if(side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                posmap_x += step_x;
                step = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                posmap_y += step_y;
                step = 1;
            }
            if(step == 0)
                distance = side_dist_x - delta_dist_x;
            else
                distance = side_dist_y - delta_dist_y;
            if(scene->map[posmap_y][posmap_x] == '1')
                wall_touched = 1;
        }
    line_height = HEIGHT / distance;
    draw_start = HEIGHT / 2 - line_height / 2;
    draw_end = HEIGHT / 2 + line_height / 2;
    if(draw_start < 0)
        draw_start = 0;
    if(draw_end >= HEIGHT)
        draw_end = HEIGHT - 1;
    if(x == 0 || x == 400 || x == 799)
        printf("line-height %d\n draw_start %d draw_end %d\n", line_height, draw_start, draw_end);
    //if(x == 0 || x == 400 || x == 799)
    //    printf("delta_dist_x %f,  delta_dist_y %f\nside_dist_x %f step_x %d\nside_dist_y %f step_y %d\n scene map %c\n step %d distance %f \n", delta_dist_x, delta_dist_y, side_dist_x, step_x, side_dist_y, step_y, scene->map[posmap_y][posmap_x], step, distance);
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
