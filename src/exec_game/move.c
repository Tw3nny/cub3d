/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 10:32:46 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/26 22:18:23 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_all *all, int keycode)
{
	double	old_eyes_x;
	double	old_fov_x;
	double	angle;

	old_eyes_x = all->player.eyes_x;
	old_fov_x = all->player.fov_x;
	angle = 0.05;
	if (keycode == 65361)
		angle = -0.05;
	all->player.eyes_x = old_eyes_x * cos(angle) - all->player.eyes_y
		* sin(angle);
	all->player.eyes_y = old_eyes_x * sin(angle) + all->player.eyes_y
		* cos(angle);
	all->player.fov_x = old_fov_x * cos(angle) - all->player.fov_y * sin(angle);
	all->player.fov_y = old_fov_x * sin(angle) + all->player.fov_y * cos(angle);
}

void	try_move(t_all *all, double dir_x, double dir_y)
{
	double	new_x;
	double	new_y;

	new_x = all->player.pos_x + dir_x * 0.1;
	new_y = all->player.pos_y + dir_y * 0.1;
	if (all->scene->map[(int)new_y][(int)new_x] != '1')
	{
		all->player.pos_x = new_x;
		all->player.pos_y = new_y;
	}
}

void	move(t_all *all, int keycode)
{
	if (keycode == 119)
		try_move(all, all->player.eyes_x, all->player.eyes_y);
	else if (keycode == 115)
		try_move(all, -all->player.eyes_x, -all->player.eyes_y);
	else if (keycode == 100)
		try_move(all, all->player.fov_x, all->player.fov_y);
	else if (keycode == 97)
		try_move(all, -all->player.fov_x, -all->player.fov_y);
}
