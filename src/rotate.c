/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:13:59 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 21:34:19 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_ra(t_stack *stack, int print)
{
	int	i;
	int	tmp;
	int	count;

	count = 0;
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
		count = 1;
	}
	return (count);
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
