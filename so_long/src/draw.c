/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:30:30 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/04 16:32:41 by tkonecny         ###   ########.fr       */
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
	char	*textures[5];

	initialize_textures(textures);
	wall_xpm = mlx_load_xpm42(textures[0]);
	player_xpm = mlx_load_xpm42(textures[1]);
	floor_xpm = mlx_load_xpm42(textures[2]);
	collectible_xpm = mlx_load_xpm42(textures[3]);
	door_xpm = mlx_load_xpm42(textures[4]);
	prg->images.wall = mlx_texture_to_image(prg->mlxptr, &wall_xpm->texture);
	prg->images.player = mlx_texture_to_image(prg->mlxptr,
			&player_xpm->texture);
	prg->images.floor = mlx_texture_to_image(prg->mlxptr, &floor_xpm->texture);
	prg->images.collectible = mlx_texture_to_image(prg->mlxptr,
			&collectible_xpm->texture);
	prg->images.exit = mlx_texture_to_image(prg->mlxptr, &door_xpm->texture);
	mlx_delete_xpm42(player_xpm);
	mlx_delete_xpm42(door_xpm);
	mlx_delete_xpm42(wall_xpm);
	mlx_delete_xpm42(collectible_xpm);
	mlx_delete_xpm42(floor_xpm);
}

void	draw_map(t_con *prg)
{
	prg->map.x_load = 0;
	while (prg->map.x_load < prg->map.h)
	{
		prg->map.y_load = 0;
		while (prg->map.layout[prg->map.x_load][prg->map.y_load])
		{
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] != '1'
				|| prg->map.layout[prg->map.x_load][prg->map.y_load] != 'P')
				mlx_image_to_window(prg->mlxptr, prg->images.floor,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == '1')
				mlx_image_to_window(prg->mlxptr, prg->images.wall,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'E')
				mlx_image_to_window(prg->mlxptr, prg->images.exit,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'C')
				mlx_image_to_window(prg->mlxptr, prg->images.collectible,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'P')
				mlx_image_to_window(prg->mlxptr, prg->images.player,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			prg->map.y_load++;
		}
		prg->map.x_load++;
	}
}
