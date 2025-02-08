/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:58 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 19:34:44 by cschnath         ###   ########.fr       */
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
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = 0;
		stack->size_a++;
		stack->size_b--;
		ft_printf("pa\n");
	}
}

void	ft_pb(t_stack *stack)
{
	int	i;

	if (stack->size_a > 0)
	{
		i = stack->size_b + 1;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		while (++i < stack->size_a - 1)
			stack->a[i] = stack->a[i + 1];
		stack->a[i] = 0;
		stack->size_b++;
		stack->size_a--;
		ft_printf("pb\n");
	}
}

void	ft_initial_push(t_stack *stack)
{
	int	i;

	i = 0;
	stack->pivot = stack->sorted[stack->size_a / 2];
	while ((i < stack->og_size) && stack->size_a >= 3 && !ft_is_sorted(stack->a,
			stack->size_a))
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
