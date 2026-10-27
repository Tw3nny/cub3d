/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:36:47 by tw3nny            #+#    #+#             */
/*   Updated: 2026/10/25 09:59:08 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_all	all;
	t_scene scene;
	int	y;

	ft_bzero(&scene, sizeof(t_scene));
	ft_bzero(&all, sizeof(t_all));
	all.scene = &scene;
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
	calcul_pos(all.scene, &all.player);
	calcul_fov_eyes(all.scene, &all.player);
	calcul_camera(&all.player);
	//printf("p_x : %f, p_y: %f \n all_spawn_x : %d, all_spwan_y : %d \n spawn_x : %d, spwan_y : %d \n", all.player.pos_x, all.player.pos_y, all.scene->spawn_x, all.scene->spawn_y, scene.spawn_x, scene.spawn_y );
	//printf("pour %c alors \n eyes_x : %f, eyes_y : %f \n fov_x : %f, fov_y : %f", all.scene->spawn_dir, all.player.eyes_x, all.player.eyes_y, all.player.fov_x, all.player.fov_y);
	all.display.init = mlx_init();
	if(!all.display.init)
		return (free_scene(&scene), 1);
	all.display.window = mlx_new_window(all.display.init, WIDTH, HEIGHT, "cub3d");
	if(!all.display.window)
		return (free_scene(&scene), 1);
	all.image.img = mlx_new_image(all.display.init, WIDTH, HEIGHT);
	if(!all.image.img)
		return (free_scene(&scene), 1);
	all.image.start_pixel = mlx_get_data_addr(all.image.img, &all.image.bits_per_pixel, &all.image.size_line, &all.image.endian);
	if(!all.image.start_pixel)
		return (free_scene(&scene), 1);
	sky_ground(&all);
	//printf("bits = %d, size = %d, endian = %d\n", all.image.bits_per_pixel, all.image.size_line, all.image.endian);
	//printf("map width %d  width %d", all.scene->map_width, scene.map_width);
	mlx_put_image_to_window(all.display.init, all.display.window, all.image.img, 0, 0);
	mlx_hook(all.display.window, 17, 0, cross_close_event, &all);
	mlx_hook(all.display.window, 2, 1L<<0, esc_close_event, &all);
	if(!mlx_loop(all.display.init))
		return (free_scene(&scene), 1);
	free_scene(&scene);
	return (0);
}
