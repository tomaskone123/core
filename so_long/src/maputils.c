/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:13:20 by tomas             #+#    #+#             */
/*   Updated: 2024/08/20 16:09:56 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	fdfail(void)
{
	ft_printf("Failed to load given file\n");
	return (exit(EXIT_FAILURE));
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
	return (*map1);
}
