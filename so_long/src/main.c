/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:15:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/14 13:08:14 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	initialize_keys(int *keys, mlx_key_data_t keydata)
{
	int	i;

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

void	keypresshandle(mlx_key_data_t keydata, void *param)
{
	t_con	*prg;
	int		keys[5];

	// initialize_keys(keys, keydata);
	prg = (t_con *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(prg->mlxptr);
		free(prg->mlxptr);
		exit(0);
	}
	if (initialize_keys(keys, keydata) && keydata.action == MLX_RELEASE)
	{
		(*prg).map.mov++;
		ft_printf("number of moves: %d\n", (*prg).map.mov);
	}
}

int32_t	main(int argc, char *argv[])
{
	t_con	prg;

	prg.mlxptr = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!prg.mlxptr)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	argument_check(argv, argc, &prg);
	prg.map = get_map_values(prg.maparg);
	ft_printf("%d", prg.map.h);
	mlx_key_hook(prg.mlxptr, keypresshandle, prg.mlxptr);
	mlx_loop(prg.mlxptr);
	mlx_terminate(prg.mlxptr);
	return (EXIT_SUCCESS);
}
