/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:51:42 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/05 15:52:48 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_con *prg, int new_x, int new_y)
{
	if ((prg->map.layout[new_x][new_y] != '1')
		&& (prg->map.layout[new_x][new_y] != 'E'))
	{
		if (prg->map.layout[new_x][new_y] == 'C')
			prg->map.coll--;
		prg->map.layout[prg->map.px][prg->map.py] = '0';
		prg->map.layout[new_x][new_y] = 'P';
		prg->map.px = new_x;
		prg->map.py = new_y;
		prg->map.mov++;
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

char	**initialize_textures(char **textures, t_con *prg)
{
	textures[0] = "/nfs/homes/tkonecny/core/so_long/textures/brick.xpm42";
	textures[1] = "/nfs/homes/tkonecny/core/so_long/textures/eud.xpm42";
	textures[2] = "/nfs/homes/tkonecny/core/so_long/textures/grass.xpm42";
	textures[4] = "/nfs/homes/tkonecny/core/so_long/textures/nexdoor.xpm42";
	textures[5] = "/nfs/homes/tkonecny/core/so_long/textures/opendoor.xpm42";
	if (prg->beer == 1)
		textures[3] = "/nfs/homes/tkonecny/core/so_long/textures/beer.xpm42";
	else
		textures[3] = "/nfs/homes/tkonecny/core/so_long/textures/pokemon.xpm42";
	return (textures);
}

void	delete_textures(t_con *prg)
{
	mlx_delete_xpm42(prg->textures.opendoor_xpm);
	mlx_delete_xpm42(prg->textures.player_xpm);
	mlx_delete_xpm42(prg->textures.door_xpm);
	mlx_delete_xpm42(prg->textures.wall_xpm);
	mlx_delete_xpm42(prg->textures.collectible_xpm);
	mlx_delete_xpm42(prg->textures.floor_xpm);
}

int	beer_check(char *beerornobeer)
{
	if (!ft_strncmp(beerornobeer, "beer", ft_strlen(beerornobeer)))
		return (1);
	return (0);
}
