/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:30:30 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/03 14:33:09 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_con *prg)
{
	xpm_t	*wall_xpm;
	xpm_t	*player_xpm;
	xpm_t	*door_xpm;
	xpm_t	*collectible_xpm;
	xpm_t	*floor_xpm;

	wall_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/wall.xpm42");
	prg->images.wall = mlx_texture_to_image(prg->mlxptr, &wall_xpm->texture);
	mlx_delete_xpm42(wall_xpm);
	player_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/player.xpm42");
	prg->images.player = mlx_texture_to_image(prg->mlxptr,
			&player_xpm->texture);
	mlx_delete_xpm42(player_xpm);
	door_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/door.xpm42");
	prg->images.exit = mlx_texture_to_image(prg->mlxptr, &door_xpm->texture);
	mlx_delete_xpm42(door_xpm);
	collectible_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/collectible.xpm42");
	prg->images.collectible = mlx_texture_to_image(prg->mlxptr,
			&collectible_xpm->texture);
	mlx_delete_xpm42(collectible_xpm);
	floor_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/floor.xpm42");
	prg->images.floor = mlx_texture_to_image(prg->mlxptr, &floor_xpm->texture);
	mlx_delete_xpm42(floor_xpm);
}

void	draw_map(t_con *prg)
{
	prg->map.h /= 90;
	while (prg->map.x_load < prg->map.h)
	{
		prg->map.y_load = 0;
		while (prg->map.layout[prg->map.x_load][prg->map.y_load])
		{
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] != '1'
				|| prg->map.layout[prg->map.x_load][prg->map.y_load] != 'E'
				|| prg->map.layout[prg->map.x_load][prg->map.y_load] != 'C')
				mlx_image_to_window(prg->mlxptr, prg->images.floor,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == '1')
				mlx_image_to_window(prg->mlxptr, prg->images.wall,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			// if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'P')
			// 	mlx_image_to_window(prg->mlxptr, prg->images.player,
			// prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'E')
				mlx_image_to_window(prg->mlxptr, prg->images.exit,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'C')
				mlx_image_to_window(prg->mlxptr, prg->images.collectible,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			prg->map.y_load++;
		}
		prg->map.x_load++;
	}
}
