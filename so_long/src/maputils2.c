/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:47:00 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/25 13:11:54 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_reachability(char **layout, t_map *map)
{
	flood_fill(layout, map->px, map->py, map);
	if (map->collectibles > 0 || map->exits > 0)
	{
		ft_printf("Error\nThe collectibles or exit are not reachable");
		return (0);
	}
	return (1);
}

int	check_size(t_map *map)
{
	if (map->w > 22 || map->h > 12)
	{
		ft_printf("Error\nThe map is too big");
		return (0);
	}
	return (1);
}
