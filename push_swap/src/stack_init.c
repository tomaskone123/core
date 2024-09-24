/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:52:54 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/24 17:02:12 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	while (*s == '\t' || *s == ' ' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	add_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last = find_last(*a);
		last->next = node;
		node->prev = last;
	}
}

int	ft_stack_init(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			return (0);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		if (check_duplicates(*a, (int)n))
			return (0);
		add_node(a, (int)n);
		i++;
	}
	return (1);
}

t_stack	*biggest(t_stack *a)
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

t_stack	*smallest(t_stack *a)
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
