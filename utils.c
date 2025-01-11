/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:38:33 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 21:48:02 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min(t_stack *stack)
{
	long	min;
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack	*ft_find_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

// Find the position of a value in the stack
int	ft_find_position(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->nb == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

// Find the optimal position for a value
int	ft_get_target_position(t_stack *stack, int value)
{
	int	i;
	int	pos;
	int	min;
	int	max;

	i = 0;
	pos = 0;
	min = ft_find_min(stack)->nb;
	max = ft_find_max(stack)->nb;
	if (value < min || value > max)
		return (0);
	while (stack)
	{
		if (value > stack->nb && value < stack->next->nb)
			return (i + 1);
		stack = stack->next;
		i++;
	}
	return (pos);
}

// Rotate or reverse rotate a stack to bring a value to the top
void	ft_move_to_top(t_stack *stack, int position)
{
	int	len;

	len = ft_stack_len(stack);
	if (position < len / 2)
	{
		while (position--)
			ft_ra(&stack, 1);
	}
	else
	{
		position = len - position;
		while (position--)
			ft_rra(&stack, 1);
	}
}
