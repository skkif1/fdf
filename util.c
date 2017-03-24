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

void	make_copy(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->height)
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

void	cust_exit(t_map *map, const char *str)
{
	if (map != 0)
		mlx_destroy_window(map->mlx, map->window);
	ft_printf("\n%s\n", str);
	exit(0);
}

void	free_list(t_list *lst)
{
	t_list *temp;

	if (lst != NULL)
	{
		while (lst != NULL)
		{
			temp = lst;
			free(lst->content);
			free(lst);
			lst = temp->next;
		}
	}
}

void	change_color(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (j < map->width)
		{
			map->map[i][j].color += 10;
			j++;
		}
		i++;
		j = 0;
	}
}
