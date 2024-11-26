/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 23:07:30 by cschnath          #+#    #+#             */
/*   Updated: 2024/11/26 23:07:30 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Declare pointers to two data structures / linked lists, one for stack a and one for stack b
    // Set both pointers to NULL
// Handle input count errors. Argc must be 2 or more, and argv[1] must not be empty
    // If input errors, return error
// Handle both cases of input, whether a variable number of command line arguments, or as a string
    // If the input of numbers is a string, call ft_split to split the substrings


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc < 2 || !argv[1])
        return (0);
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        if (!argv)
            return (0);
    }
    return (0);
}
