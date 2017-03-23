/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:52:24 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/16 14:52:29 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/ft_printf.h"
#include "mlx.h"
#include <errno.h>
#include <math.h>

#define PI 3.1415926
#define COSNS(ang) cos(ang * PI / 180)
#define SINSS(ang) sin(ang * PI / 180)

typedef struct	s_point
{
    int y;
    int x;
    int height;
    int color;
}				t_point;


typedef struct	s_map
{
    t_point map[2000][2000];
    t_point copy[20000][20000];
    int width;
    int height;
    void *mlx;
    void *window;
    int scale;
    double angle_x;
    double angle_y;
    double angle_z;
    int map_max;
}				t_map;


int get_map(char *name, t_map *map);
void reculc_point(t_map *map);
int key_listener(int keycode, void *param);
void draw_map(t_map *map);
void reculc_map(t_map *map, int vector);
void make_copy(t_map *map);
int normal_round(double num);


#endif
