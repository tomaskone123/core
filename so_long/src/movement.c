/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:51:42 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/04 16:33:38 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	move_player(t_con *prg, int new_x, int new_y)
{
	if ((prg->map.layout[new_x][new_y] != '1')
		&& (prg->map.layout[new_x][new_y] != 'E'))
	{
		if (prg->map.layout[new_x][new_y] != 'C')
			prg->map.collectibles--;
		prg->map.layout[prg->map.px][prg->map.py] = '0';
		prg->map.layout[new_x][new_y] = 'P';
		prg->map.px = new_x;
		prg->map.py = new_y;
		prg->map.mov++;
		ft_printf("x:%d\ny:%d\n", prg->map.px, prg->map.py);
		draw_map(prg);
	}
}

void	draw_layout(t_con *prg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < prg->map.h)
	{
		x = 0;
		while (prg->map.layout[y][x])
		{
			ft_printf("%c", prg->map.layout[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

char	**initialize_textures(char **textures)
{
	textures[0] = "/nfs/homes/tkonecny/core/so_long/textures/wall.xpm42";
	textures[1] = "/nfs/homes/tkonecny/core/so_long/textures/player.xpm42";
	textures[2] = "/nfs/homes/tkonecny/core/so_long/textures/floor.xpm42";
	textures[3] = "/nfs/homes/tkonecny/core/so_long/textures/collectible.xpm42";
	textures[4] = "/nfs/homes/tkonecny/core/so_long/textures/door.xpm42";
	return (textures);
}

