/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:36:13 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 20:47:08 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ft_find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	ft_rra(t_stack **a, int print)
{
	ft_rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack **b, int print)
{
	ft_rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack **a, t_stack **b, int print)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
