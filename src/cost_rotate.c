/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:34:03 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 21:34:23 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_do_rr(t_stack *stack, int cost_a, int cost_b)
{
	int	tmp;

	tmp = cost_a;
	while (cost_a > 0 && cost_b > 0)
	{
		cost_a--;
		cost_b--;
		ft_rr(stack);
	}
	return (tmp);
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

int	ft_do_ra(t_stack *stack, int cost)
{
	int	tmp;

	tmp = 0;
	while (cost)
	{
		if (cost > 0)
		{
			tmp++;
			ft_ra(stack, 1);
			cost--;
		}
		else if (cost < 0)
		{
			tmp--;
			ft_rra(stack, 1);
			cost++;
		}
	}
	return (tmp);
}
