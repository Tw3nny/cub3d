/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:32:46 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/26 20:40:26 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotate(t_all *all, int keycode)
{
    double old_eyes_x;
    double old_fov_x;
    
    if(keycode == 65363 )
    {
        old_eyes_x = all->player.eyes_x;
        old_fov_x = all->player.fov_x;
        all->player.eyes_x = old_eyes_x * cos(0.05) - all->player.eyes_y * sin(0.05);
        all->player.eyes_y = old_eyes_x * sin(0.05) + all->player.eyes_y * cos(0.05);
        all->player.fov_x = old_fov_x * cos(0.05) - all->player.fov_y * sin(0.05);
        all->player.fov_y = old_fov_x * sin(0.05) + all->player.fov_y * cos(0.05);
    }
    if(keycode == 65361)
    {
        old_eyes_x = all->player.eyes_x;
        old_fov_x = all->player.fov_x;
        all->player.eyes_x = old_eyes_x * cos(-0.05) - all->player.eyes_y * sin(-0.05);
        all->player.eyes_y = old_eyes_x * sin(-0.05) + all->player.eyes_y * cos(-0.05);
        all->player.fov_x = old_fov_x * cos(-0.05) - all->player.fov_y * sin(-0.05);
        all->player.fov_y = old_fov_x * sin(-0.05) + all->player.fov_y * cos(-0.05);

    }
}

void move(t_all *all, int keycode)
{
    double new_x;
    double new_y;

    if(keycode == 119)
    {
        new_x = all->player.pos_x + all->player.eyes_x * 0.1;
        new_y = all->player.pos_y + all->player.eyes_y * 0.1;
    } else if (keycode == 115)
    {
        new_x = all->player.pos_x - all->player.eyes_x * 0.1;
        new_y = all->player.pos_y - all->player.eyes_y * 0.1;
    } else if (keycode == 100)
    {
        new_x = all->player.pos_x + all->player.fov_x * 0.1;
        new_y = all->player.pos_y + all->player.fov_y * 0.1;
    } else if (keycode == 97)
    {
        new_x = all->player.pos_x - all->player.fov_x * 0.1;
        new_y = all->player.pos_y - all->player.fov_y * 0.1;        
    }
    if(all->scene->map[(int)new_y][(int)new_x] != '1')
    {
        all->player.pos_x = new_x;
        all->player.pos_y = new_y;
    }
}
