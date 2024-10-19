/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:21:40 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/19 21:18:22 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void	printstack(t_stack *a)
// {
// 	while (a)
// 	{
// 		ft_printf("%d\n", (int)a->nbr);
// 		a = a->next;
// 	}
// }

int	main(int argc, char *argv[])
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
	if (!ft_stack_init(&a, idk->argv))
		free_stuff(&a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_clean(&a, &b, idk);
}
