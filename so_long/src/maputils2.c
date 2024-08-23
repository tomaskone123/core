/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:47:00 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/23 14:53:07 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_reachability(char** layout, t_map *map)
{
	flood_fill(layout, map->px, map->py, map);
	free_layout(layout);
	if (map->collectibles > 0 || map->exits > 0)
	{
		ft_printf("Error\nThe collectibles or exit are not reachable");
		return (0);
	}
	return (1);
}
