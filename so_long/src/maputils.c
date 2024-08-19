/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:13:20 by tomas             #+#    #+#             */
/*   Updated: 2024/08/19 16:08:05 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int		ber_check(char* argv, t_con* prg)
{
	int end;

	end = ft_strlen(argv) - 4;
	if (ft_strncmp(argv + end, ".ber", 4) == 0)
	{
		prg->maparg = argv;
		return(0);
	}
	return (1);
}


t_map get_map_values(char	*map_file)
{
	t_map		map1;
	int			fd;
	char		*layout;
	char		*line;

	map1.h = 0;
	map1.w = 0;
	layout = NULL;
	map1.mov = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("failed to load file\n");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		layout = ft_strjoin_gnl(layout, line);
		free(line);
		line = get_next_line(fd);
		map1.h++;
	}
	close(fd);
	map1.layout = ft_split(layout, '\n');
	map1.w = ft_strlen(map1.layout[0]);
	free(layout);
	free(line);
	return (map1);
}

