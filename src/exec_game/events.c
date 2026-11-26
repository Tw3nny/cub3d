/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 22:03:25 by Neanuphar         #+#    #+#             */
/*   Updated: 2026/11/26 22:03:30 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_everything(t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (all->texture[i].image.img != NULL)
			mlx_destroy_image(all->display.init, all->texture[i].image.img);
		i++;
	}
	if (all->image.img != NULL)
		mlx_destroy_image(all->display.init, all->image.img);
	if (all->display.window != NULL)
		mlx_destroy_window(all->display.init, all->display.window);
	if (all->display.init != NULL)
	{
		mlx_destroy_display(all->display.init);
		free(all->display.init);
	}
	free_scene(all->scene);
}

int	cross_close_event(t_all *all)
{
	free_everything(all);
	exit(0);
}

int	click_event(int keycode, t_all *all)
{
	if (keycode == 65307)
	{
		free_everything(all);
		exit(0);
	}
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
	{
		move(all, keycode);
		render(all);
	}
	if (keycode == 65363 || keycode == 65361)
	{
		rotate(all, keycode);
		render(all);
	}
	return (0);
}
