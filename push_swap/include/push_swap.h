/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:22:11 by tkonecny          #+#    #+#             */
/*   Updated: 2024/09/24 14:48:09 by tkonecny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_values
{
	char**			argv;
}					t_values;

// Handle errors
int		syntax_error(char* str);
void	free_stuff(t_stack **a);
int		check_duplicates(t_stack *a, int n);
void	free_stack(t_stack **a);
void	free_clean(t_stack **a, t_stack **b, t_values *idk);




// Stack Initiation
int		ft_stack_init(t_stack **a, char **argv);


// Nodes Initiation

// Stack Utils
t_stack	*find_last(t_stack	*a);
int		stack_len(t_stack* a);
bool	stack_sorted(t_stack* a);


// Commands
void	sa(t_stack **a, bool p);
void	sb(t_stack **b, bool p);
void	ss(t_stack **b, t_stack **a, bool p);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);


// Algorithm


#endif
