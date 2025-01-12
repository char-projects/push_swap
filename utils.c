/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:38:33 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 21:58:30 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *ft_rev_array(int *array, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i++;
		j--;
	}
	return (array);
}

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

// Rotate or reverse rotate a stack to bring a value to the top
void	ft_move_to_top(t_stack **stack, int value)
{
    int	position;
    int	len;

    position = ft_find_position(*stack, value);
    len = ft_stack_len(*stack);
    if (position < len / 2)
    {
        while (position-- > 0)
            ft_ra(stack, 1);
    }
    else
    {
        position = len - position;
        while (position-- > 0)
            ft_rra(stack, 1);
    }
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\f' || *str == '\v')
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
