/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 08:37:43 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/26 22:02:14 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	choose_texure(t_cam *cam)
{
	if (cam->side == 0)
	{
		if (cam->step_x == 1)
			return (2);
		else
			return (3);
	}
	else
	{
		if (cam->step_y == 1)
			return (0);
		else
			return (1);
	}
}

unsigned int	read_pixel(t_texture *tex, int x, int y)
{
	int				gap;
	char			*pixel;
	unsigned int	color;

	gap = y * tex->image.size_line + x * (tex->image.bits_per_pixel / 8);
	pixel = tex->image.start_pixel + gap;
	color = *(unsigned int *)pixel;
	return (color);
}

void	draw_col(t_all *all, t_draw *draw, double x, t_texture *tex)
{
	int	y;
	int	top_wall;
	int	tex_y;

	y = draw->draw_start;
	top_wall = HEIGHT / 2 - draw->line_height / 2;
	while (y <= draw->draw_end)
	{
		tex_y = (y - top_wall) * tex->height / draw->line_height;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		draw_pixel(all, x, y, read_pixel(tex, draw->tex_x, tex_y));
		y++;
	}
}
