/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:07:30 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 21:59:48 by cschnath         ###   ########.fr       */
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
Divide the list into chunks based on size (e.g., 20-50 elements per chunk for
medium datasets, smaller for large datasets) and the sorted order of values

Push Chunks to Stack B:
For each chunk, push elements from stack A to stack B.
Use rotate (ra) and reverse rotate (rra) to move the closest target
to the top of stack A

Sort and Push Back to Stack A:
Sort stack B by using rotate (rb) or reverse rotate (rrb)
to find the largest value.
Push the largest value from stack B back to stack A using pa.
Use double rotations (e.g., rr) in stack A when possible for optimization

Free memory and exit
*/

#include "push_swap.h"

static void	ft_append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->nb = n;
	node->cheapest = 0;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	ft_init_stack_a(t_stack **a, char **argv)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		if (ft_error(argv[i]))
			ft_free_errors(a);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN || ft_error_duplicate(*a, (int)n))
			ft_free_errors(a);
		ft_append_node(a, (int)n);
		i++;
	}
}

// Run checker & after the commands use Ctrl + D
void	ft_init_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	if (argc < 2)
		exit(0);
	*a = NULL;
	*b = NULL;
	ft_init_stack_a(a, argv + 1);
}

void	ft_chunky(t_stack *a, t_stack *b, int *chunks, int num_chunks)
{
	int	i;

	i = 0;
	while (i < num_chunks)
	{
		ft_push_chunk_to_b(a, b, chunks + i);
		ft_sort_stack_b(b, a);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*array;
	int		*chunks;
	int		num_chunks;

	ft_init_stacks(argc, argv, &a, &b);
	array = ft_stack_to_array(a, ft_stack_len(a));
	ft_sort_array(array, ft_stack_len(a));
	num_chunks = ft_stack_len(a) / 20;
	chunks = ft_create_chunks(a, num_chunks);
	ft_chunky(a, b, chunks, num_chunks);
	ft_push_back_to_a(a, b);
	free(array);
	free(chunks);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
