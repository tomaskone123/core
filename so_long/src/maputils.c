/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:58:45 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/22 17:08:53 by tkonecny         ###   ########.fr       */
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

int	check_exits(char **layout, t_map map)
{
	int	exit_count;

	exit_count = 0;
	map.j = 0;
	map.i = 0;
	while (layout[map.i])
	{
		map.j = 0;
		while (layout[map.i][map.j])
		{
			if (layout[map.i][map.j] == 'E')
				exit_count++;
			map.j++;
		}
		map.i++;
	}
	if (exit_count != 1)
	{
		ft_printf("Error\nThere is %d exits instead of 1", exit_count);
		return (0);
	}
	return (1);
}

int	check_collectibles(char **layout, t_map map)
{
	int	collectibles;

	collectibles = 0;
	map.j = 0;
	map.i = 0;
	while (layout[map.i])
	{
		map.j = 0;
		while (layout[map.i][map.j])
		{
			if (layout[map.i][map.j] == 'C')
				collectibles++;
			map.j++;
		}
		map.i++;
	}
	if (collectibles < 1)
	{
		ft_printf("Error\nThere are no collectibles");
		return (0);
	}
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
