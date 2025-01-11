/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 01:34:52 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 23:41:58 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_chunks(int *chunks, int *arr, int size, int num)
{
    int	i;
    int	j;

    i = -1;
    j = 0;
    while (++i < num)
    {
        chunks[i] = arr[j];
        j += size;
    }
    chunks[i] = 0;
}

// THIS FUNCTION IS THE PROBLEM !!!!!!!!!
int	*ft_create_chunks(t_stack *stack, int num_chunks)
{
	int	*chunks;
	int	*array;
	int	chunk_size;

	ft_printf("Reached ft_create_chunks\n"); // This gets printed
	if (num_chunks == 0)
	{
		ft_printf("Num_chunks was NULL\n"); // This is a problem, why is it always NULL?
		return (NULL);
	}
	array = ft_stack_to_array(stack, ft_stack_len(stack));
	if (!array)
		return (NULL);
	ft_sort_array(array, ft_stack_len(stack));
	chunks = malloc(sizeof(int) * (num_chunks + 1));
	if (!chunks)
		return (free(array), NULL);
	ft_printf("Or not???\n");
	chunk_size = ft_stack_len(stack) / num_chunks;
	ft_fill_chunks(chunks, array, chunk_size, num_chunks);
    ft_printf("Reached end of ft_create_chunks\n");
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
	int len;
	
	len = size;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
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
	ft_printf("Reached ft_sort_array\n");
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
    ft_printf("Reached ft_stack_len\n");
	return (len);
}
