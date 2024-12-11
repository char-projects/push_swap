/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:38:24 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 13:39:32 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
    while (*b != cheapest->target_node && *a != cheapest)
        ft_rrr(a, b, false);
    ft_index(*a);
    ft_index(*b);
}

// Done
static void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		ft_rr(a, b, false);
	ft_index(*a);
	ft_index(*b);
}

// Done
static void	ft_push_to_a(t_stack **a, t_stack **b)
{
	ft_prep_for_push(a, (*b)->target_node, 'a');
	ft_pa(a, b, false);
}

// Done
static void	ft_push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = ft_find_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		ft_rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !(cheapest->target_node->above_median))
		ft_rev_rotate_both(a, b, cheapest);
	ft_prep_for_push(b, cheapest, 'a');
	ft_prep_for_push(a, cheapest->target_node, 'b');
	ft_pb(b, a, false);
}
