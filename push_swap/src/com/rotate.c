/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:49:40 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/29 14:13:37 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_stack **a)
{
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	last = find_last(*a);
	last->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
