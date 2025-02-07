/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:58 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 01:12:01 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stack *stack, int i)
{
	if (stack->size_b > 0)
	{
		i = stack->size_a;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			stack->target_a[i] = stack->target_a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		stack->target_a[0] = stack->target_b[0];
		i = 0;
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			stack->target_b[i] = stack->target_b[i + 1];
			i++;
		}
		stack->b[i] = 0;
		stack->target_b[i] = 0;
		stack->size_a++;
		stack->size_b--;
		ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *stack)
{
	int i;

	if (stack->size_a > 0)
	{
		i = stack->size_b + 1;
		while (--i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			stack->target_b[i] = stack->target_b[i - 1];
		}
		stack->b[0] = stack->a[0];
		stack->target_b[0] = stack->target_a[0];
		i = -1;
		while (++i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			stack->target_a[i] = stack->target_a[i + 1];
		}
		stack->a[i] = 0;
		stack->target_a[i] = 0;
		stack->size_b++;
		stack->size_a--;
		ft_printf("pb\n");
	}
}

// Iterates over target array and pushes the elements to b if they are smaller than the pivot
// Implement the cost function here to determine which elements to push first
// Then we push everything else to b except for the biggest three elements
// If b happens to be sorted in descending order, we push everything back to a
void  ft_initial_push(t_stack *stack)
{
	int i;
	int old_size;

	i = 0;
	old_size = stack->size_a;
	ft_printf("pivot: %d\n", stack->pivot);
	while ((i < old_size) && stack->size_a >= 3)
	{
		if (stack->a[0] < stack->pivot)
			ft_pb(stack);
		else
			ft_ra(stack, 1);
		i++;
	}
	while (stack->size_a > 3)
		ft_pb(stack);
	ft_sort_three(stack);
	if (ft_rev_sort_b(stack, stack->size_b) == 0)
	{
		while (stack->size_b > 0)
			ft_pa(stack, 0);
	}
}
