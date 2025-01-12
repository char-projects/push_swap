/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:07:30 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 23:32:50 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Divide and conquer with chunking:
The array is split into chunks of values. Each chunk is processed by
moving its elements from stack A to stack B in the correct order, then
sorted and pushed back to stack A

Preparation:
Parse input, validate numbers, and initialize stacks A and B.
Find the sorted order of the numbers to determine their positions for chunking

Chunk Division:
Divide the list into chunks based on size and the sorted order of values
*/

#include "push_swap.h"

static void	ft_append_node(t_stack **stack, long nb)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_free_errors(stack);
	new_node->nb = nb;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
}

void	ft_init_stack_a(t_stack **a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (ft_error(argv[i]))
			ft_free_errors(a);
		nb = ft_atol(argv[i]);
		if (ft_duplicate(*a, nb))
			ft_free_errors(a);
		ft_append_node(a, nb);
		i++;
	}
}

void	ft_init_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc < 2)
		exit(0);
	*a = NULL;
	*b = NULL;
	ft_init_stack_a(a, argv + 1);
}

// Dynamically calculate the number of chunks based on stack size
int	ft_calculate_chunks(int stack_len)
{
	int	chunk_size;

	if (stack_len <= 10)
		return (1);
	else if (stack_len <= 100)
		chunk_size = 10;
	else if (stack_len <= 500)
		chunk_size = 20;
	else
		chunk_size = 30;
	return ((stack_len + chunk_size - 1) / chunk_size);
}

// Run checker & after the commands use Ctrl + D
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;
	int		len;
	int		num_chunks;

	ft_init_stacks(argc, argv, &a, &b);
	len = ft_stack_len(a);
	if (len <= 5)
		ft_small(&a, &b, len);
	else
	{
		num_chunks = ft_calculate_chunks(len);
		arr = ft_stack_to_array(a, len);
		if (!arr)
			ft_free_errors(&a);
		ft_sort_array(arr, len);
		b = ft_arr_to_chunk(a, b, arr, num_chunks, len);
		a = NULL;
		while (b)
			ft_pa(&a, &b, 1);
	}
	ft_printf("Result: ");
	ft_print_stack(a);
}
