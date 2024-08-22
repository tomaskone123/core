/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:58:45 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/22 16:05:05 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char*	load_line(char* line, char* layout, t_map *map1)
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
