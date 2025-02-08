/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:28 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 21:37:46 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Find the cheapest way to move an element from stack B to stack A
// Then sort the element in stack A
int	ft_cost_a(t_stack *stack, int i)
{
	int	pos;
	int	cost;

	pos = ft_find_position(stack, stack->b[i]);
	cost = pos;
	if (pos > stack->size_a / 2)
		cost = (stack->size_a - pos) * (-1);
	return (cost);
}

int	ft_cost_b(t_stack *stack, int i)
{
	int	cost;

	cost = i;
	if (i > stack->size_b / 2)
		cost = (stack->size_b - i) * (-1);
	return (cost);
}

void	ft_optimize_rotation(t_stack *stack, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		ft_rr(stack);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		ft_rrr(stack);
		cost_a++;
		cost_b++;
	}
	ft_do_ra(stack, cost_a);
	ft_do_rb(stack, cost_b);
}

int	ft_cheapest(t_stack *stack, int i)
{
	int	cheapest_index;
	int	min_cost;
	int	total_cost;
	int	cost_a;
	int	cost_b;

	min_cost = 2147483647;
	cheapest_index = 0;
	while (i < stack->size_b)
	{
		cost_a = ft_cost_a(stack, i);
		cost_b = ft_cost_b(stack, i);
		total_cost = ft_abs(cost_a) + ft_abs(cost_b);
		if (cost_a > 0 && cost_b > 0)
			total_cost -= ft_min(cost_a, cost_b);
		if (cost_a < 0 && cost_b < 0)
			total_cost += ft_max(cost_a, cost_b);
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
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
	ft_optimize_rotation(stack, cost_a, cost_b);
	ft_pa(stack, 0);
	return (cost_a);
}
