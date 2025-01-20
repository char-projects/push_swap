/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:07:30 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/20 20:50:31 by cschnath         ###   ########.fr       */
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

void	ft_append_node(t_stack **stack, long nb)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		ft_free_stack(stack);
		exit(1);
	}
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

void	ft_validate(int argc, char **argv, t_stack **a, int i)
{
	long	nb;

	while (i < argc)
	{
		if (ft_error(argv[i]))
			ft_free_errors(a);
		nb = ft_atol(argv[i]);
		ft_append_node(a, nb);
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

void	ft_init_stacks(int argc, char **argv, t_stack **a, t_stack **b, int i)
{
	int		new_argc;
	char	**split_argv;

	*a = NULL;
	*b = NULL;
	if (argc < 2 || (argc == 2 && !(*argv)[1]))
	{
		ft_printf("Error: Number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		split_argv = ft_new_split(argv[1], ' ');
		new_argc = ft_wordcount(argv[1], ' ');
		if (ft_duplicate(split_argv, new_argc))
			exit(EXIT_FAILURE);
		ft_validate(new_argc, split_argv, a, 0);
	}
	else
	{
		if (ft_duplicate(argv, argc))
			exit(EXIT_FAILURE);
		ft_validate(argc, argv, a, 1);
	}
	(void)i;
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

	ft_init_stacks(argc, argv, &a, &b, 0);
	len = ft_stack_len(a);
	if (len <= 5 && !(ft_is_sorted(a)))
		ft_small(&a, &b, len);
	else if ((ft_is_sorted(a)))
		ft_free_errors(&a);
	else
	{
		num_chunks = ft_calculate_chunks(len);
		arr = ft_stack_to_array(a, len);
		if (!arr)
			ft_free_errors(&a);
		ft_sort_array(arr, len);
		b = ft_arr_to_chunk(a, b, arr, num_chunks, len);
		while (b)
			ft_pa(&a, &b, 1);
	}
	ft_printf("Result: ");
	ft_print_stack(a);
}
