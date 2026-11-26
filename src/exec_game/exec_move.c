/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:32:46 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/25 10:48:33 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_forward(t_all *all)
{
    double new_x;
    double new_y;

    new_x = all->player.pos_x + all->player.eyes_x * 0.1;
    new_y = all->player.pos_y + all->player.eyes_y * 0.1;
    if(all->scene->map[(int)new_y][(int)new_x] != '1')
    {
        all->player.pos_x = new_x;
        all->player.pos_y = new_y;
    }
}
void move_back(t_all *all)
{
    double new_x;
    double new_y;

    new_x = all->player.pos_x - all->player.eyes_x * 0.1;
    new_y = all->player.pos_y - all->player.eyes_y * 0.1;
    if(all->scene->map[(int)new_y][(int)new_x] != '1')
    {
        all->player.pos_x = new_x;
        all->player.pos_y = new_y;
    }
}