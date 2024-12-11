/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:45:10 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 12:46:41 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
void	ft_init_nodes_a(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_a(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(a);
}

// Done
void	ft_init_nodes_b(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_b(a, b);
}

// Done
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

void	ft_init_nodes(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_a(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(a);
}