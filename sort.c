/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:34:52 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 20:51:28 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_chunk_size(int i, int arr_len, int num_chunks)
{
	int	chunk_size;
	
	chunk_size = 0;
	if (i < num_chunks - 1)
		chunk_size = arr_len / num_chunks;
	else
		chunk_size = arr_len / num_chunks + 1;
	return (chunk_size);
}

// Create a chunk
int	*ft_create_chunks(int *arr, int size, int i)
{
	int	*chunk;
	int j;
	
	j = 0;
	chunk = malloc(sizeof(int) * (size));
	if (!chunk)
		return (free(arr), NULL);
	while (j < size)
	{
		chunk[j] = arr[i + j];
		j++;
	}
	return (chunk);
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
