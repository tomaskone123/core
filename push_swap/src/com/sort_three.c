/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:09:27 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/29 14:15:12 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a);
	else if (biggest == (*a)->next)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}
