/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:31:57 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/23 15:56:19 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int choose_texure(t_cam *cam)
{
    if(cam->side == 0)
    {
        if(cam->step_x == 1)
            return (0x0000FF);
        else
            return (0xFFFF00);
    }
    else
    {
        if(cam->step_y == 1)
            return (0xFF0000);
        else
            return (0x00FF00);
    }
}