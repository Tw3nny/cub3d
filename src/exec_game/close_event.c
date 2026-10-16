/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_close_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 23:16:04 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/10/15 00:07:22 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_everything(t_all *all)
{
    mlx_destroy_image(all->display.init, all->image.img);
    mlx_destroy_window(all->display.init, all->display.window);
    mlx_destroy_display(all->display.init);
    free(all->display.init);
    free_scene(all->scene);
}

int cross_close_event(t_all *all)
{
    free_everything(all);
    printf("fermeture");
    exit(0);
}

int esc_close_event(int keycode, t_all *all)
{
    if(keycode == 65307)
    {
        free_everything(all);
        printf("fermeture");
        exit(0);
    }
    return(0);
}