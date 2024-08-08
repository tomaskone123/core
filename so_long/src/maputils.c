/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maputils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:13:20 by tomas             #+#    #+#             */
/*   Updated: 2024/08/08 13:28:42 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		ber_check(char* argv)
{
	int end;

	end = ft_strlen(argv) - 4;
	return(ft_strncmp(argv + end, ".ber", 4));
}

void	argument_check(char* argv[], int argc)
{
	if (argc > 2)
	{
		ft_printf("only fist argument is going to be used");
	}
	if (argc == 1)
	{
		ft_printf("Not enough arguments!");
		exit(0);
	}
	if (ber_check(argv[1]) != 0)
	{
		ft_printf("File format is not .ber");
		exit(0);
	}
}
