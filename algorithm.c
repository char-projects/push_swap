/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:31:23 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/20 20:45:05 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Remove for eval
void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d ", stack->nb);
		stack = stack->next;
	}
	ft_printf("\n");
}

int	**ft_rev_chunks(int **chunks, int num)
{
	int	i;
	int	j;
	int	*temp;

	i = 0;
	j = num - 1;
	while (i < j)
	{
		temp = chunks[i];
		chunks[i] = chunks[j];
		chunks[j] = temp;
		i++;
		j--;
	}
	return (chunks);
}

t_stack	*ft_arr_to_chunk(t_stack *a, t_stack *b, int *arr, int num, int len)
{
	int	**chunks;
	int	chunk_size;
	int	arr_i;
	int	i;

	arr_i = 0;
	i = 0;
	chunks = malloc(sizeof(int *) * num);
	if (!chunks)
		return (NULL);
	while (i < num)
	{
		chunk_size = ft_chunk_size(i, len - 4, num);
		chunks[i] = ft_create_chunks(arr, chunk_size, arr_i);
		chunks[i] = ft_rev_array(chunks[i], chunk_size);
		ft_push_chunk_to_b(&a, &b, chunks[i], chunk_size);
		arr_i += chunk_size;
		i++;
	}
	ft_printf("Stack A: ");
	ft_print_stack(a);
	ft_printf("Stack B: ");
	ft_print_stack(b);
	free(chunks);
	free(arr);
	return (b);
}

int	*ft_stack_to_array(t_stack *stack, int len)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (len + 1));
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

// Push a chunk from stack A to stack B
void	ft_push_chunk_to_b(t_stack **a, t_stack **b, int *chunk, int size)
{
	int	i;
	int	pos;
	int	len_a;

	i = size - 1;
	while (i >= 0 && *a)
	{
		pos = ft_find_position(*a, chunk[i]);
		len_a = ft_stack_len(*a);
		if (pos < len_a / 2)
			while (pos-- > 0)
				ft_ra(a, 1);
		else
			while (pos++ < len_a)
				ft_rra(a, 1);
		if (*a)
			ft_pb(b, a, 1);
		i--;
	}
}
