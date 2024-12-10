/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:28:35 by cschnath          #+#    #+#             */
/*   Updated: 2024/12/11 00:05:42 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// MAKE FT_FIND_LAST
static void	ft_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_find_last(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ft_ra(t_stack **a, bool print)
{
	ft_rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	ft_rb(t_stack **b, bool print)
{
	ft_rotate(b);
	if (!print)
		ft_printf("rb\n");
}

// Done
void	ft_rr(t_stack **a, t_stack **b, bool print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!print)
		ft_printf("rr\n");
}

// Done
static void	ft_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		ft_rr(a, b, false);
	ft_index(*a);
	ft_index(*b);
}