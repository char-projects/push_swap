/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:30:31 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 00:06:44 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Include ft_atof in the libft repo
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Using the Turk algorithm
// Pushes the first two nodes from stack a to stack b without checking anything
// But: There have to be 3 nodes left in stack a
// So if a > 3, push a to b until a = 3, sorting b in descending order
// Now we have a min and max value in stack b
// Look for target nodes next, every a node needs one from b
// A target node is the closest smaller number to the a node
// Then we push that a node on top of its target node in b
// If no closest smaller number is found, the target node is the max value in b
// Cost analysis: Which a node is the cheapest to push to b
// Push cost = (x operations to bring a on top)
//	+ (x operations to bring a->target node on top)
// If multiple nodes have the same cost, go with the first one
// Then push every b node back to a
// Every b node needs a target node in a which is the closest bigger number
// If no closest bigger number is found, the target node is the min value in a
// Median: If target node above, do ra, if below do rra
// Finally, find min, if above median, do ra, if below do rra

# include "libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				nb;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Do not include static functions in the header file

// Main - DONE
int					ft_error_duplicate(t_stack *a, int nb);

// Checks - DONE
bool				ft_is_duplicate(t_stack *stack, long int nb);
bool				ft_is_sorted(t_stack *a);
void				ft_free_errors(t_stack **a);
// static int			ft_wordcount(char const *s, char c);
// static char			*ft_nextword(char *s, char c);

// Node stuff
void				ft_free_stack(t_stack **stack);
void				ft_append_node(t_stack **stack, long int nb);
void				ft_init_a(t_stack **a, char **argv);
void				ft_init_nodes(t_stack *a, t_stack *b);
int					ft_stack_len(t_stack *stack);

// Sorting - DONE
void				ft_sort_three(t_stack **a);
void				ft_index(t_stack *stack);
// static void			ft_push_to_b(t_stack **a, t_stack **b);
// static void			ft_push_to_a(t_stack **a, t_stack **b);
void				ft_sort_stacks(t_stack **a, t_stack **b);

// Swap - DONE
// static void 		ft_swap(t_stack **head);
void				ft_sa(t_stack **a, bool print);
void				ft_sb(t_stack **b, bool print);
void				ft_ss(t_stack **a, t_stack **b, bool print);

// Push - DONE
// static void 		ft_push(t_stack **dst, t_stack **src);
void				ft_pa(t_stack **a, t_stack **b, bool print);
void				ft_pb(t_stack **b, t_stack **a, bool print);

// Rotate - DONE
// static void ft_rotate(t_stack **stack);
void				ft_ra(t_stack **a, bool print);
void				ft_rb(t_stack **b, bool print);
void				ft_rr(t_stack **a, t_stack **b, bool print);
// static void				ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

// Rev rotate - DONE
// static void ft_rev_rotate(t_stack **stack);
void				ft_rra(t_stack **a, bool print);
void				ft_rrb(t_stack **b, bool print);
void				ft_rrr(t_stack **a, t_stack **b, bool print);
// static void ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

// Utils - DONE
int					ft_error(char *argv);
long				ft_atol(const char *str);
t_stack				*ft_find_min(t_stack *stack);
// static void			ft_target_a(t_stack *a, t_stack *b);
// static void			ft_cost_analysis(t_stack *a, t_stack *b);

// Utils 2 - DONE
void				ft_set_cheapest(t_stack *stack);
// static void			ft_min_on_top(t_stack **a);
void				ft_prep_for_push(t_stack **stack, t_stack *top_node,
						char c);

// Utils 3 - DONE
// static void			ft_target_b(t_stack *a, t_stack *b);
void				ft_init_nodes_a(t_stack *a, t_stack *b);
void				ft_init_nodes_b(t_stack *a, t_stack *b);
char				**ft_new_split(char const *s, char c);
t_stack				*ft_find_max(t_stack *stack);

#endif