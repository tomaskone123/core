/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:30:30 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/05 15:51:38 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_images(t_con *prg)
{
	char	*textures[6];

	initialize_textures(textures, prg);
	prg->textures.wall_xpm = mlx_load_xpm42(textures[0]);
	prg->textures.player_xpm = mlx_load_xpm42(textures[1]);
	prg->textures.floor_xpm = mlx_load_xpm42(textures[2]);
	prg->textures.collectible_xpm = mlx_load_xpm42(textures[3]);
	prg->textures.door_xpm = mlx_load_xpm42(textures[4]);
	prg->textures.opendoor_xpm = mlx_load_xpm42(textures[5]);
	prg->images.opendoor = mlx_texture_to_image(prg->mlxptr,
			&prg->textures.opendoor_xpm->texture);
	prg->images.wall = mlx_texture_to_image(prg->mlxptr,
			&prg->textures.wall_xpm->texture);
	prg->images.player = mlx_texture_to_image(prg->mlxptr,
			&prg->textures.player_xpm->texture);
	prg->images.floor = mlx_texture_to_image(prg->mlxptr,
			&prg->textures.floor_xpm->texture);
	prg->images.collectible = mlx_texture_to_image(prg->mlxptr,
			&prg->textures.collectible_xpm->texture);
	prg->images.exit = mlx_texture_to_image(prg->mlxptr,
			&prg->textures.door_xpm->texture);
	delete_textures(prg);
}

void	draw_exit(t_con *prg)
{
	if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'E')
		mlx_image_to_window(prg->mlxptr, prg->images.exit, prg->map.y_load
			* TILE_SIZE, prg->map.x_load * TILE_SIZE);
	if (prg->map.layout[prg->map.x_load][prg->map.y_load] == 'X')
		mlx_image_to_window(prg->mlxptr, prg->images.opendoor, prg->map.y_load
			* TILE_SIZE, prg->map.x_load * TILE_SIZE);
}

void	draw_map(t_con *prg)
{
	prg->map.x_load = 0;
	while (prg->map.x_load < prg->map.h)
	{
		prg->map.y_load = 0;
		while (prg->map.layout[prg->map.x_load][prg->map.y_load])
		{
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] != '1')
				mlx_image_to_window(prg->mlxptr, prg->images.floor,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			if (prg->map.layout[prg->map.x_load][prg->map.y_load] == '1')
				mlx_image_to_window(prg->mlxptr, prg->images.wall,
					prg->map.y_load * TILE_SIZE, prg->map.x_load * TILE_SIZE);
			draw_exit(prg);
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
