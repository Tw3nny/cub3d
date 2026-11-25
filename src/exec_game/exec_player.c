/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 07:23:22 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/25 10:13:18 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_col(t_all *all, t_draw *draw, double x, t_texture *tex)
{
    int y;
    int top_wall;
    int tex_y;

    y = draw->draw_start;
    top_wall = HEIGHT / 2 - draw->line_height / 2;
    while (y <= draw->draw_end)
    {
        tex_y = (y - top_wall) * tex->height / draw->line_height;
        if(tex_y >= tex->height)
            tex_y = tex->height - 1;
        draw_pixel(all, x, y, read_pixel(tex, draw->tex_x, tex_y));
        y++;
    }
}

void calcul_camera(t_all *all)
{
    t_cam cam;
    t_draw draw;
    int i;
    double x;

    x = 0;
    while(x < WIDTH)
    {
        rayon_col(all, &cam, x);
        init_steps(all, &cam);
        find_wall(all, &cam);
        calcul_draw_limit(&draw, &cam);
        i = choose_texure(&cam);
        draw.tex_x = (int)(wall_x(all, &cam) * all->texture[i].width);
       draw_col(all, &draw, x, &all->texture[i]);
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
