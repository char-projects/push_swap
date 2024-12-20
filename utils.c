/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:38:33 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/20 04:16:45 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This one works for sure
long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

// This one works for sure
t_stack	*ft_find_min(t_stack *stack)
{
	long min;
	t_stack *min_node;

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

// This one works for sure
t_stack *ft_find_max(t_stack *stack)
{
	long max;
	t_stack *max_node;

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

// This one works for sure
t_stack *ft_find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
