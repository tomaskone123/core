/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:21:40 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/11 17:21:05 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	t_values	*idk;

	a = NULL;
	b = NULL;
	idk = ft_calloc(1, sizeof(t_values));
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		idk->argv = ft_split(argv[1], ' ');
	else
		idk->argv = argv + 1;
	ft_stack_init(&a, idk->argv);
	free(idk);
}
