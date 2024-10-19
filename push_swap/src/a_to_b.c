/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:45:08 by tomas             #+#    #+#             */
/*   Updated: 2024/10/19 19:03:16 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	current_index(t_stack *a)
{
	int	i;
	int	median;

	i = 0;
	if (!a)
		return ;
	median = stack_len(a) / 2;
	while (a)
	{
		a->index = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		++i;
	}
}

static void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->targer_node = find_biggest(b);
		else
			a->targer_node = target;
		a = a->next;
	}
}

static void	cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - (a->index);
		if (a->targer_node->above_median)
			a->cost += a->targer_node->index;
		else
			a->cost += len_b - (a->targer_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack *a)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!a)
		return ;
	cheapest_value = LONG_MAX;
	while (a)
	{
		if (a->cost < cheapest_value)
		{
			cheapest_value = a->cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

void	init_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	cost_a(a, b);
	set_cheapest(a);
}
