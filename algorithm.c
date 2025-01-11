/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:31:23 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 23:23:35 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_stack_to_array(t_stack *stack, int stack_len)
{
	int	*array;
	int len;
	int	i;

	len = stack_len;
	array = malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = stack->nb;
		stack = stack->next;
		i++;
	}
	ft_printf("Reached ft_stack_to_array\n");
	return (array);
}

// Push a chunk from stack A to stack B
void	ft_push_chunk_to_b(t_stack *a, t_stack *b, int *chunk)
{
	int	i;
	int	pos;
	int	len;

	i = 0;
	len = ft_stack_len(a);
	while (i < len)
	{
		pos = ft_find_position(a, chunk[i]);
		if (pos < len / 2)
			while (a->nb != chunk[i])
				ft_ra(&a, 1);
		else
			while (a->nb != chunk[i])
				ft_rra(&a, 1);
		ft_pb(&b, &a, 1);
		i++;
	}
}

// Sort elements in stack B
void	ft_sort_stack_b(t_stack *b, t_stack *a)
{
	int	len;
	int	*array;

	len = ft_stack_len(b);
	array = ft_stack_to_array(b, len);
	ft_sort_array(array, len);
	while (len > 0)
	{
		ft_move_to_top(b, array[len - 1]);
		ft_pa(&a, &b, 1);
		len--;
	}
	free(array);
}

// Push sorted elements back to stack A
void	ft_push_back_to_a(t_stack *a, t_stack *b)
{
	int	len;
    int position;
    t_stack *min_node;

	len = ft_stack_len(b);
	while (len > 0)
	{
		min_node = ft_find_min(b);
        position = ft_find_position(b, min_node->nb);
        ft_move_to_top(b, position);
		ft_pa(&a, &b, 1);
		len--;
	}
}
