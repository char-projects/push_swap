/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:12:04 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 01:12:06 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack *stack, int print)
{
	int	i;
	int	tmp;
	int tmp_target;

	if (stack->size_a > 1)
	{
		i = stack->size_a - 1;
		tmp = stack->a[i];
		tmp_target = stack->target_a[i];
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			stack->target_a[i] = stack->target_a[i - 1];
			i--;
		}
		stack->a[i] = tmp;
		stack->target_a[i] = tmp_target;
		if (print != 0)
			ft_printf("rra\n");
	}
}

void	ft_rrb(t_stack *stack, int print)
{
	int	i;
	int	tmp;
	int tmp_target;

	if (stack->size_b > 1)
	{
		i = stack->size_b - 1;
		tmp = stack->b[i];
		tmp_target = stack->target_b[i];
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			stack->target_b[i] = stack->target_b[i - 1];
			i--;
		}
		stack->b[i] = tmp;
		stack->target_b[i] = tmp_target;
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