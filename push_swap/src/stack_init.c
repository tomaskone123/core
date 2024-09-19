/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:52:54 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/19 12:37:55 by tkonecny         ###   ########.fr       */
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

void	ft_stack_init(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_stuff(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_stuff(a);
		if (check_duplicates(*a, (int)n))
			free_stuff(a);
		add_node(a, (int)n);
		i++;
	}
}
