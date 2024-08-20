/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:48:01 by tkonecny          #+#    #+#             */
/*   Updated: 2024/08/20 15:49:14 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
