/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:07:30 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/12 00:00:04 by cschnath         ###   ########.fr       */
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

static void ft_append_node(t_stack **stack, long nb)
{
    t_stack *new_node;
    t_stack *last;

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

void ft_init_stack_a(t_stack **a, char **argv)
{
    int	    i;
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

// FT_CREATE_CHUNKS IS THE PROBLEM RN, FIX IT!!
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
    ft_printf("Reached until create_chunks\n");
	chunks = ft_create_chunks(a, num_chunks); // Num_chunks is 0 for stacks with < 20 elements
    ft_printf("Reached after create_chunks\n");
	ft_chunky(a, b, chunks, num_chunks);
	ft_push_back_to_a(a, b);
	free(array);
	free(chunks);
	ft_free_stack(&a);
	ft_free_stack(&b);
}
