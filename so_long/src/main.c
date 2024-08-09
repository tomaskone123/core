/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:15:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/09 10:44:02 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	keypresshandle(void* param)
{
	t_con*	prg;

	prg = (t_con*)param;
	if (mlx_is_key_down(prg->mlxptr, MLX_KEY_ESCAPE))
		mlx_close_window(prg->mlxptr);
	if (mlx_is_key_down(prg->mlxptr, MLX_KEY_W))
		(*prg).map.mov++;
	ft_printf("number of moves:%d\n", (*prg).map.mov);

}

int32_t main(int argc, char *argv[])
{
	t_con	prg;

	if (!(prg.mlxptr = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	argument_check(argv, argc, &prg);
	// prg.map = get_map_values(prg.maparg);
	// ft_printf("%s", prg.map.h);
	// mlx_loop_hook(prg.mlxptr, keypresshandle, prg.mlxptr);
	mlx_loop(prg.mlxptr);
	mlx_terminate(prg.mlxptr);
	return (EXIT_SUCCESS);
}
