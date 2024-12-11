/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:15:10 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 12:49:07 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Done
static void	ft_push(t_stack **dst, t_stack **src)
{
	t_stack	*push;

	if (!*src)
		return ;
	push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push->prev = NULL;
	if (!*dst)
	{
		*dst = push;
		push->next = NULL;
	}
	else
	{
		push->next = *dst;
		push->next->prev = push;
		*dst = push;
	}
}

void	ft_pa(t_stack **a, t_stack **b, bool print)
{
	ft_push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	ft_pb(t_stack **b, t_stack **a, bool print)
{
	ft_push(b, a);
	if (!print)
		ft_printf("pb\n");
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
