/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:37:43 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/10/19 09:37:22 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_s_g(t_all *all, int y, unsigned int color_to_draw)
{
    int gap;
	char *pixel;
    int x;

    x = 0;
    while(x < WIDTH)
    {
        gap = (y * all->image.size_line + x * (all->image.bits_per_pixel / 8));
        pixel = all->image.start_pixel + gap;
        *(unsigned int *)pixel = color_to_draw;
        x++;
    }
}

void sky_ground(t_all *all)
{
    int y;

    y = 0;
	while(y < (HEIGHT / 2))
	{
        draw_s_g(all, y, all->scene->c_color);
		y++;
	}
    while(y < HEIGHT)
    {
        draw_s_g(all, y, all->scene->f_color);
        y++;
    }
}
