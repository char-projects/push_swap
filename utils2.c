/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:11:16 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/10 13:28:08 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		ft_rr(a, b, false);
	ft_index(*a);
	ft_index(*b);
}

void	ft_rr(t_stack **a, t_stack **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!print)
		ft_printf("rr\n");
}

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
