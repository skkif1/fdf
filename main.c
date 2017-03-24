/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:25:59 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/16 14:26:03 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	if (argc == 2)
	{
		map->mlx = mlx_init();
		map->window = mlx_new_window(map->mlx, 1000, 1000, argv[1]);
	}
	else
		cust_exit(0, "wrong number of pararmeters!!!!");
	map->angle_x = 0 * PI / 180;
	map->angle_y = -30 * PI / 180;
	map->angle_z = 0 * PI / 180;
	get_map(argv[1], map);
	make_copy(map);
	if (map->height > 200)
		map->scale = 1;
	else if (map->height > 50)
		map->scale = 2;
	else
		map->scale = 15;
	reculc_map(map);
	mlx_key_hook(map->window, key_listener, map);
	mlx_loop(map->mlx);
	return (0);
}
