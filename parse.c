/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omotyliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:10:06 by omotyliu          #+#    #+#             */
/*   Updated: 2017/03/17 14:10:10 by omotyliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int *get_line(char *line, t_map *map)
{
    char **values;
    int *int_line;
    int i;
    int height;

    height = 0;
    i = 0;
    values = ft_strsplit(line, ' ');
    while (values[i])
        i++;
    map->width = i;
    int_line = (int*)malloc(sizeof(int) * map->width);
    i = 0;
    while (values[i])
    {
        int_line[i] = ft_atoi(values[i]);
        height = (int_line[i] > height) ? int_line[i] : height;
        i++;
    }
    map->map_max = height;
    return int_line;
}

static void color(t_map *map)
{
    int  i;
    int j;

    i = 0;
    j = 0;

    while (i < map->height)
    {
        while (j < map->width)
        {
           if(map->map[i][j].height > 10)
               map->map[i][j].color = 0XFF0000;
           else
               map->map[i][j].color = 0XFFFFFF;
            j++;
        }
        j = 0;
        i++;
    }
}

static void get_int(t_list *list, t_map *map)
{
    t_list *temp;
    int *line;
    int i;
    int j;

    i = 0;
    j = 0;
    temp = list;
    while (i < map->height)
    {

        line = get_line(list->content, map);
        while (j < map->width) {
            map->map[i][j].x = i;
            map->map[i][j].y = j;
            map->map[i][j].height = line[j];
            j++;
        }
        list = list->next;
        j = 0;
        i++;
    }
    color(map);
}

int get_map(char *name, t_map *map)
{
    int fd;
    char *line;
    t_list *list;
    int height;

    height = 0;
    list = NULL;
    if ((fd = open(name, O_RDONLY)) > 0)
    {
        ft_printf("parse begin\n");
        while (get_next_line(fd, &line) > 0)
        {
            ft_lstadd_end(&list, ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1));
            printf("line %d\n", height);
            free(line);
            height++;
        }
        ft_printf("parse end \n");
        map->height = height;
        get_int(list, map);
        close(fd);
    }
    else
    {
        printf("%d\n", fd);
        printf("%s\n", strerror(errno));
        ft_printf("error");
    }
    return 0;
}