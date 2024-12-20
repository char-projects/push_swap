/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:07:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/20 04:19:01 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Declare pointers to two data structures / linked lists, one for stack a and one for stack b
    // Set both pointers to NULL
// Handle input count errors. Argc must be 2 or more, and argv[1] must not be empty
    // If input errors, return error
// Handle both cases of input, whether a variable number of command line arguments, or as a string
    // If the input of numbers is a string, call ft_split to split the substrings
// Initialize stack a by appending each input number as a node to stack a
    // Handle integer overflow, duplicates and syntax errors (input must only contain numbers or + -)
        // If errors found, free stack a and return error
    // Check for each input, if it is a long int
        // If the input is a string, convert it to a long int
    // Append the nodes to stack a
// Check is stack a is sorted
    // If not sorted, implement sorting algorithm
        // Check for two numbers
            // If two numbers, swap them
        // Check for three numbers
            // If three numbers, implement simple sort three algorithm
        // Check if the stack has more than three numbers
            // If more than three numbers, implement Turk algorithm
// Utils: Error handling, operations(ra, rb, rr, rra, rrb, rrr, sa, sb, ss, pa, pb), stack length, last node, min max 

#include "push_swap.h"

// Fixed tiny missing thing
static void	ft_append_node(t_stack **stack, int n)
{
	t_stack *node;
	t_stack *last_node;

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

// This one works for sure
void ft_init_a(t_stack **a, char **argv)
{
    int i;
    long n;

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

// Fixed this one
static void	ft_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb > b->nb && current_a->nb < best_match)
			{
				best_match = current_a->nb;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = ft_find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

// Done
void	ft_init_nodes_b(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_b(a, b);
}

void print_stack(t_stack *stack) {
    while (stack) {
        ft_printf("%d ", stack->nb);
        stack = stack->next;
    }
    ft_printf("\n");
}

// This one works for sure
// Run checker & after the commands use Ctrl + D
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
    {
        ft_printf("Error\n");
        return (1);
    }
    if (argc == 2)
        argv = ft_new_split(argv[1], ' ');
    ft_init_a(&a, argv + 1);
    if (!ft_is_sorted(a))
    {
        if (ft_stack_len(a) == 2)
            ft_sa(&a, false);
        else if (ft_stack_len(a) == 3)
            ft_sort_three(&a);
        else
            ft_sort_stacks(&a, &b);
    }
    print_stack(a);
    ft_free_stack(&a);
    return (0);
}
