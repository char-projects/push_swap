/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:13:59 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 16:23:04 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack *stack, int print)
{
	int	i;
	int	tmp;

	if (stack->size_a > 1)
	{
		i = 0;
		tmp = stack->a[0];
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[i] = tmp;
		if (print != 0)
			ft_printf("ra\n");
	}
}

void	ft_rb(t_stack *stack, int print)
{
	int	i;
	int	tmp;

	if (stack->size_b > 1)
	{
		i = 0;
		tmp = stack->b[0];
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[i] = tmp;
		if (print != 0)
			ft_printf("rb\n");
	}
}

void	ft_rr(t_stack *stack)
{
	ft_ra(stack, 0);
	ft_rb(stack, 0);
	ft_printf("rr\n");
}

void	ft_do_rr(t_stack *stack, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		cost_a--;
		cost_b--;
		ft_rr(stack);
	}
}

void	ft_do_rb(t_stack *stack, int cost)
{
	while (cost)
	{
		if (cost > 0)
		{
			ft_rb(stack, 1);
			cost--;
		}
		else if (cost < 0)
		{
			ft_rrb(stack, 1);
			cost++;
		}
	}
}
