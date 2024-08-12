/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:13:20 by tomas             #+#    #+#             */
/*   Updated: 2024/08/12 19:28:00 by tomas            ###   ########.fr       */
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

	// ft_printf("%s", map_file);
	layout = "";
	fd = open(map_file, O_RDONLY);
	// ft_printf("%d", fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		layout = ft_strjoin_gnl(layout, line);
		free(line);
		line = get_next_line(fd);
		map1.h++;
	}
	map1.layout = ft_split(layout, '\n');
	// ft_printf("%s\n", map1.layout[1]);
	free(layout);
	free(line);
	return (map1);
}
