/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:31:57 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/26 22:31:42 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel(t_all *all, int x, int y, unsigned int color_to_draw)
{
	int		gap;
	char	*pixel;

	gap = (y * all->image.size_line + x * (all->image.bits_per_pixel / 8));
	pixel = all->image.start_pixel + gap;
	*(unsigned int *)pixel = color_to_draw;
}

void	draw_s_g(t_all *all, int y, unsigned int color_to_draw)
{
	int		gap;
	char	*pixel;
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		gap = (y * all->image.size_line + x * (all->image.bits_per_pixel / 8));
		pixel = all->image.start_pixel + gap;
		*(unsigned int *)pixel = color_to_draw;
		x++;
	}
}

void	sky_ground(t_all *all)
{
	int	y;

	y = 0;
	while (y < (HEIGHT / 2))
	{
		draw_s_g(all, y, all->scene->c_color);
		y++;
	}
	while (y < HEIGHT)
	{
		draw_s_g(all, y, all->scene->f_color);
		y++;
	}
}

void	calcul_camera(t_all *all)
{
	t_cam	cam;
	t_draw	draw;
	int		i;
	double	x;

	x = 0;
	while (x < WIDTH)
	{
		rayon_col(all, &cam, x);
		init_steps(all, &cam);
		find_wall(all, &cam);
		calcul_draw_limit(&draw, &cam);
		i = choose_texure(&cam);
		draw.tex_x = (int)(wall_x(all, &cam) * all->tex[i].width);
		if ((cam.side == 0 && cam.rayon_x < 0) || (cam.side == 1
				&& cam.rayon_y > 0))
			draw.tex_x = all->tex[i].width - 1 - draw.tex_x;
		draw_col(all, &draw, x, &all->tex[i]);
		x++;
	}
}

void	render(t_all *all)
{
	sky_ground(all);
	calcul_camera(all);
	mlx_put_image_to_window(all->display.init, all->display.window,
		all->image.img, 0, 0);
}
