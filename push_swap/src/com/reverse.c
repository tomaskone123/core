/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:49:40 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/24 15:00:55 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse(t_stack **a)
{
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	last = find_last(a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
}

void	rra(t_stack **a, bool print)
{
	reverse(a);
	if (!print)
		ft_printf("ra\n");
}


void	rrb(t_stack **b, bool print)
{
	reverse(b);
	if (!print)
		ft_printf("rb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse(a);
	reverse(b);
	if (!print)
		ft_printf("rr\n");
}
