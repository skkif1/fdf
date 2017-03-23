/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:07:35 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/18 14:07:36 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void make_copy(t_map *map)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(i < map->height)
    {
        while (j < map->width)
        {
            map->copy[i][j] = map->map[i][j];
            j++;
        }
        i++;
        j = 0;
    }
}

int normal_round(double num)
{
    double res;
    double size;

    res = 0;
    size = modf(num, &res);

    if (size > 0.5)
        return (int)res++;
    return (int)(res);
}