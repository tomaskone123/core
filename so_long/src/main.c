/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:15:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/03 17:23:14 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int	initialize_keys(int *keys, mlx_key_data_t keydata)
// {
// 	int	i;

// 	keys[0] = MLX_KEY_W;
// 	keys[1] = MLX_KEY_A;
// 	keys[2] = MLX_KEY_S;
// 	keys[3] = MLX_KEY_D;
// 	keys[4] = 0;
// 	i = 0;
// 	while (keys[i] != 0)
// 	{
// 		if (keys[i] == (int)keydata.key)
// 			return (keys[i]);
// 		i++;
// 	}
// 	return (0);
// }

void	keypresshandle(mlx_key_data_t keydata, void *param)
{
	t_con	*prg;

	prg = (t_con *)param;
	if (keydata.action == MLX_PRESS)
	{
		// Move player based on key press
		if (keydata.key == MLX_KEY_W) {  // Move up
			move_player(prg, prg->map.px, prg->map.py - 10);
		} else if (keydata.key == MLX_KEY_S) {  // Move down
			move_player(prg, prg->map.px, prg->map.py + 10);
		} else if (keydata.key == MLX_KEY_A) {  // Move left
			move_player(prg, prg->map.px - 10, prg->map.py);
		} else if (keydata.key == MLX_KEY_D) {  // Move right
			move_player(prg, prg->map.px + 10, prg->map.py);
		}
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("Exiting program\n");
		mlx_close_window(prg->mlxptr);
		free(prg->mlxptr);
		free(prg);
		exit(0);
	}
}

int32_t	main(int argc, char *argv[])
{
	t_con	*prg;

	prg = (t_con *)ft_calloc(1, sizeof(t_con));
	if (!prg)
		return (EXIT_FAILURE);
	argument_check(argv, argc, prg);
	prg->map = get_map_values(prg->maparg);
	prg->mlxptr = mlx_init(prg->map.w, prg->map.h, "So_Long", false);
	if (!prg->mlxptr)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	load_images(prg);
	draw_map(prg);
	mlx_key_hook(prg->mlxptr, keypresshandle, prg);
	mlx_loop(prg->mlxptr);
	so_long_exit(prg);
	return (EXIT_SUCCESS);
}
