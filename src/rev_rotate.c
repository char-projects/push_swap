/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:12:04 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 06:27:31 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack *stack, int print)
{
	int	i;
	int	tmp;

	if (stack->size_a > 1)
	{
		i = stack->size_a - 1;
		tmp = stack->a[i];
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[i] = tmp;
		if (print != 0)
			ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack *stack, int print)
{
	int	i;
	int	tmp;

	if (stack->size_b > 1)
	{
		i = stack->size_b - 1;
		tmp = stack->b[i];
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[i] = tmp;
		if (print != 0)
			ft_printf("rrb\n");
	}
}

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack, 0);
	ft_rrb(stack, 0);
	ft_printf("rrr\n");
}

int	ft_do_rrr(t_stack *stack, int cost_a, int cost_b)
{
	int tmp;
	
	tmp = 0;
	while (cost_a < 0 && cost_b < 0)
	{
		tmp++;
		cost_a++;
		cost_b++;
		ft_rrr(stack);
	}
	return (tmp);
}

// if at the end the stack is like this: 5 6 1 2, do rra until it's sorted
void	ft_last_rra(t_stack *stack)
{
	int	i;

	i = 0;
	while (!ft_is_sorted(stack->a, stack->size_a) && i < stack->size_a)
	{
		ft_rra(stack, 1);
		i++;
	}
}
