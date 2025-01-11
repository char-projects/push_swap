/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:28:35 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/11 22:19:24 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_find_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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

void	ft_ra(t_stack **a, int print)
{
	ft_rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	ft_rb(t_stack **b, int print)
{
	ft_rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	ft_rr(t_stack **a, t_stack **b, int print)
{
	ft_rotate(a);
	ft_rotate(b);
	if (!print)
		ft_printf("rr\n");
}
