/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:36:47 by tw3nny            #+#    #+#             */
/*   Updated: 2026/10/15 00:19:42 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_scene	scene;
	void *init;
	void *window;
	int	y;

	ft_bzero(&scene, sizeof(t_scene));
	if (ac != 2)
		return (error(NULL, "usage: ./cub3d <map.cub>"), 1);
	if (!parse_scene(av[1], &scene))
		return (free_scene(&scene), 1);
	//print toute les valeurs parser de la struct : map, spawn, texture...
	printf("NO = %s\n", scene.no);
	printf("f_color = 0x%06X\n", scene.f_color);
	printf("map %d x %d   spawn (%d,%d) dir %c\n", scene.map_width, scene.map_height, scene.spawn_x, scene.spawn_y, scene.spawn_dir);
	y = 0;
	while (y < scene.map_height)
		printf("|%s|\n", scene.map[y++]);
	init = mlx_init();
	if(!init)
		return (free_scene(&scene), 1);
	window = mlx_new_window(init, 800, 600, "cub3d");
	if(!window)
		return (free_scene(&scene), 1);
	mlx_hook(window, 17, 0, cross_close_event, NULL);
	mlx_hook(window, 2, 1L<<0, esc_close_event, NULL);
	if(!mlx_loop(init))
		return (free_scene(&scene), 1);
	free_scene(&scene);
	return (0);
}
