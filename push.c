/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschnath <cschnath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:15:10 by cschnath          #+#    #+#             */
/*   Updated: 2025/01/20 20:54:13 by cschnath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_pa(t_stack **a, t_stack **b, int print)
{
	ft_push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	ft_pb(t_stack **b, t_stack **a, int print)
{
	ft_push(b, a);
	if (print)
		ft_printf("pb\n");
}

void	ft_push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*smallest;
	int		position;
	int		len;

	len = ft_stack_len(*stack_a);
	smallest = ft_find_min(*stack_a);
	position = ft_find_position(*stack_a, smallest->nb);
	if (position <= len / 2)
	{
		while (position-- > 0)
			ft_ra(stack_a, 1);
	}
	else
	{
		while (position++ < len)
			ft_rra(stack_a, 1);
	}
	ft_pb(stack_b, stack_a, 1);
}
