/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:13:59 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 01:14:00 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack *stack, int print)
{
	int	i;
	int	tmp;
	int	tmp_target;

	if (stack->size_a > 1)
	{
		i = 0;
		tmp = stack->a[0];
		tmp_target = stack->target_a[0];
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			stack->target_a[i] = stack->target_a[i + 1];
			i++;
		}
		stack->a[i] = tmp;
		stack->target_a[i] = tmp_target;
		if (print != 0)
			ft_printf("ra\n");
	}
}

void ft_rb(t_stack *stack, int print)
{
	int	i;
	int	tmp;
	int	tmp_target;

	if (stack->size_b > 1)
	{
		i = 0;
		tmp = stack->b[0];
		tmp_target = stack->target_b[0];
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			stack->target_b[i] = stack->target_b[i + 1];
			i++;
		}
		stack->b[i] = tmp;
		stack->target_b[i] = tmp_target;
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