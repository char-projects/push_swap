/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:07:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/10 22:52:33 by cschnath         ###   ########.fr       */
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

// Done
int ft_error_duplicate(t_stack *a, int nb)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nb == nb)
            return (1);
        a = a->next;
    }
    return (0);
}

// Done
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc < 2 || ( argc == 2 && !argv[1][0]))
        exit(EXIT_FAILURE);
    else if (argc == 2)
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
    ft_free_stack(&a);
}
