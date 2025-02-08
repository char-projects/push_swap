/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:09:01 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/08 21:28:54 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_position(t_stack *stack, int num)
{
	int	i;
	int	min_pos;
	int	max_pos;

	i = 0;
	min_pos = ft_find_min_pos(stack);
	max_pos = ft_find_max_pos(stack);
	if (num < stack->a[min_pos])
		return (min_pos);
	if (num > stack->a[max_pos])
		return ((max_pos + 1) % stack->size_a);
	while (i < stack->size_a - 1)
	{
		if (num > stack->a[i] && num < stack->a[i + 1])
			return (i + 1);
		i++;
	}
	return (0);
}

int	ft_find_min_pos(t_stack *stack)
{
	int	i;
	int	min;
	int	min_pos;

	if (!stack || stack->size_a == 0)
		return (-1);
	i = 0;
	min = stack->a[0];
	min_pos = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] < min)
		{
			min = stack->a[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

int	ft_find_max_pos(t_stack *stack)
{
	int	i;
	int	max;
	int	max_pos;

	if (!stack || stack->size_a == 0)
		return (-1);
	i = 0;
	max = stack->a[0];
	max_pos = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] > max)
		{
			max = stack->a[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
