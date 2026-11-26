/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:36:47 by tw3nny            #+#    #+#             */
/*   Updated: 2026/11/26 22:01:31 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_all	all;
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	ft_bzero(&all, sizeof(t_all));
	all.scene = &scene;
	if (ac != 2)
		return (error(NULL, "usage: ./cub3D <map.cub>"), 1);
	if (!parse_scene(av[1], &scene))
		return (free_scene(&scene), 1);
	calcul_pos(all.scene, &all.player);
	calcul_fov_eyes(all.scene, &all.player);
	if (init_mlx(&all) == 1)
		return (1);
	if (load_textures(&all, &scene) == 1)
		return (1);
	render(&all);
	mlx_hook(all.display.window, 17, 0, cross_close_event, &all);
	mlx_hook(all.display.window, 2, 1L << 0, click_event, &all);
	mlx_loop(all.display.init);
	free_everything(&all);
	return (0);
}
