/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:15:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/12 13:14:20 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	keypresshandle(mlx_key_data_t keydata, void *param)
{
	t_con	*prg;

	prg = (t_con *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(prg->mlxptr);
	if (keydata.key == MLX_KEY_W)
		(*prg).map.mov++;
	if (keydata.key == MLX_KEY_A)
		(*prg).map.mov++;
	if (keydata.key == MLX_KEY_S)
		(*prg).map.mov++;
	if (keydata.key == MLX_KEY_D)
		(*prg).map.mov++;
	ft_printf("number of moves:%d\n", (*prg).map.mov);
}

int32_t	main(int argc, char *argv[])
{
	t_con	prg;

	prg.mlxptr = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!prg.mlxptr)
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	argument_check(argv, argc, &prg);
	// prg.map = get_map_values(prg.maparg);
	// ft_printf("%s", prg.map.h);
	mlx_key_hook(prg.mlxptr, keypresshandle, prg.mlxptr);
	mlx_loop(prg.mlxptr);
	mlx_terminate(prg.mlxptr);
	return (EXIT_SUCCESS);
}
