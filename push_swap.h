/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:30:31 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/20 20:42:02 by cschnath         ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// Do not include static functions in the header file

// Algorithm
void	ft_print_stack(t_stack *stack); // Remove later
int					**ft_rev_chunks(int **chunks, int num);
t_stack				*ft_arr_to_chunk(t_stack *a, t_stack *b, int *arr, int num,
						int len);
void				ft_push_chunk_to_b(t_stack **a, t_stack **b, int *chunk,
						int size);
int					*ft_stack_to_array(t_stack *stack, int stack_len);

// Checks
int					ft_is_sorted(t_stack *stack);
int					ft_is_duplicate(t_stack *stack);
int					ft_wordcount(char const *s, char c);
// static char		*ft_nextword(char **s, char c);
char				**ft_new_split(char const *s, char c);

// Errors
int					ft_error(char *argv);
int					ft_duplicate(char **argv, int size);
void				ft_free_stack(t_stack **stack);
void				ft_free_errors(t_stack **a);

// Main
int					main(int argc, char **argv);
int					ft_calculate_chunks(int stack_len);
void				ft_append_node(t_stack **stack, long nb);
void				ft_validate(int argc, char **argv, t_stack **a, int i);
void				ft_init_stacks(int argc, char **argv, t_stack **a,
						t_stack **b, int i);

// Sort
int					ft_chunk_size(int i, int stack_len, int num_chunks);
int					*ft_create_chunks(int *array, int size, int i);
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
void				ft_push_smallest_to_b(t_stack **stack_a, t_stack **stack_b);

// Rotate
// static t_stack	*ft_find_last(t_stack *stack);
// static void 		ft_rotate(t_stack **stack);
void				ft_ra(t_stack **a, int print);
void				ft_rb(t_stack **b, int print);
void				ft_rr(t_stack **a, t_stack **b, int print);

// Small
void				ft_sort_three(t_stack **stack);
void				ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void				ft_small(t_stack **stack_a, t_stack **stack_b, int size);

// Rev rotate
// static t_stack	*ft_find_last(t_stack *stack);
// static void 		ft_rev_rotate(t_stack **stack);
void				ft_rra(t_stack **a, int print);
void				ft_rrb(t_stack **b, int print);
void				ft_rrr(t_stack **a, t_stack **b, int print);

// Utils
int					*ft_rev_array(int *array, int len);
t_stack				*ft_find_min(t_stack *stack);
int					ft_find_position(t_stack *stack, int value);
char				*ft_strncpy(char *dst, const char *src, size_t len);
long				ft_atol(const char *str);

#endif