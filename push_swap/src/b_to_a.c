/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:12:55 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/13 15:03:03 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_index;

	while (b)
	{
		current_a = a;
		best_index = LONG_MAX;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_index)
			{
				best_index = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			b->targer_node = find_smallest(a);
		else
			b->targer_node = target;
		b = b->next;
	}
}

void	init_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_b(a, b);
}
