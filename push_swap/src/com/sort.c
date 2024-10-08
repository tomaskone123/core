/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:21:03 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/08 16:43:25 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	a_to_b(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(a);
	if (cheapest->above_median && cheapest->targer_node->above_median)
		rotate_both(a, b, cheapest); // TODO
	else if (!(cheapest->above_median) && !(cheapest->targer_node->above_median))
		rev_rotate_both(a, b, cheapest); // TODO
	prep_for_push(a, cheapest, 'a'); // TODO
	prep_for_push(a, cheapest->targer_node, 'b'); // TODO
	pb(b, a);
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
