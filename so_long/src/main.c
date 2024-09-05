/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:15:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/05 15:52:42 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	next_frame(void *param)
{
	t_con	*prg;

	prg = (t_con *)param;
	if (prg->map.coll == 0)
	{
		prg->map.layout[prg->map.ex][prg->map.ey] = 'X';
	}
	if (prg->map.px == prg->map.ex && prg->map.py == prg->map.ey)
	{
		ft_printf("You Win !!!!!\n");
		mlx_close_window(prg->mlxptr);
		free(prg->mlxptr);
		free(prg);
		exit(0);
	}
}

void	keypresshandle(mlx_key_data_t keydata, void *param)
{
	t_con	*prg;

	prg = (t_con *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			move_player(prg, prg->map.px - 1, prg->map.py);
		if (keydata.key == MLX_KEY_A)
			move_player(prg, prg->map.px, prg->map.py - 1);
		if (keydata.key == MLX_KEY_S)
			move_player(prg, prg->map.px + 1, prg->map.py);
		if (keydata.key == MLX_KEY_D)
			move_player(prg, prg->map.px, prg->map.py + 1);
		ft_printf("Number of moves: %d\n", prg->map.mov);
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
	prg->mlxptr = mlx_init(prg->map.w * 90, prg->map.h * 90, "So_Long", false);
	if (!prg->mlxptr)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	load_images(prg);
	draw_map(prg);
	mlx_loop_hook(prg->mlxptr, next_frame, prg);
	mlx_key_hook(prg->mlxptr, keypresshandle, prg);
	mlx_loop(prg->mlxptr);
	so_long_exit(prg);
	return (EXIT_SUCCESS);
}
