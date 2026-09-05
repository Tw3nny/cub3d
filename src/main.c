/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tw3nny <tw3nny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:36:47 by tw3nny            #+#    #+#             */
/*   Updated: 2026/09/05 18:28:53 by tw3nny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_scene	scene;
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
	free_scene(&scene);
	return (0);
}
