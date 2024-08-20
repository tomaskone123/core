/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:13:20 by tomas             #+#    #+#             */
/*   Updated: 2024/08/20 17:39:06 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_player(char** layout, t_map map)
{
	int	player_count;

	player_count = 0;
	while (layout[map.i])
	{
		map.j = 0;
		while (layout[map.i][map.j])
		{
			if (layout[map.i][map.j] == 'P')
				player_count++;
			map.j++;
		}
		map.i++;
	}
	if (player_count != 1)
	{
		ft_printf("Not right emount of Players");
		return (0);
	}
	map.j = 0;
	map.i = 0;
	return (1);
}

int	is_rectangle(char** layout, t_map map)
{
	map.j = ft_strlen(layout[0]);
	map.i = 1;
	while(layout[map.i])
	{
		if ((int)ft_strlen(layout[map.i]) != map.j)
		{
			ft_printf("The map is not a rectangle\n");
			return (0);
		}
		map.i++;
	}
	return (1);
}

int	check_map_values(char** layout, t_map map)
{
	if (!check_player(layout, map))
		return (0);
	if (!is_rectangle(layout, map))
		return (0);
	return (1);
}

t_map	get_map_values(char *map_file)
{
	t_map	*map1;
	int		fd;
	char	*layout;
	char	*line;

	layout = NULL;
	map1 = (t_map *)ft_calloc(1, sizeof(t_map));
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		fdfail();
	line = get_next_line(fd);
	while (line)
	{
		layout = ft_strjoin_gnl(layout, line);
		free(line);
		line = get_next_line(fd);
		map1->h++;
	}
	close(fd);
	map1->layout = ft_split(layout, '\n');
	map1->w = ft_strlen(map1->layout[0]);
	free(layout);
	if (!check_map_values(map1->layout, *map1))
	{
		free(map1);
		exit(EXIT_FAILURE);
	}
	ft_printf("the map is ok sofar\n");
	return (*map1);
}
