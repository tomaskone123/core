/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:30:30 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/02 16:37:47 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void load_images(t_con *prg) {
//     // Load the player sprite
//     xpm_t *player_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/AnyConv.com__pixil-frame-0.xpm42");
//     if (!player_xpm) {
//         ft_printf("Failed to load player image\n");
//         mlx_terminate(prg->mlxptr);
//         exit(EXIT_FAILURE);
//     }

//     prg->images.player = mlx_texture_to_image(prg->mlxptr,
		// &player_xpm->texture);
//     mlx_delete_xpm42(player_xpm);

//     if (!prg->images.player) {
//         ft_printf("Failed to create player image\n");
//         mlx_terminate(prg->mlxptr);
//         exit(EXIT_FAILURE);
//     }

//     // Draw the image to the window at coordinates (x = 0, y = 0)
//     mlx_image_to_window(prg->mlxptr, prg->images.player, 0, 0);
// }
void	load_images(t_con *prg)
{
	xpm_t	*wall_xpm;

	// Load the wall image (90x90px white square)
	wall_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/AnyConv.com__pixil-frame-0.xpm42");
	if (!wall_xpm)
	{
		ft_printf("Failed to load wall image\n");
		mlx_terminate(prg->mlxptr);
		exit(EXIT_FAILURE);
	}
	prg->images.wall = mlx_texture_to_image(prg->mlxptr, &wall_xpm->texture);
	mlx_delete_xpm42(wall_xpm);
	if (!prg->images.wall)
	{
		ft_printf("Failed to create wall image\n");
		mlx_terminate(prg->mlxptr);
		exit(EXIT_FAILURE);
	}
	// Load other images (player, empty space, etc.) as needed
	// Example for player:
	xpm_t *player_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/player.xpm42");
	if (!player_xpm) {
	    ft_printf("Failed to load player image\n");
	    mlx_terminate(prg->mlxptr);
	    exit(EXIT_FAILURE);
	}
	prg->images.player = mlx_texture_to_image(prg->mlxptr,
			&player_xpm->texture);
	mlx_delete_xpm42(player_xpm);
	// Additional images like collectible (C), exit (E),
		// empty space (0) can be loaded similarly
	xpm_t *door_xpm = mlx_load_xpm42("/nfs/homes/tkonecny/core/so_long/textures/door.xpm42");
	if (!door_xpm) {
	    ft_printf("Failed to load player image\n");
	    mlx_terminate(prg->mlxptr);
	    exit(EXIT_FAILURE);
	}
	prg->images.exit = mlx_texture_to_image(prg->mlxptr,
			&door_xpm->texture);
	mlx_delete_xpm42(door_xpm);
}

void	draw_map(t_con *prg)
{
	int	i;
	int	j;

	int tile_size = 90; // Assuming each tile (image) is 90x90 pixels
	j = 0;
	i = 0;
	prg->map.h /= 90;
	while (i < prg->map.h)
	{
		j = 0;
		while (prg->map.layout[i][j])
		{
			// Ensure we're within bounds before accessing layout[i][j]
			if (i >= prg->map.h || j >= prg->map.w || !prg->map.layout[i])
			{
				exit(EXIT_FAILURE);
			}
			if (prg->map.layout[i][j] == '1')
			{
				// Place wall image
				mlx_image_to_window(prg->mlxptr, prg->images.wall, j
					* tile_size, i * tile_size);
			}
			if (prg->map.layout[i][j] == 'P')
				mlx_image_to_window(prg->mlxptr, prg->images.player, j * tile_size, i * tile_size);
			if (prg->map.layout[i][j] == 'E')
				mlx_image_to_window(prg->mlxptr, prg->images.exit, j * tile_size, i * tile_size);

			ft_printf("%c", prg->map.layout[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
