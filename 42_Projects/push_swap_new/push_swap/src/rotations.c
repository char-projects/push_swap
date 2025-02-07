/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:22 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 01:24:13 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
*	Reverse rotates both stack A and B until one of them is in position.
*	The given cost is negative since both positions are in the bottom half
*	of their respective stacks. The cost is increased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
void	ft_do_rrr(t_stack *stack, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		(cost_a)++;
		(cost_b)++;
		ft_rrr(stack);
	}
}

/*
*	Rotates both stack A and B until one of them is in position.
*	The given cost is positive since both positions are in the top half
*	of their respective stacks. The cost is decreased as the stacks are
*	rotated, when one reaches 0, the stack has been rotated as far as possible
*	and the top position is correct.
*/
void	ft_do_rr(t_stack *stack, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		(cost_a)--;
		(cost_b)--;
		ft_rr(stack);
	}
}

/*
*	Rotates stack A until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
void	ft_do_ra(t_stack *stack, int cost)
{
	while (cost)
	{
		if (cost > 0)
		{
			ft_ra(stack, 1);
			(cost)--;
		}
		else if (cost < 0)
		{
			ft_rra(stack, 1);
			(cost)++;
		}
	}
}

/*
*	Rotates stack B until it is in position. If the cost is negative,
*	the stack will be reverse rotated, if it is positive, it will be 
*	rotated.
*/
void	ft_do_rb(t_stack *stack, int cost)
{
	while (cost)
	{
		if (cost > 0)
		{
			ft_rb(stack, 1);
			(cost)--;
		}
		else if (cost < 0)
		{
			ft_rrb(stack, 1);
			(cost)++;
		}
	}
}
