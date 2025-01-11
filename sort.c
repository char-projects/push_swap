/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:34:52 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 20:46:48 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_stack_to_array(t_stack *stack, int stack_len)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * stack_len);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = stack->nb;
		stack = stack->next;
		i++;
	}
	return (array);
}

int	*ft_create_chunks(t_stack *stack, int num_chunks)
{
	int	*chunks;
	int	*array;
	int	chunk_size;
	int	i;
	int	j;

	array = ft_stack_to_array(stack, ft_stack_len(stack));
	if (!array)
		return (NULL);
	ft_sort_array(array, ft_stack_len(stack));
	chunks = malloc(sizeof(int) * (num_chunks + 1));
	if (!chunks)
		return (free(array), NULL);
	chunk_size = ft_stack_len(stack) / num_chunks;
	i = -1;
	j = 0;
	while (++i < num_chunks)
	{
		chunks[i] = array[j];
		j += chunk_size;
	}
	chunks[i] = 0;
	free(array);
	return (chunks);
}

// Check if a value belongs to a chunk
int	ft_is_in_chunk(int value, int *chunk)
{
	int	i;

	i = 0;
	while (chunk[i])
	{
		if (value == chunk[i])
			return (0);
		i++;
	}
	return (1);
}

// Sort an array for chunk creation
void	ft_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_stack_len(t_stack *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}
