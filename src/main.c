/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Neanuphar <Neanuphar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:36:47 by tw3nny            #+#    #+#             */
/*   Updated: 2026/11/26 21:28:11 by Neanuphar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int load_textures(t_all *all, t_scene *scene)
{
	int i;

	i = 0;
	all->texture[0].path = scene->no;
	all->texture[1].path = scene->so;
	all->texture[2].path = scene->we;
	all->texture[3].path = scene->ea;
	while(i < 4)
	{
		all->texture[i].image.img = mlx_xpm_file_to_image(all->display.init, all->texture[i].path, &all->texture[i].width, &all->texture[i].height);
		if (!all->texture[i].image.img)
			return (error(all->texture[i].path, "broken file"), free_everything(all), 1);
		all->texture[i].image.start_pixel = mlx_get_data_addr(all->texture[i].image.img, &all->texture[i].image.bits_per_pixel, &all->texture[i].image.size_line, &all->texture[i].image.endian);
		if (!all->texture[i].image.start_pixel)
			return (error(NULL, "mlx_get_data_addr failed"), free_everything(all), 1);
		i++;
	}
	return(0);
}

int init_mlx(t_all *all)
{
	all->display.init = mlx_init();
	if(!all->display.init)
		return (error(NULL, "mlx_init failed"), free_everything(all), 1);
	all->display.window = mlx_new_window(all->display.init, WIDTH, HEIGHT, "cub3D");
	if(!all->display.window)
		return (error(NULL, "mlx_new_window failed"),free_everything(all), 1);
	all->image.img = mlx_new_image(all->display.init, WIDTH, HEIGHT);
	if(!all->image.img)
		return (error(NULL, "mlx_new_image failed"), free_everything(all), 1);
	all->image.start_pixel = mlx_get_data_addr(all->image.img, &all->image.bits_per_pixel, &all->image.size_line, &all->image.endian);
	if(!all->image.start_pixel)
		return (error(NULL, "mlx_get_data_addr failed"), free_everything(all), 1);
	return(0);
}

void render(t_all *all)
{
	sky_ground(all);
	calcul_camera(all);
	mlx_put_image_to_window(all->display.init, all->display.window, all->image.img, 0, 0);	
}

int	main(int ac, char **av)
{
	t_all	all;
	t_scene scene;

	ft_bzero(&scene, sizeof(t_scene));
	ft_bzero(&all, sizeof(t_all));
	all.scene = &scene;
	if (ac != 2)
		return (error(NULL, "usage: ./cub3D <map.cub>"), 1);
	if (!parse_scene(av[1], &scene))
		return (free_scene(&scene), 1);
	calcul_pos(all.scene, &all.player);
	calcul_fov_eyes(all.scene, &all.player);
	if(init_mlx(&all) == 1)
		return(1);
	if(load_textures(&all, &scene) == 1)
		return(1);
	render(&all);
	mlx_hook(all.display.window, 17, 0, cross_close_event, &all);
	mlx_hook(all.display.window, 2, 1L<<0, click_event, &all);
	mlx_loop(all.display.init);
	free_everything(&all);
	return (0);
}
