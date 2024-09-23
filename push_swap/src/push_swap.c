/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:21:40 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/23 13:31:45 by tkonecny         ###   ########.fr       */
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
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		// else if (stack_len(a) == 3)
		// 	sort_tree(&a);
		// else
		// 	sort_stack(&a, &b);
	}
	free(idk);
}
