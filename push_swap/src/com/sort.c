/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomas <tomas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 14:21:03 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/08 16:37:43 by tomas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	a_to_b(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);

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
