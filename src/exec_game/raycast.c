/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 12:36:42 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/26 22:02:27 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rayon_col(t_all *all, t_cam *cam, double x)
{
	cam->wall_touched = 0;
	cam->posmap_x = (int)all->player.pos_x;
	cam->posmap_y = (int)all->player.pos_y;
	cam->camera_x = 2 * x / WIDTH - 1;
	cam->rayon_x = all->player.eyes_x + all->player.fov_x * cam->camera_x;
	cam->rayon_y = all->player.eyes_y + all->player.fov_y * cam->camera_x;
	cam->delta_dist_x = fabs(1 / cam->rayon_x);
	cam->delta_dist_y = fabs(1 / cam->rayon_y);
}

void	init_steps(t_all *all, t_cam *cam)
{
	if (cam->rayon_x < 0)
	{
		cam->step_x = -1;
		cam->side_dist_x = (all->player.pos_x - cam->posmap_x)
			* cam->delta_dist_x;
	}
	else
	{
		cam->step_x = 1;
		cam->side_dist_x = (cam->posmap_x + 1.0 - all->player.pos_x)
			* cam->delta_dist_x;
	}
	if (cam->rayon_y < 0)
	{
		cam->step_y = -1;
		cam->side_dist_y = (all->player.pos_y - cam->posmap_y)
			* cam->delta_dist_y;
	}
	else
	{
		cam->step_y = 1;
		cam->side_dist_y = (cam->posmap_y + 1.0 - all->player.pos_y)
			* cam->delta_dist_y;
	}
}

void	find_wall(t_all *all, t_cam *cam)
{
	cam->side = 0;
	while (cam->wall_touched == 0)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			cam->posmap_x += cam->step_x;
			cam->side = 0;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			cam->posmap_y += cam->step_y;
			cam->side = 1;
		}
		if (cam->side == 0)
			cam->distance = cam->side_dist_x - cam->delta_dist_x;
		else
			cam->distance = cam->side_dist_y - cam->delta_dist_y;
		if (all->scene->map[cam->posmap_y][cam->posmap_x] == '1')
			cam->wall_touched = 1;
	}
}

void	calcul_draw_limit(t_draw *draw, t_cam *cam)
{
	if (cam->distance < 0.01)
		cam->distance = 0.01;
	draw->line_height = HEIGHT / cam->distance;
	if (draw->line_height < 1)
		draw->line_height = 1;
	draw->draw_start = HEIGHT / 2 - draw->line_height / 2;
	draw->draw_end = HEIGHT / 2 + draw->line_height / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	if (draw->draw_end >= HEIGHT)
		draw->draw_end = HEIGHT - 1;
}

double	wall_x(t_all *all, t_cam *cam)
{
	double	res;

	if (cam->side == 0)
		res = all->player.pos_y + cam->distance * cam->rayon_y;
	else
		res = all->player.pos_x + cam->distance * cam->rayon_x;
	return (res - floor(res));
}
