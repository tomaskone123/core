/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:15:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/19 16:40:56 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int initialize_keys(int *keys, mlx_key_data_t keydata)
{
	int i;

	keys[0] = MLX_KEY_W;
	keys[1] = MLX_KEY_A;
	keys[2] = MLX_KEY_S;
	keys[3] = MLX_KEY_D;
	keys[4] = 0;
	i = 0;
	while (keys[i] != 0)
	{
		if (keys[i] == (int)keydata.key)
			return (1);
		i++;
	}
	return (0);
}

void keypresshandle(mlx_key_data_t keydata, void *param)
{
	t_con *prg;
	int keys[5];

	initialize_keys(keys, keydata);
	prg = (t_con *)param;
	if (((keydata.key == MLX_KEY_ESCAPE) || keydata.key == MLX_KEY_Q) && keydata.action == MLX_PRESS)
	{
		ft_printf("Exiting program\n");
		mlx_close_window(prg->mlxptr);
		free(prg->mlxptr);
		exit(0);
	}
	if (initialize_keys(keys, keydata) && keydata.action == MLX_RELEASE)
	{
		(*prg).map.mov++;
		ft_printf("Number of moves: %d\n", (*prg).map.mov);
	}
}

int32_t main(int argc, char *argv[])
{
	t_con *prg;

	prg = (t_con*)ft_calloc(1, sizeof(t_con));
	prg->mlxptr = mlx_init(WIDTH, HEIGHT, "So_Long", false);
	if (!prg->mlxptr)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	argument_check(argv, argc, prg);
	prg->map = get_map_values(prg->maparg);
	ft_printf("map width: %d\nmap height: %d\n", prg->map.w, prg->map.h);
	mlx_key_hook(prg->mlxptr, keypresshandle, prg);
	mlx_loop(prg->mlxptr);
	mlx_terminate(prg->mlxptr);
	return (EXIT_SUCCESS);
}
