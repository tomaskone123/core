/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:36:30 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/19 21:17:03 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*store;

	if (!src)
		return ;
	store = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	store->prev = NULL;
	if (!*dst)
	{
		*dst = store;
		store->next = NULL;
	}
	else
	{
		store->next = *dst;
		store->next->prev = store;
		*dst = store;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	ft_printf("pb\n");
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->targer_node && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->targer_node && *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
