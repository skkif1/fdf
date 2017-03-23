/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:40:03 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/17 16:40:04 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void reculc_point(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (i < map->height)
    {
        while (j < map->width)
        {
            map->map[i][j].x += (500 - (map->height / 2) * map->scale);
            map->map[i][j].y += (500 - (map->width / 2) * map->scale);
            j++;
        }
        i++;
        j = 0;
    }
    ft_printf("create point\n");
}

static void rotate_y(t_map *map)
{
    int i;
    int j;
    int x;
    int y;
    int height;

    i = 0;
    j = 0;

    while (i < map->height)
    {
        while (j < map->width)
        {
            height = map->copy[i][j].height * map->scale;
            x = map->copy[i][j].x * map->scale;
            y = map->copy[i][j].y * map->scale;


            y = (y - map->scale * (map->width / 2)) * cos(map->angle_x) +  height * sin(map->angle_x);
            height = -(y) * sin(map->angle_x) + height * cos(map->angle_x);

            x = (x - map->scale * (map->height / 2)) * cos(map->angle_y) +  (height) * sin(map->angle_y);
            height = -(y) * sin(map->angle_y) + (height) * cos(map->angle_y);

            x = (x) * cos(map->angle_z) + y * sin(map->angle_z);
            y = -(x) * sin(map->angle_z) + y * cos(map->angle_z);

            x += (map->height / 2) * map->scale;
            y += (map->width / 2) * map->scale;

            map->map[i][j].height = height;
            map->map[i][j].x = x;
            map->map[i][j].y = y;

            j++;
        }
        i++;
        j = 0;
    }
}

void reculc_map(t_map *map, int vector)
{
    static int reculc;

    vector = 0;
    if (map->height > 100)
        map->scale = 4;
    if (map->height > 200)
        map->scale = 1;

    rotate_y(map);
    reculc_point(map);
    reculc++;
            draw_map(map);
}
