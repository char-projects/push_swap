/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:34:52 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 13:44:40 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
void	ft_sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = ft_find_max(*a);
	if (biggest == *a)
		ft_ra(a, false);
	else if ((*a)->next == biggest)
		ft_rra(a, false);
	if ((*a)->nb > (*a)->next->nb)
		ft_sa(a, false);
}

// Done
void	ft_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

// Done
void	ft_sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	if (len_a-- < 3 && !ft_is_sorted(*a))
		ft_pb(b, a, false);
	if (len_a-- < 3 && !ft_is_sorted(*a))
		ft_pb(b, a, false);
	while (len_a-- > 3 && !ft_is_sorted(*a))
	{
		ft_init_a(*a, *b);
		ft_push_to_b(a, b);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_b(*a, *b);
		ft_push_to_a(a, b);
	}
	ft_index(*a);
	ft_min_on_top(a);
}

// Done
void	ft_append_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = n;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

// Done
int	ft_stack_len(t_stack *stack)
{
	int		len;
	
	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
