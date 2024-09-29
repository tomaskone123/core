/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:35:36 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/24 17:11:45 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_last(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
		a = a->next;
	return (a);
}

int	stack_len(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

bool	stack_sorted(t_stack *a)
{
	if (!a)
		return (0);
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

t_stack	*find_biggest(t_stack *a)
{
	long	big;
	t_stack	*max_node;

	if (!a)
		return (NULL);
	big = LONG_MIN;
	while (a)
	{
		if (a->nbr > big)
		{
			big = a->nbr;
			max_node = a;
		}
		a = a->next;
	}
	return (max_node);
}

t_stack	*find_smallest(t_stack *a)
{
	long	min;
	t_stack	*min_node;

	if (!a)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (a->nbr < min)
		{
			min = a->nbr;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}
