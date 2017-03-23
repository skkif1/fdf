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

int key_listener(int keycode, void *param)
{
    t_map *map;

    map = param;
    if (keycode == 53)
    {
        mlx_destroy_window(map->mlx, map->window);
        exit(0);
    }
        if (keycode == 13 || keycode == 1)
    {
        mlx_clear_window(map->mlx, map->window);
        map->scale = (keycode == 1) ? map->scale - 1 : map->scale + 1;
        ft_printf("resize");
        reculc_map(map, 1);
    }
    if (keycode == 126 || keycode == 125)
    {
        mlx_clear_window(map->mlx, map->window);
        map->angle_x = (keycode == 125) ? map->angle_x - 0.1 : map->angle_x + 0.1;
        reculc_map(map, 2);
    }
    if (keycode == 123 || keycode == 124)
    {
        mlx_clear_window(map->mlx, map->window);
        map->angle_y = (keycode == 123) ? map->angle_y - 0.1 : map->angle_y + 0.1;
        reculc_map(map, 3);
    }
    if (keycode == 12 || keycode == 14)
    {
        mlx_clear_window(map->mlx, map->window);
        map->angle_z = (keycode == 12) ? map->angle_z - 0.1 : map->angle_z + 0.1;
        reculc_map(map, 3);
    }
        return 0;
}


//
// 1234567890    1230
//1            1
//2            2 *
//3 1 2 3      3
//4   * 3      0
//5
//6
//7
//8
//9
//0
//
//height = width / 2 - width / 2  = 3
//
//    5           4
//width = height / 2 - height = 3 = 1