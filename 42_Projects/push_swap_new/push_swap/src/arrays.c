/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:11:39 by cschnath          #+#    #+#             */
/*   Updated: 2025/02/07 01:11:41 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_arr(t_stack *arr, int size)
{
	int i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		arr->sorted[i] = arr->a[i];
        i++;
	}
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr->sorted[i] > arr->sorted[j])
			{
				temp = arr->sorted[i];
				arr->sorted[i] = arr->sorted[j];
				arr->sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
	arr->pivot = arr->sorted[size / 2];
}

// map each value in a to its target index in sorted
void ft_set_target_a(t_stack *stack)
{
	int i;
	int j;
	int *tmp;

	i = 0;
	tmp = ft_calloc(stack->size_a, sizeof(int));
	tmp = ft_memcpy(tmp, stack->sorted, stack->size_a * sizeof(int));
	while (i < stack->size_a)
	{
		j = 0;
		while (j < stack->size_a)
		{
			if (stack->a[i] == tmp[j])
			{
				stack->target_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

// map each value in a to its target index in sorted
void ft_set_target_b(t_stack *stack)
{
	int i;
	int j;
	int *tmp;

	i = 0;
	tmp = ft_calloc(stack->size_b, sizeof(int));
	tmp = ft_memcpy(tmp, stack->sorted, stack->size_b * sizeof(int));
	while (i < stack->size_b)
	{
		j = 0;
		while (j < stack->size_b)
		{
			if (stack->a[i] == tmp[j])
			{
				stack->target_b[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}
