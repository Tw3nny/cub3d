/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:31:57 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/24 00:21:26 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int choose_texure(t_cam *cam)
{
    if(cam->side == 0)
    {
        if(cam->step_x == 1)
            return (2);
        else
            return (3);
    }
    else
    {
        if(cam->step_y == 1)
            return (0);
        else
            return (1);
    }
}

unsigned int read_pixel(t_texture *tex, int x, int y)
{
    int gap;
    char *pixel;
    unsigned int color;

    gap = y * tex->image.size_line + x *(tex->image.bits_per_pixel / 8);
    pixel = tex->image.start_pixel + gap;
    color = *(unsigned int *)pixel;

    return(color);
}