/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:05:20 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/10 22:52:22 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack *current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nb = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

// Done
void	ft_append_node(t_stack **stack, int n)
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
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
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

// Done
int	ft_stack_len(t_stack *stack)
{
	int		len;
	
	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
