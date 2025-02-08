/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:39:16 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 08:55:47 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	*sorted;
	int	*target;
	int	og_size;
	int	size_a;
	int	size_b;
	int	pivot;
	int	argc;
}		t_stack;

// checks
int		ft_rev_sort_b(t_stack *stack, int size);
int		ft_is_sorted(int *stack, int size);
int		ft_wordcount(char const *s, char c);
char	**ft_new_split(char const *s, char c);
// static char	*ft_nextword(char const **s, char c);

// cost
int		ft_cost_a(t_stack *stack, int i);
int		ft_cost_b(t_stack *stack, int i);
int		ft_cheapest(t_stack *stack);
int		ft_payday(t_stack *stack, int i);

// errors
void	ft_print_arr(int *arr, int size); // COMMENT OUT FOR EVAL
int		ft_error(char *argv);
int		ft_duplicate(char **argv, int size);
void	ft_free_errors(t_stack *stack);

// main
void	ft_validate(char **argv, t_stack *stack);
void	ft_split_stacks(char **argv, t_stack *stack);
void	ft_init_stacks(char **argv, t_stack *stack);
t_stack	*ft_init(int argc, char **argv);

// push
void	ft_pa(t_stack *stack, int i);
void	ft_pb(t_stack *stack);
void	ft_initial_push(t_stack *stack);

// rev_rotate
void	ft_rra(t_stack *stack, int print);
void	ft_rrb(t_stack *stack, int print);
void	ft_rrr(t_stack *stack);
int		ft_do_rrr(t_stack *stack, int cost_a, int cost_b);
void	ft_last_rra(t_stack *stack);

// rotate
int	ft_ra(t_stack *stack, int print);
void	ft_rb(t_stack *stack, int print);
void	ft_rr(t_stack *stack);
int		ft_do_rr(t_stack *stack, int cost_a, int cost_b);
void	ft_do_rb(t_stack *stack, int cost);
int		ft_do_ra(t_stack *stack, int cost);

// small
void	ft_rev_sort_three(t_stack *stack);
void	ft_sort_three(t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_small(t_stack *stack, int size);

// utils
void	ft_sort_arr(t_stack *arr, int size, int i);
void	ft_set_target(t_stack *stack);
int		ft_abs(int n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
long	ft_atol(const char *str);

#endif
