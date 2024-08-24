/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:13:20 by tomas             #+#    #+#             */
/*   Updated: 2024/08/24 20:34:07 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_player(char **layout, t_map *map)
{
	map->j = 0;
	map->i = 0;
	while (layout[map->i])
	{
		map->j = 0;
		while (layout[map->i][map->j])
		{
			if (layout[map->i][map->j] == 'P')
			{
				map->px = map->i;
				map->py = map->j;
				map->player_count++;
			}
			map->j++;
		}
		map->i++;
	}
	if (map->player_count != 1)
	{
		ft_printf("Error\nThere is %d Players instead of 1", map->player_count);
		return (0);
	}
	return (1);
}

int	is_valid_character(char **layout, t_map map)
{
	char	*valid_chars;

	valid_chars = "10CPE";
	map.i = 0;
	map.j = 0;
	while (map.i < map.h)
	{
		map.j = 0;
		while (map.j < map.w)
		{
			if (layout[map.i] == NULL)
			{
				ft_printf("Error\nThere is an empty line in map");
				return (0);
			}
			if (!ft_strchr(valid_chars, layout[map.i][map.j]))
			{
				ft_printf("Error\nInvalid character in map file");
				return (0);
			}
			map.j++;
		}
		map.i++;
	}
	return (1);
}

int	is_rectangle(char **layout, t_map map)
{
	map.j = ft_strlen(layout[0]);
	map.i = 1;
	while (layout[map.i])
	{
		if (map.h == map.w)
		{
			ft_printf("Error\nThe map is not rectangle");
			return (0);
		}
		if ((int)ft_strlen(layout[map.i]) != map.j)
		{
			ft_printf("Error\nThe map has wrong dimensions\n");
			return (0);
		}
		map.i++;
	}
	return (1);
}

int	check_map_values(char **layout, t_map *map)
{
	if (!check_size(map))
		return (0);
	if (!is_rectangle(layout, *map))
		return (0);
	if (!is_valid_character(layout, *map))
		return (0);
	if (!check_borders(layout, *map))
		return (0);
	if (!check_player(layout, map))
		return (0);
	if (!check_exits(layout, map))
		return (0);
	if (!check_collectibles(layout, map))
		return (0);
	if (!check_reachability(map->testlayout, map))
		return (0);
	return (1);
}

t_map	get_map_values(char *map_file)
{
	t_map	*map1;
	char	*layout;
	char	*line;
	t_map	result;

	layout = NULL;
	map1 = (t_map *)ft_calloc(1, sizeof(t_map));
	map1->fd = open(map_file, O_RDONLY);
	if (map1->fd == -1)
		fdfail();
	line = get_next_line(map1->fd);
	layout = load_line(line, layout, map1);
	close(map1->fd);
	map1->layout = ft_split(layout, '\n');
	map1->testlayout = ft_split(layout, '\n');
	map1->w = ft_strlen(map1->layout[0]);
	free(layout);
	if (!check_map_values(map1->layout, map1))
	{
		free_layout(map1->testlayout);
		free_layout(map1->layout);
		free(map1);
		exit(EXIT_FAILURE);
	}
	result = *map1;
	free(map1);
	return (result);
}
