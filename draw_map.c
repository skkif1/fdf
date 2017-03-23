/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:49:43 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/18 13:49:44 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int put_point(t_point point, int color, t_map *map)
{
    mlx_pixel_put(map->mlx, map->window, point.y, point.x, color);
    return 1;
}

static void draw_line(t_point point, t_point point2, t_map *map)
{
    int deltax = abs(point.x - point2.x);
    int deltay = abs(point.y - point2.y);
    int signX = point.x < point2.x ? 1 : -1;
    int signY = point.y < point2.y ? 1 : -1;
    int error = deltax - deltay;

    while(point.x != point2.x || point.y != point2.y)
    {
        put_point(point, point.color, map);
        int error2 = error * 2;
        if(error2 > -deltay)
        {
            error -= deltay;
            point.x += signX;
        }
        if(error2 < deltax)
        {
            error += deltax;
            point.y += signY;
        }
    }
}

void draw_map(t_map *map)
{

    int i;
    int j;
    i = 0;
    j = 0;

    while (i < map->height)
    {
        while(j < map->width)
        {
            if (j < map->width - 1)
                draw_line(map->map[i][j], map->map[i][j + 1], map);
            if (i > 0)
                draw_line(map->map[i][j], map->map[i - 1][j], map);
            j++;
        }
        i++;
        j = 0;
    }
}