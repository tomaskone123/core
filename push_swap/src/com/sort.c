/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:21:03 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/11 19:09:54 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->targer_node && *a != cheapest_node)
		rr(*a);
	current_index(*a);
	current_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->targer_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	a_to_b(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(a);
	if (cheapest->above_median && cheapest->targer_node->above_median)
		rotate_both(a, b, cheapest); // TODO
	else if (!(cheapest->above_median)
		&& !(cheapest->targer_node->above_median))
		rev_rotate_both(a, b, cheapest);          // TODO
	prep_for_push(a, cheapest, 'a');              // TODO
	prep_for_push(a, cheapest->targer_node, 'b'); // TODO
	pb(b, a);
}

static void	b_to_a(t_stack **a, t_stack **b)
{
	prep_to_push(a, (*b)->targer_node, 'a');
	pa(a, b);
}

static void	min_to_top(t_stack **a)
{
	while ((*a)->nbr != find_smallest(*a)->nbr)
	{
		if (find_smallest(*a)->above_median)
			re(a);
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
	while (len_a > 3 && !stack_sorted(*a) && i <= 3)
	{
		pb(b, a);
		i++;
	}
	while (!stack_sorted(*a))
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
	current(*a);
	min_to_top(a);
}
