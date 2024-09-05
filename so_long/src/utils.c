/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:48:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/05 15:52:29 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	so_long_exit(t_con *prg)
{
	mlx_terminate(prg->mlxptr);
	free_layout(prg->map.layout);
	free_layout(prg->map.testlayout);
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

void	free_layout(char **layout)
{
	int	i;

	i = 0;
	while (layout[i])
	{
		free(layout[i]);
		i++;
	}
	free(layout);
}

void	fdfail(void)
{
	ft_printf("Error\nFailed to load given file\n");
	return (exit(EXIT_FAILURE));
}

void	argument_check(char *argv[], int argc, t_con *prg)
{
	if (argc == 3)
		prg->beer = beer_check(argv[2]);
	if (argc > 2)
	{
		ft_printf("Only fist argument is going to be used\n");
	}
	if (argc == 1)
	{
		ft_printf("Error\nNot enough arguments\n");
		exit(0);
	}
	if (ber_check(argv[1], prg) != 0)
	{
		ft_printf("Error\nFile format is not .ber\n");
		exit(0);
	}
}
