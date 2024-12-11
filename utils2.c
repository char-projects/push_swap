/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:11:16 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 12:54:30 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
void	ft_set_cheapest(t_stack *stack)
{
	long	cheapest;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

// Done
static void	ft_min_on_top(t_stack **a)
{
	while ((*a)->nb != ft_find_min(*a)->nb)
	{
		if (ft_find_min(*a)->above_median)
			ft_ra(a, false);
		else
			ft_rra(a, false);
	}
}

// Done
void	ft_prep_for_push(t_stack **stack, t_stack *top_node, char c)
{
	while (*stack != top_node)
	{
		if (c == 'a')
		{
			if (top_node->above_median)
				ft_ra(stack, false);
			else
				ft_rra(stack, false);
		}
		else if (c == 'b')
		{
			if (top_node->above_median)
				ft_rb(stack, false);
			else
				ft_rrb(stack, false);
		}
	}
}

// Done
static void	ft_cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_b - (a->index);
		if (!(a->target_node->above_median))
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
