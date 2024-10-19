/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:21:03 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/19 21:16:30 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->targer_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->targer_node->above_median))
		rev_rotate_both(a, b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->targer_node, 'b');
	pb(b, a);
}

static void	b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->targer_node, 'a');
	pa(a, b);
}

static void	min_to_top(t_stack **a)
{
	while ((*a)->nbr != find_smallest(*a)->nbr)
	{
		if (find_smallest(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len_a;
	int	i;

	i = 0;
	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_a(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(*a, *b);
		b_to_a(a, b);
	}
	current_index(*a);
	min_to_top(a);
}
