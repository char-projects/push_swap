/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:45:10 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/20 01:46:06 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
static void	ft_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		current_b = b;
		best_match = LONG_MIN;
		while (current_b)
		{
			if (current_b->nb < a->nb && current_b->nb > best_match)
			{
				best_match = current_b->nb;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = ft_find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

// Done
static void	ft_cost_analysis(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_len(a);
	len_b = ft_stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (!(a->target_node->above_median))
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

// Done
void	ft_init_nodes_a(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_a(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(a);
}

void	ft_init_nodes(t_stack *a, t_stack *b)
{
	ft_index(a);
	ft_index(b);
	ft_target_a(a, b);
	ft_cost_analysis(a, b);
	ft_set_cheapest(a);
}
