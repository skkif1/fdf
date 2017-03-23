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



int main (int argc, char **argv)
{
    t_map *map;
    argc = 0;

    map = (t_map*)malloc(sizeof(t_map));
    map->mlx = mlx_init();
    map->window = mlx_new_window(map->mlx, 1000, 1000, "lolll");
    map->scale = 15;
    map->angle_x = 0 * PI / 180;
    map->angle_y = 0 * PI / 180;
    map->angle_z = 0 * PI / 180;
    get_map(argv[1], map);

    make_copy(map);
    reculc_map(map, 1);
    mlx_key_hook(map->window, key_listener, map);
    mlx_loop(map->mlx);
}
