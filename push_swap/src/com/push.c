/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:36:30 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/29 14:14:10 by tkonecny         ###   ########.fr       */
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
