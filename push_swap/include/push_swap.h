/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkonecny <tkonecny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:22:11 by tkonecny          #+#    #+#             */
/*   Updated: 2024/10/11 19:09:19 by tkonecny         ###   ########.fr       */
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
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*targer_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_values
{
	char			**argv;
}					t_values;

// Handle errors
int					syntax_error(char *str);
void				free_stuff(t_stack **a);
int					check_duplicates(t_stack *a, int n);
void				free_stack(t_stack **a);
void				free_clean(t_stack **a, t_stack **b, t_values *idk);

// Stack Initiation
int					ft_stack_init(t_stack **a, char **argv);

// Nodes Initiation
void				init_a(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *a);
void				current_index(t_stack *a);
t_stack				*get_cheapest(t_stack *a);

// Stack Utils
t_stack				*find_last(t_stack *a);
int					stack_len(t_stack *a);
bool				stack_sorted(t_stack *a);
t_stack				*find_smallest(t_stack *a);
t_stack				*find_biggest(t_stack *a);

// Commands
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **b, t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				rr(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);

// Algorithm
void				sort_three(t_stack **a);

#endif
