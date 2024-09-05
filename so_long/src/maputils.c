/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:58:45 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/05 16:24:28 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*load_line(char *line, char *layout, t_map *map1)
{
	while (line)
	{
		layout = ft_strjoin_gnl(layout, line);
		free(line);
		line = get_next_line(map1->fd);
		map1->h++;
	}
	return (layout);
}

int	check_exits(char **layout, t_map *map)
{
	map->j = 0;
	map->i = 0;
	while (layout[map->i])
	{
		map->j = 0;
		while (layout[map->i][map->j])
		{
			if (layout[map->i][map->j] == 'E')
			{
				map->ex = map->i;
				map->ey = map->j;
				map->exits++;
			}
			map->j++;
		}
		map->i++;
	}
	if (map->exits != 1)
	{
		ft_printf("Error\nThere is %d exits instead of 1", map->exits);
		return (0);
	}
	return (1);
}

int	check_collectibles(char **layout, t_map *map)
{
	map->j = 0;
	map->i = 0;
	while (layout[map->i])
	{
		map->j = 0;
		while (layout[map->i][map->j])
		{
			if (layout[map->i][map->j] == 'C')
				map->collectibles++;
			map->j++;
		}
		map->i++;
	}
	if (map->collectibles < 1)
	{
		ft_printf("Error\nThere are no collectibles");
		return (0);
	}
	map->coll = map->collectibles;
	return (1);
}

int	check_borders(char **layout, t_map map)
{
	map.i = 0;
	while (map.i < map.w)
	{
		if (layout[0][map.i] != '1' || layout[map.h - 1][map.i] != '1')
		{
			ft_printf("Error\nThe map borders are not valid");
			return (0);
		}
		map.i++;
	}
	map.i = 0;
	while (map.i < map.h)
	{
		if (layout[map.i][0] != '1' || layout[map.i][map.w - 1] != '1')
		{
			ft_printf("Error\nThe map borders are not valid");
			return (0);
		}
		map.i++;
	}
	return (1);
}

void	flood_fill(char **layout, int x, int y, t_map *map)
{
	if (x < 0 || x >= map->h || y < 0 || y >= map->w || layout[x][y] == '1'
		|| layout[x][y] == 'V')
		return ;
	if (layout[x][y] == 'C')
		map->collectibles--;
	if (layout[x][y] == 'E')
		map->exits--;
	if (layout[x][y] == 'E')
	{
		layout[x][y] = '1';
		return ;
	}
	layout[x][y] = 'V';
	flood_fill(layout, x + 1, y, map);
	flood_fill(layout, x - 1, y, map);
	flood_fill(layout, x, y + 1, map);
	flood_fill(layout, x, y - 1, map);
}
