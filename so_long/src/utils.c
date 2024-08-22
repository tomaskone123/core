/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:48:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/22 15:53:40 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long_exit(t_con *prg)
{
	mlx_terminate(prg->mlxptr);
	free_layout(prg->map.layout, &prg->map);
	free(prg);
}



int	ber_check(char *argv, t_con *prg)
{
	int	end;

	end = ft_strlen(argv) - 4;
	if (ft_strncmp(argv + end, ".ber", 4) == 0)
	{
		prg->maparg = argv;
		return (0);
	}
	return (1);
}

void	free_layout(char **layout, t_map *map)
{
	int i;

	i = 0;
	while (layout[i])
	{
		free(layout[i]);
		i++;
	}
	free(map);
	free(layout);
}

void	fdfail(void)
{
	ft_printf("Failed to load given file\n");
	return (exit(EXIT_FAILURE));
}

void	argument_check(char *argv[], int argc, t_con *prg)
{
	if (argc > 2)
	{
		ft_printf("Only fist argument is going to be used\n");
	}
	if (argc == 1)
	{
		ft_printf("Not enough arguments\n");
		exit(0);
	}
	if (ber_check(argv[1], prg) != 0)
	{
		ft_printf("File format is not .ber\n");
		exit(0);
	}
}
