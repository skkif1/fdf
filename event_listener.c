/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:18:42 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/18 13:18:45 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_listener(int keycode, void *param)
{
	t_map *map;

	map = param;
	if (keycode == 53)
		cust_exit(map, ft_strnew(1));
	mlx_clear_window(map->mlx, map->window);
	if (keycode == 13 || keycode == 1)
		map->scale = (keycode == 1) ? map->scale - 1 : map->scale + 1;
	if (keycode == 123 || keycode == 124)
		map->angle_x = (keycode == 123) ? map->angle_x - 0.1 :
	map->angle_x + 0.1;
	if (keycode == 126 || keycode == 125)
		map->angle_y = (keycode == 126) ? map->angle_y - 0.1 :
	map->angle_y + 0.1;
	if (keycode == 12 || keycode == 14)
		map->angle_z = (keycode == 12) ? map->angle_z - 0.1 :
	map->angle_z + 0.1;
	if (keycode == 18)
		change_color(map);
	reculc_map(map);
	return (1);
}
