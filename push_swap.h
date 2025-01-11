/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:30:31 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 21:55:39 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Include ft_atof in the libft repo
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// Algorithm
void				ft_push_chunk_to_b(t_stack *a, t_stack *b, int *chunk);
void				ft_sort_stack_b(t_stack *b, t_stack *a);
void				ft_push_back_to_a(t_stack *a, t_stack *b);

// Checks
int					ft_is_duplicate(t_stack *stack, long int nb);
int					ft_is_sorted(t_stack *a);
// static int		ft_wordcount(char const **s, char c);
// static char		*ft_nextword(char *s, char c);
char				**ft_new_split(char const *s, char c);

// Errors
int					ft_error(char *argv);
int					ft_error_duplicate(t_stack *a, int nb);
void				ft_free_stack(t_stack **stack);
void				ft_free_errors(t_stack **a);
long				ft_atol(const char *str);

// Main
void				ft_init_stack_a(t_stack **a, char **argv);
// static void		ft_append_node(t_stack **stack, int nb);
void				ft_init_stacks(int argc, char **argv, t_stack **a,
						t_stack **b);
void				ft_chunky(t_stack *a, t_stack *b, int *chunks,
						int num_chunks);

// Sort
int					*ft_stack_to_array(t_stack *stack, int stack_len);
int					*ft_create_chunks(t_stack *stack, int num_chunks);
int					ft_is_in_chunk(int value, int *chunk);
void				ft_sort_array(int *array, int size);
int					ft_stack_len(t_stack *stack);

// Swap
// static void 		ft_swap(t_stack **upper);
void				ft_sa(t_stack **a, int print);
void				ft_sb(t_stack **b, int print);
void				ft_ss(t_stack **a, t_stack **b, int print);

// Push
// static void 		ft_push(t_stack **dst, t_stack **src);
void				ft_pa(t_stack **a, t_stack **b, int print);
void				ft_pb(t_stack **b, t_stack **a, int print);

// Rotate
// static void 		ft_rotate(t_stack **stack);
void				ft_ra(t_stack **a, int print);
void				ft_rb(t_stack **b, int print);
void				ft_rr(t_stack **a, t_stack **b, int print);

// Rev rotate
// static void 		ft_rev_rotate(t_stack **stack);
void				ft_rra(t_stack **a, int print);
void				ft_rrb(t_stack **b, int print);
void				ft_rrr(t_stack **a, t_stack **b, int print);

// Utils
t_stack				*ft_find_min(t_stack *stack);
t_stack				*ft_find_max(t_stack *stack);
int					ft_find_position(t_stack *stack, int value);
int					ft_get_target_position(t_stack *stack, int value);
void				ft_move_to_top(t_stack *stack, int position);

#endif