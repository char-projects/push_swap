/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:28 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 16:18:43 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Find the cheapest way to move an element from stack B to stack A
// Then sort the element in stack A
int	ft_cost_a(t_stack *stack, int i)
{
	int	cost_a;
	int	half_stack;

	half_stack = stack->size_a / 2 + 1;
	cost_a = stack->target[i];
	if (stack->target[i] > half_stack)
		cost_a = (stack->size_a + 2 - stack->target[i]) * (-1);
	return (cost_a);
}

int	ft_cost_b(t_stack *stack, int i)
{
	int	cost_b;

	if (i <= stack->size_b / 2)
		cost_b = i;
	else
		cost_b = ((stack->size_b - i) + 1) * (-1);
	return (cost_b);
}

int	ft_cheapest(t_stack *stack)
{
	int	min_cost;
	int	cheapest_index;
	int	i;
	int	cost;

	min_cost = 2147483647;
	cheapest_index = 0;
	i = 0;
	ft_set_target(stack);
	ft_printf("target: ");
	ft_print_arr(stack->target, stack->size_b);
	while (i < stack->size_b)
	{
		cost = ft_abs(ft_cost_a(stack, i)) + ft_abs(ft_cost_b(stack, i));
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest_index = i;
		}
		i++;
	}
	return (cheapest_index);
}

int	ft_payday(t_stack *stack, int i)
{
	int	cost_a;
	int	cost_b;

	cost_a = ft_cost_a(stack, i);
	cost_b = ft_cost_b(stack, i);
	ft_printf("cost_a: %d\n", cost_a);
	ft_printf("cost_b: %d\n", cost_b);
	ft_do_rrr(stack, cost_a, cost_b);
	ft_do_rr(stack, cost_a, cost_b);
	if (cost_a < 0)
	{
		ft_pa(stack, 0);
		ft_ra(stack, 1);
		ft_do_rb(stack, cost_b);
	}
	else if (cost_a > 0)
	{
		ft_ra(stack, 1);
		ft_pa(stack, 0);
		ft_do_rb(stack, cost_b);
	}
	else
		ft_pa(stack, 0);
	return (cost_a);
}
