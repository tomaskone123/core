/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:22:47 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/23 13:30:04 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_stack **a)
{
	if (!*a || !(*a)->next)
		return;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next-prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
}

void	sa(t_stack **a, bool p)
{
	swap(a);
	if (!p)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool p)
{
	swap(b);
	if (!p)
		ft_printf("sb\n");
}

void	ss(t_stack **b, t_stack **a, bool p)
{
	swap(a);
	swap(b);
	if (!p)
		ft_printf("ss\n");
}
