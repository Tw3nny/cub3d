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

int cross_close_event()
{
    printf("fermeture");
    exit(0);
}

int esc_close_event(int keycode)
{
    if(keycode == 65307)
    {
        printf("fermeture");
        exit(0);
    }
    return(0);
}